#include "libarys/ini.h"
#include <vector>
#include <iostream>

class Ships {
  private:
    int length;
    bool active;
    std::string direction;
    int health;

  public:
    Ships(std::string type, std::string passedDirection, mINI::INIStructure setup);
    static void shipCreation(int numOfPlayers, std::vector<std::string> shipTypes);
};