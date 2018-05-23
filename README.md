# Boilerplate

This repository is a scaffold for high-energy physics project using
[ROOT 6.x](https://root.cern.ch/), [Pythia 8](http://home.thep.lu.se/Pythia/) and
[Delphes with ExRootAnalysis](https://cp3.irmp.ucl.ac.be/projects/delphes).

In this scaffold, docker is utilized to ensure portability.
As long as `docker` command is installed, the project is guaranteed to run *anywhere*.

## Prerequisite

* Install Docker
    * Note that it is recommended for you to belong `docker` group.
* Update image `hfukuda/madgraph`

```bash
docker image pull hfukuda/madgraph
```

## Basic Usage

```bash
./runindocker.sh COMMAND_TO_RUN
```

[The docker image](https://hub.docker.com/r/hfukuda/madgraph/) used in this script
is based on the image [rootproject/root-ubuntu16](https://hub.docker.com/r/rootproject/root-ubuntu16/)
with additional packages like `libboost-all-dev`.
So, commands like `make` and `cmake` are available.

Note that in order to load some header files from ROOT/Cling,
it is necessary to run cmake at least once to locate the header files,
which sets the enviroment variable `ROOT_INCLUDE_PATH` via `.env` file.

### Sample

```bash
./runindocker.sh cmake .
./runindocker.sh make
./runindocker.sh ./src/main ./SOME_FILE_TO_PROCESS
```

The series of these commands are summarized in a single script;

```bash
./runmain.sh ./SOME_FILE_TO_PROCESS
```

Note that the files to process must be in this or child directories, which are mounted in the container.
