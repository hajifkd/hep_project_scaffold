# Sample Project

**CLING DOESN'T WORK WELL NOW. YOU NEED TO SET  `ROOT_INCLUDE_PATH=/home/hep/MG5_aMC_v2_6_2/Delphes/external`**

## Prerequisite

* Install Docker
* Update image `hfukuda/madgraph`

## Usage

```bash
./runindocker.sh COMMAND_TO_RUN
```

I have based on the image [rootproject/root-ubuntu16](https://hub.docker.com/r/rootproject/root-ubuntu16/)
adding `python`, `gfortran`, `build-essential` and `libboost-all-dev`.
I have checked fundamental commands like `make` and `cmake` are available.

### Sample

```bash
./runindocker.sh cmake .
./runindocker.sh make
./runindocker.sh ./main ./SOME_FILE_TO_PROCESS
```

