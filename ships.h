#include "libarys/ini.h"


class ships {
  private:
    int length;
    bool active;
    std::string direction;
    int health;

  public:
    ships(std::string type, std::string passedDirection, mINI::INIStructure setup);
};