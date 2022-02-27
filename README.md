<h1 align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/747/747131.png" alt="lab" width="150" height="150">
</h1>

<h1 align="center">
  42 Labs Selection Process
</h1>

<p align="center">
   <img alt="Norminette" src="https://github.com/42sp/42labs-selection-process-v2-anolivei/actions/workflows/norminette.yml/badge.svg?event=push">
</p>


<p align="center">
  <a href="#about">About</a> &#xa0; | &#xa0; 
  <a href="#methods">Methods</a> &#xa0; | &#xa0;
  <a href="#technologies">Technologies</a> &#xa0; | &#xa0;
  <a href="#requirements">Requirements</a> &#xa0; | &#xa0;
  <a href="#starting">Starting</a> &#xa0; | &#xa0;
  <a href="#testing">Testing</a> &#xa0; | &#xa0;
  <a href="https://github.com/anolivei" target="_blank">Author</a>
</p>

<br>

## About ##
This project has two applications: a Rest API and a CLI application, 
both written in C language.<br>
The Rest API send, receive, change and remove movie data in format json, using 
the methods POST, GET, PUT and DELETE, while print the logs in a file api.log
and also in terminal.<br>
The CLI application is a simple applicaton which reads the api.log file and
prints a resume of this logs.

It's running on [DigitalOcean](https://www.digitalocean.com/) cloud: http://162.243.163.141:8080/ 


[Project Planning](https://tree.taiga.io/project/anolivei-42-labs/timeline)

[Notion with important links](https://www.notion.so/42-Labs-69ad2915d4f44ec1825bad69779d696b)

## Methods ##
- POST:

  localhost:8080/ - add a new movie

- GET:

  localhost:8080/ - lists all movies

  localhost:8080/:id - lists a specifc movie

- PUT:

  localhost:8080/:id - modify an existing movie

- DELETE:

  localhost:8080/:id - delete an existing movie

A movie is a JSON object with the following model:
```json
{
  "id": "1",
  "title": "Back to the Future",
  "genre": "Sci-fi",
  "year": "1985"
}
```

## Technologies ##

The following tools were used in this project:

- [Ulfius](https://babelouest.github.io/ulfius/)
- [Jansson](https://jansson.readthedocs.io/en/2.5/index.html)
- [Docker](https://www.docker.com/)

## Requirements ##

Before starting, you need to have [Git](https://git-scm.com) and 
[Docker](https://docs.docker.com/engine/install/) installed.

## Starting ##

Rest API:

```bash
# Clone this project
git clone https://github.com/42sp/42labs-selection-process-v2-anolivei

# Access
cd 42labs-selection-process-v2-anolivei

# Run the project
bash run.sh

# The server will initialize in the <http://localhost:8080>

# To stop the server press enter

# To remove the container
docker rm labs_api

# To remove the images
docker rmi labs_api ubuntu
```
CLI Application:
```bash
# Open a new terminal and execute
docker exec -it labs_api /bin/bash

# Access
cd cli

# Compile and run
make run
```
## Testing ##
```bash
# Open a new terminal and execute
docker exec -it labs_api /bin/bash

# Access
cd tests

# Run
bash test.sh
```

&#xa0;

<a href="#top">Back to top</a>
