FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

COPY ./api/* ./api/
COPY ./cli/* ./cli/
COPY ./entrypoint.sh /

RUN apt-get clean && \
	apt-get update && \
	apt-get install -y build-essential sudo cmake \
	libjson-c-dev \
	libjansson-dev \
	libulfius-dev

ENTRYPOINT ["bash", "entrypoint.sh"] 
