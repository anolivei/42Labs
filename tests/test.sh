
#!/bin/bash

rm ../api/api.log

mkdir diffs

echo "Testing the log file..."

curl -X POST -H "Content-Type: application/json" -d \
    '{"id":"1","name":"lalala","genre":"tiro","year":"2005"}' "localhost:8080/"; 
cat logs/POST.log | cut -c 23-  > sample
cat ../api/api.log | cut -c 23-  > log
diff sample log > diff
x=$(wc -c < diff)
if [[ "$x" == *"0"* ]]; then
    echo "POST Test - OK"
else
    echo "POST Test - Fail"
fi

curl --silent --output diffs/teste1.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/1"
cat logs/POST_GET.log | cut -c 23-  > sample
cat ../api/api.log | cut -c 23-  > log
diff sample log > diffs/diff
x=$(wc -c < diffs/diff)
if [[ "$x" == *"0"* ]]; then
    echo "POST GET - OK"
else
    echo "POST GET - Fail"
fi

echo "Testing json objects content..."

diff diffs/teste1.log logs/get1.log > diffs/diff1
x=$(wc -c < diffs/diff1)
if [[ "$x" == "0" ]]; then
    echo "GET1 - OK"
else
    echo "GET1 - Fail"
fi

curl -X POST -H "Content-Type: application/json" -d \
    '{"id":"2","name":"movie2","genre":"action","year":"2002"}' "localhost:8080/";
curl -X POST -H "Content-Type: application/json" -d \
    '{"id":"3","name":"movie3","genre":"action","year":"2003"}' "localhost:8080/"; 
curl -X POST -H "Content-Type: application/json" -d \
    '{"id":"4","name":"movie4","genre":"action","year":"2004"}' "localhost:8080/"; 
curl --silent --output diffs/teste2.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/"

diff diffs/teste2.log logs/get2.log > diffs/diff2
x=$(wc -c < diffs/diff2)
if [[ "$x" == "0" ]]; then
    echo "GET2 - OK"
else
    echo "GET2 - Fail"
fi

curl --silent --output diffs/teste3.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/1" 
diff diffs/teste3.log logs/get3.log > diffs/diff3
x=$(wc -c < diffs/diff3)
if [[ "$x" == "0" ]]; then
    echo "GET3 - OK"
else
    echo "GET3 - Fail"
fi

curl --silent --output diffs/teste3.log -X DELETE -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/1" 
curl --silent --output diffs/teste4.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/" 
diff diffs/teste4.log logs/get4.log > diffs/diff4
x=$(wc -c < diffs/diff4)
if [[ "$x" == "0" ]]; then
    echo "GET4 - OK"
else
    echo "GET4 - Fail"
fi

curl --silent --output diffs/teste5.log -X GET -H "Content-Type: application/json" -d \
    '{}' "localhost:8080/1" 
diff diffs/teste5.log logs/get5.log > diffs/diff5
x=$(wc -c < diffs/diff5)
if [[ "$x" == "0" ]]; then
    echo "GET5 - OK"
else
    echo "GET5 - Fail"
fi

rm -rf diffs
rm diff
rm log
rm sample
