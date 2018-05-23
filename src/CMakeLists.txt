add_executable(main
  main.cpp)

target_link_libraries(main 
  ${ROOT_LIBRARIES}
  ${DELPHES_LIBRARY}
  ${PYTHIA8_LIBRARY}
  m pthread dl)

