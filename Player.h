#include <vector>

class Player {
private:
  int shotsPerRound;
  int playerType;
  int numOfShips;
  int bombs;
  std::vector<std::string> shipLocations;

  
public:
  Player(int passedPlayerType, int passedMode, int passedNumberOfShips, int passedBombs);
  void setShotsPerRound(int s);
  int getShotsPerRound();
  void setPlayerType(int t);
  int getPlayerType();
  void setNumOfShips(int s);
  int getNumOfShips();
  void setNumOfBombs(int b);
  int getNumOfBombs();
  bool checkForShipAtLocation(std::string loc, bool destroyIfFound);
};