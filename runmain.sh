#!/bin/bash

./runindocker.sh sh -c "cmake . && make && ./src/main $@"
