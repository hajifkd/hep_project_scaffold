#!/bin/bash

touch .env
docker container run\
  -it --rm -v $PWD:/var/build --user=$(id -u):$(id -g)\
  -e ROOT_INCLUDE_PATH="`env $(cat .env) printenv ROOT_INCLUDE_PATH`" -w /var/build hfukuda/madgraph "$@"
