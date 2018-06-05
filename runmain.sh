#!/bin/bash

./runindocker.sh sh -c "cmake . && make && env \$(cat .env) ./src/main $*"
