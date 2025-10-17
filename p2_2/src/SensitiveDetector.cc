
#include "SensitiveDetector.hh"

#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4ios.hh"
#include "G4AnalysisManager.hh"

SensitiveDetector::SensitiveDetector(const G4String& name): G4VSensitiveDetector(name)
{

}

SensitiveDetector::~SensitiveDetector()
{
  
}



 


G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* history)
{

    
    return true;
}


