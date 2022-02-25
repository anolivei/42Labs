#! /bin/bash

echo "BUILDING"

docker build . -t labs_api

echo "RUNNING"

docker run --name labs_api -it -p 8080:8080 labs_api