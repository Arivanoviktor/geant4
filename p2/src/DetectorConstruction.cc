

#include "DetectorConstruction.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include "G4Orb.hh"
#include "G4Tubs.hh"
#include "G4UniformMagField.hh"
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"

#include "SensitiveDetector.hh"
#include "G4SDManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume *DetectorConstruction::Construct()
{

  G4NistManager *nist = G4NistManager::Instance();
  G4Material *world_mat = nist->FindOrBuildMaterial("G4_AIR");


  G4bool checkOverlaps = true;
  G4double world_sizeXY = 100;
  G4double world_sizeZ = 100;
  auto solidWorld = new G4Box("World", 0.5 * world_sizeXY, 0.5 * world_sizeXY, 0.5 * world_sizeZ);
  auto logicWorld = new G4LogicalVolume(solidWorld, world_mat, "World");
  auto physWorld = new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logicWorld, "World", 0, false, 0, checkOverlaps);



  return physWorld;
}
