#!/bin/bash

touch .env
env $(cat .env) docker container run\
  -it --rm -v $PWD:/var/build --user=$(id -u):$(id -g)\
  -e "ROOT_INCLUDE_PATH=${ROOT_INCLUDE_PATH}" -w /var/build hfukuda/madgraph "$@"
