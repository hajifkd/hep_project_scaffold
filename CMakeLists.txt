cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

# Looking for ROOT
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS RIO)

# Looking for Delphes and ExRootAnalysis
file(GLOB mg5dirs /home/hep/MG5_*)

find_path(DELPHES_INCLUDE_DIR
  NAMES classes/DelphesClasses.h
  PATH_SUFFIXES Delphes
  HINTS ${mg5dirs})

find_path(DELPHES_EXTERNAL_INCLUDE_DIR
  NAMES ExRootAnalysis/ExRootTreeReader.h
  PATH_SUFFIXES external
  HINTS ${DELPHES_INCLUDE_DIR})

find_library(DELPHES_LIBRARY
  NAMES Delphes
  PATH_SUFFIXES lib
  HINTS ${DELPHES_INCLUDE_DIR})

# Looking for Pythia
find_path(PYTHIA8_INCLUDE_DIR
  NAMES Pythia8/Pythia.h
  PATH_SUFFIXES include include/Pythia8 include/pythia8
  HINTS /usr)

find_library(PYTHIA8_LIBRARY
  NAMES pythia8 Pythia8
  PATH_SUFFIXES lib)

# Include them all
include_directories(${PYTHIA8_INCLUDE_DIR})
include_directories(${DELPHES_EXTERNAL_INCLUDE_DIR})
include_directories(${DELPHES_INCLUDE_DIR})
include_directories(${ROOT_INCLUDE_DIRS})

file(WRITE .env
  "ROOT_INCLUDE_PATH=${ROOT_INCLUDE_DIRS}:${DELPHES_INCLUDE_DIR}:${DELPHES_EXTERNAL_INCLUDE_DIR}:${PYTHIA8_INCLUDE_DIR}")

# Codes in ./src directory
add_subdirectory(src)

