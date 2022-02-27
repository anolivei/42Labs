# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 02:46:36 by anolivei          #+#    #+#              #
#    Updated: 2022/02/27 13:46:26 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

COPY ./api/* ./api/
COPY ./cli/* ./cli/
COPY ./tests/ ./tests/
COPY ./entrypoint.sh /

RUN apt-get clean && \
	apt-get update && \
	apt-get install -y build-essential sudo cmake curl \
	libjansson-dev \
	libulfius-dev

ENTRYPOINT ["bash", "entrypoint.sh"] 
