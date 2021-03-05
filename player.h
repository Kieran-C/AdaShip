class Player {
  public:
    int shotsPerRound;
    int playerType;
    int numOfShips;
    int bombs;

    Player(int passedPlayerType, int passedMode, int passedNumberOfShips, int passedBombs){
      playerType = passedPlayerType;
      bombs = passedBombs;
      if (passedMode == 1){
        shotsPerRound = 1;
      }else if (passedMode == 2){
        shotsPerRound = passedNumberOfShips;
      }else if (passedMode == 3){
        shotsPerRound = 1;
      }else {
        shotsPerRound = 0;
      }
      numOfShips = passedNumberOfShips;
    }
};