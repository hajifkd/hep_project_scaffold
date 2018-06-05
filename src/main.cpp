#include <iostream>
#include "classes/DelphesClasses.h"
#include "TChain.h"
#include "ExRootAnalysis/ExRootTreeReader.h"
#include "TClonesArray.h"


int main(int argc, char** argv) {
  using std::cout;
  using std::endl;

  cout << "Hello, world!" << endl;

  if (argc != 2) return 1;

  TChain chain("Delphes");
  chain.Add(argv[1]);

  ExRootTreeReader treeReader(&chain);

  auto* particles = treeReader.UseBranch("Particle");
  auto* met = treeReader.UseBranch("MissingET");

  const int nEvent = treeReader.GetEntries();

  for (unsigned int entry = 0; entry < nEvent; entry++) {
    treeReader.ReadEntry(entry);

    for (unsigned int i = 0; i < particles->GetEntries(); i++) {
    }
  }

  return 0;
}
