FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

COPY ./api/* ./api/
COPY ./entrypoint.sh /

RUN apt-get clean && apt-get update && \
	apt-get install -y build-essential libcurl4-gnutls-dev libjson-c-dev \
	sudo libmicrohttpd-dev libjansson-dev libcurl4-gnutls-dev libgnutls28-dev \
	libgcrypt20-dev zlib1g-dev cmake git libsystemd-dev libulfius-dev uwsc curl

ENTRYPOINT ["bash", "entrypoint.sh"] 
