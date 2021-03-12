#include "ships.h"
#include "libarys/ini.h"
#include <iomanip>

ships::ships(std::string type, std::string passedDirection, mINI::INIStructure setup){
  length = std::stoi(setup["ships"][type]);
  active = true;
  direction = passedDirection;
  health = std::stoi(setup["ships"][type]);
}