#include <vector>

class Player {
private:
  int playerId;
  int shotsPerRound;
  int playerType;
  int numOfShips;
  int bombs;
  std::vector<std::string> shipLocations;

  
public:
  Player(int passedPlayerId, int passedPlayerType, int passedMode, int passedNumberOfShips, int passedBombs);
  void setPlayerId(int d);
  int getPlayerId();
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