#include "libarys/ini.h"
#include <vector>
#include <iostream>

class Ships {
  private:
    std::string shipType;
    char shipTypeAbbreviation;
    int length;
    bool active;
    std::string direction;
    int health;
    bool placed;
    std::vector<int> shipXCoordinates;
    std::vector<int> shipYCoordinates;

  public:
    Ships(std::string type, std::string passedDirection, mINI::INIStructure setup);
    std::string getType();
    void setType(std::string type);
    int getLength();
    void setLength(int passedLength);
    bool getActive();
    void setActive(bool passedActive);
    std::string getDirection();
    void setDirection(std::string passedDirection);
    int getHealth();
    void setHealth(int passedHealth);
    void setTypeAbbreviation(char typeAbb);
    char getTypeAbbreviation();
    void setPlaced(bool passedPlaced);
    bool getPlaced();
    void setXCoordinates(std::vector<int> shipXCoords);
    std::vector<int> getXCoordinates();
    void setYCoordinates(std::vector<int> shipYCoords);
    std::vector<int> getYCoordinates();
    void appendNewCoordinate (char axis, int coord);
    void clearXCoordinates();
    void clearYCoordinates();
};