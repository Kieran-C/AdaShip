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
    int getLength();
    void setLength(int passedLength);
    bool getActive();
    void setActive(bool passedActive);
    std::string getDirection();
    void setDirection(std::string passedDirection);
    int getHealth();
    void setHealth(int passedHealth);
};