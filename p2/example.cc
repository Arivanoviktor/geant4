
#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"

#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "FTFP_BERT.hh"

int main(int argc, char** argv)
{
  // construct the default run manager
  // auto runManager = G4RunManagerFactory::CreateRunManager();

  G4RunManager* runManager = new G4RunManager;


  runManager->SetUserInitialization(new DetectorConstruction);

  auto physicsList = new FTFP_BERT;
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);

  runManager->SetUserInitialization(new ActionInitialization);


  auto visManager = new G4VisExecutive(argc, argv);
  visManager->Initialize();
  G4UIExecutive* ui = new G4UIExecutive(argc, argv);  


  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  UImanager->ApplyCommand("/control/execute init_vis.mac");


  ui->SessionStart();
  delete ui;

 

  delete runManager;
  return 0;
}