#include "Ships.h"
#include "libarys/ini.h"
#include <iomanip>
#include <vector>
#include <iostream>

// std::vector<ships> shipList;  

Ships::Ships(std::string type, std::string passedDirection, mINI::INIStructure setup){
  length = std::stoi(setup["ships"][type]);
  active = true;
  direction = passedDirection;
  health = std::stoi(setup["ships"][type]);
}

void shipCreation(int numOfPlayers, std::vector<std::string> shipTypes){
  for (int i = 0; i < numOfPlayers; i++){
      std::cout << "TEST" << std::endl;
  }
}