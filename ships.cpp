#include "ships.h"
#include "libarys/ini.h"
#include <iomanip>
#include <vector>

std::vector<ships> shipList;  

ships::ships(std::string type, std::string passedDirection, mINI::INIStructure setup){
  length = std::stoi(setup["ships"][type]);
  active = true;
  direction = passedDirection;
  health = std::stoi(setup["ships"][type]);
}

// void ships::addShipToList(){
//   // shipList.emplace_back(ships::~ships());
// }