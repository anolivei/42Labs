#! /bin/bash

echo "BUILDING"

docker build . -t labs_api

echo "RUNNING"

docker run -it -p 8080:8080 labs_api