#ifndef SensitiveDetector_h
#define SensitiveDetector_h 1


#include "G4VSensitiveDetector.hh"


class G4Step;

class SensitiveDetector : public G4VSensitiveDetector
{
  public:
    SensitiveDetector(const G4String& name);

    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
    ~SensitiveDetector();

};


#endif
