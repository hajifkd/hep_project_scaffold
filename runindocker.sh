#!/bin/bash

docker container run -it --rm -v $PWD:/var/build --user=$(id -u):$(id -g) -w /var/build -e ROOT_INCLUDE_PATH=/home/hep/MG5_aMC_v2_6_2/Delphes/external hfukuda/madgraph "$@"
