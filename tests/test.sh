# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 14:51:31 by anolivei          #+#    #+#              #
#    Updated: 2022/02/27 16:34:31 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

GREEN="\033[32m"
YELLOW="\033[0;33m"
RED="\033[0;31m"
BLUE="\033[0;34m"
MUTED="\033[1;30m"
RESET="\033[0m"
BOLD="\033[1m"

if [ -f ../api/api.log ]; then
    rm ../api/api.log
fi

mkdir diffs

check_log()
{
    cat $2 | cut -c 23-  > sample
    cat $3 | cut -c 23-  > log
    diff sample log > diff
    x=$(wc -c < diff)
    if [[ "$x" == *"0"* ]]; then
        echo -e ${GREEN}"[OK] "$1${RESET}
    else
        echo -e ${RED}"[KO] "$1${RESET}
    fi
}

check_api()
{
    diff $2 $3 > diff
    x=$(wc -c < diff)
    if [[ "$x" == *"0"* ]]; then
        echo -e ${GREEN}"[OK] "$1${RESET}
    else
        echo -e ${RED}"[KO] "$1${RESET}
    fi
}

curl --silent --output diffs/teste1.log -X POST -H "Content-Type: application/json" -d \
    '{"id":"1","name":"movie1","genre":"Sci-fi","year":"2001"}' "localhost:8080/"; 
check_log "POST log" logs/log_post.log ../api/api.log
check_api "POST api" logs/post.log diffs/teste1.log

curl --silent --output diffs/teste2.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/1"
check_log "GET log" logs/log_get.log ../api/api.log
check_api "GET api" logs/json_test1.log diffs/teste2.log

curl --silent --output diffs/teste3.log -X POST -H "Content-Type: application/json" -d \
    '{"id":"2","name":"movie2","genre":"Sci-fi","year":"2002"}' "localhost:8080/";
curl --silent --output diffs/teste3.log -X POST -H "Content-Type: application/json" -d \
    '{"id":"3","name":"movie3","genre":"Sci-fi","year":"2003"}' "localhost:8080/"; 
curl --silent --output diffs/teste3.log -X POST -H "Content-Type: application/json" -d \
    '{"id":"4","name":"movie4","genre":"Sci-fi","year":"2004"}' "localhost:8080/"; 
curl --silent --output diffs/teste3.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/"
check_log "POST 3 times log" logs/log_post3.log ../api/api.log
check_api "GET after post 3 times api" logs/json_test2.log diffs/teste3.log

curl --silent --output diffs/teste4.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/1" 
check_api "GET id 1 api" logs/json_test3.log diffs/teste4.log

curl --silent --output diffs/teste5.log -X DELETE -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/1" 
check_api "DELETE id 1 api" logs/delete.log diffs/teste5.log

curl --silent --output diffs/teste6.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/" 
check_api "GET after delete id 1 api" logs/json_test4.log diffs/teste6.log

curl --silent --output diffs/teste7.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/1" 
check_api "Not found GET id 1 api" logs/not_found.log diffs/teste7.log

curl --silent --output diffs/teste8.log -X PUT -H "Content-Type: application/json" -d \
    '{"id":"2","name":"movie2_put","genre":"Sci-fi","year":"2002"}' "localhost:8080/2";
check_api "PUT id 2 api" logs/put.log diffs/teste8.log

curl --silent --output diffs/teste9.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/" 
check_api "GET after put api" logs/json_test6.log diffs/teste9.log

# Remove test files
rm -rf diffs
rm diff
rm log
rm sample