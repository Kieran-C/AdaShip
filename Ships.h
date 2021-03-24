#include "libarys/ini.h"
#include <vector>
#include <iostream>

class Ships {
  private:
    //declares class variables
    std::string shipType;
    char shipTypeAbbreviation;
    int length;
    bool active;
    std::string direction;
    int health;
    bool placed;
    std::vector<int> shipXCoordinates;
    std::vector<int> shipYCoordinates;
    int shipId;

  public:
    ///Ships constructor, takes all args needed to setup player object
    Ships(std::string type, std::string passedDirection, mINI::INIStructure setup);
    ///getter for type, takes no args, return string 
    std::string getType();
    ///setter for type, takes string as arg, returns void
    void setType(std::string type);
    ///getter for length, takes no args, returns int of length
    int getLength();
    ///setter for length, takes int as arg, returns void
    void setLength(int passedLength);
    ///getter for active, takes no args, retruns bool of active status
    bool getActive();
    ///setter for active, takes bool as arg, returns void
    void setActive(bool passedActive);
    ///getter for direction, takes no args, returns string for direction
    std::string getDirection();
    ///setter for direction, takes string as arg, returns void
    void setDirection(std::string passedDirection);
    ///getter for health, takes no args, returns int
    int getHealth();
    ///setter for health, takes int as arg, returns void
    void setHealth(int passedHealth);
    ///setter for typeAbb, takes char as arg, returns void
    void setTypeAbbreviation(char typeAbb);
    ///getter for typeAbb, takes no args, returns char of typeAbb
    char getTypeAbbreviation();
    ///setter for placed, takes bool as arg, returns void
    void setPlaced(bool passedPlaced);
    ///getter for placed, takes no args, returns bool of placed
    bool getPlaced();
    ///setter for shipXCoordinates, takes vector<int> as args, returns void
    void setXCoordinates(std::vector<int> shipXCoords);
    ///getter for shipXCoordinates, takes no args, returns vector<int>
    std::vector<int> getXCoordinates();
    ///setter for shipYCoordinates, takes vector<int> as args, returns void
    void setYCoordinates(std::vector<int> shipYCoords);
    ///getter for shipYCoordinates, takes no args, returns vector<int>
    std::vector<int> getYCoordinates();
    ///appendNewCoordinate places a new coordinate in either shipXCoordinates or shipYCoordinates depending on axis passed into function
    void appendNewCoordinate (char axis, int coord);
    ///clearXCoordinates clears the vector of x coordinates associated with this ship
    void clearXCoordinates();
    ///clearYCoordinates clears the vector of y coordinates associated with this ship
    void clearYCoordinates();
    ///isShipHit checks if passed coordinates have hit a ship, if they have the function updates the board with a hit marker on the board at the passed coordinate, if its missed then updates the board with a missed marker on the board at the passed coordinate. Returns the updated board
    std::vector<std::vector<int>> isShipHit(std::vector<int> coords, std::vector<std::vector<int>> board);
    ///setter for shipId, takes int as arg, returns void
    void setShipId(int passedId);
    ///getter for shipId, takes no args, return int as shipId
    int getShipId();
    ///updates active status if health is 0 and returns true, else returns false
    bool isShipSunk();
};