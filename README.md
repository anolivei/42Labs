<h1 align="center">42 Labs Selection Process</h1>

<p align="center">
   <img alt="Norminette" src="https://github.com/42sp/42labs-selection-process-v2-anolivei/actions/workflows/norminette.yml/badge.svg?event=push">
</p>


<p align="center">
  <a href="#about">About</a> &#xa0; | &#xa0; 
  <a href="#sparkles-features">Features</a> &#xa0; | &#xa0;
  <a href="#rocket-technologies">Technologies</a> &#xa0; | &#xa0;
  <a href="#requirements">Requirements</a> &#xa0; | &#xa0;
  <a href="#starting">Starting</a> &#xa0; | &#xa0;
  <a href="https://github.com/anolivei" target="_blank">Author</a>
</p>

<br>

## About ##

This is a Rest API written in C to send, receive, change and remove movie data
in format json, using the methods POST, GET, PUT and DELETE.

[Project Planning](https://tree.taiga.io/project/anolivei-42-labs/timeline)

[Notion with important links](https://www.notion.so/42-Labs-69ad2915d4f44ec1825bad69779d696b)

## Features ##

json example to POST:

```json
{
  "ID": "1",
  "title": "Back to the Future",
  "genre": "Sci-fi",
  "year": "1985"
}
```

## Technologies ##

The following tools were used in this project:

- [Ulfius](https://babelouest.github.io/ulfius/)
- [Docker](https://www.docker.com/)

## Requirements ##

Before starting, you need to have [Git](https://git-scm.com) and [Docker](https://docs.docker.com/engine/install/) installed.

## Starting ##

```bash
# Clone this project
$ git clone https://github.com/42sp/42labs-selection-process-v2-anolivei

# Access
$ cd 42labs-selection-process-v2-anolivei

# Run the project
$ bash run.sh

# The server will initialize in the <http://localhost:8080>
```

&#xa0;

<a href="#top">Back to top</a>
