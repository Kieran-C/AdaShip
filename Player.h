#include <vector>

class Player {
private:
  //declares the class variables
  int playerId;
  int shotsPerRound;
  int playerType;
  int numOfShips;
  int bombs;
  std::vector<std::string> shipLocations;

  
public:
  ///player constructor, used to set up a new player object. Takes all the arguemnets needed to setup player
  Player(int passedPlayerId, int passedPlayerType, int passedMode, int passedNumberOfShips, int passedBombs);
  ///setter for playerId, takes int, returns void
  void setPlayerId(int d);
  ///getter for playerid, takes no args, return int of playerId
  int getPlayerId();
  ///setter for shotsPerRound, takes int, returns void
  void setShotsPerRound(int s);
  ///getter for shotsPerRound, takes no args, returns int of shotsPerRound 
  int getShotsPerRound();
  ///setter for playerType, takes int, returns void
  void setPlayerType(int t);
  ///getter for playerType, takes no args, returns int of playerType
  int getPlayerType();
  ///setter for numOfShips, takes int, returns void
  void setNumOfShips(int s);
  ///getter for numOfShips, takes no args, returns int of numOfShips
  int getNumOfShips();
  ///setter for bombs, takes int, retruns void
  void setNumOfBombs(int b);
  ///getter for bombs, takes no args, returns int of bombs
  int getNumOfBombs();
};