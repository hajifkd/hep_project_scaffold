#include <iostream>
#include "classes/DelphesClasses.h"
#include "TChain.h"
#include "ExRootAnalysis/ExRootTreeReader.h"


int main(int argc, char** argv) {
  using std::cout;
  using std::endl;

  cout << "Hello, world!" << endl;

  if (argc != 2) return 1;

  TChain chain("Delphes");
  chain.Add(argv[1]);

  ExRootTreeReader treeReader(&chain);

  return 0;
}
