#include <iostream>
#include "Player.h"
#include "board.h"
// #include "Ships.h"
#include "menu.h"
#include "helpers.h"

std::vector<char> charAlpha {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

std::vector<int> convertPointToCoord(std::string point){
  std::string col;
  int row;
  int yCoord;
  int xCoord;
  if (point != "auto"){
    for (char &c : point){
      if (isalpha(c)) {
        col += c;
      }
    }
    std::transform(col.begin(), col.end(), col.begin(), ::tolower);
    row = stoi(point.substr(col.size(), point.size()));
    yCoord = row - 1;
  }

  for (int i = 0; i < col.size(); i++){
    auto it = std::find(charAlpha.begin(), charAlpha.end(), col[i]);
    if (it != charAlpha.end()){
      int xIndex = it - charAlpha.begin();
      xCoord = ((26 * i) + xIndex);
    }
  }
  std::vector<int> pointCoords {yCoord, xCoord};
  std::cout << std::endl << "Y Coord: " << yCoord << "X Coord: " << xCoord << std::endl;
  return pointCoords;
}

std::string playerShooting(){
  std::string shotPoint;
  std::cout << std::endl << "Please enter coordinate to fire at: ";
  std::cin >> shotPoint;
  return shotPoint;
}

bool areAllPlayerShipsDead(std::vector<Ships> ships){
  bool allShipsDead = false;
  int deadShips = 0;
  for (auto &i: ships){
    if (i.getActive() == false){
      deadShips++;
    }
  }
  if (deadShips == ships.size()){
    allShipsDead = true;
  }else{allShipsDead = false;}
  return allShipsDead;
}

void mainLoop(Player& player1, Player& player2, board& b1, board& b2, std::vector<std::vector<int>>& b1Board, std::vector<std::vector<int>>& b2Board, mINI::INIStructure setup, std::vector<std::vector<Ships>>& allShipList){
  bool play = true;
  int turn = 1;
  Player& currentPlayer = player1;
  Player& notCurrentPlayer = player2;
  std::vector<int> pointCoord;
  bool player1Win;
  bool player2Win;
  while (play){
    std::cout << std::endl;
    b1.boardDraw(setup, b1Board);
    std::cout << std::endl;
    b2.boardDraw(setup, b2Board);
    std::cout << std::endl;
    pointCoord.clear();
    bool hit = false;
    Player tempPlayer = currentPlayer; 
    if (turn == 1) {
    }else if (turn % 2 == 0){
      currentPlayer = notCurrentPlayer;
      notCurrentPlayer = tempPlayer;
    }else {
      currentPlayer = notCurrentPlayer;
      notCurrentPlayer = tempPlayer;
    }
    if (currentPlayer.getPlayerType() == 1){//Human Player
      bool valid = false;
      while (!valid){
        std::string point = playerShooting();
        pointCoord = convertPointToCoord(point);
        if ((pointCoord[0] >= 0) && (pointCoord[0] < b1Board.size()) && (pointCoord[1] >= 0) && (pointCoord[1] < b1Board[0].size())){
          std::cout << std::endl << "Valid Shot" << std::endl;
          valid = true;
        }else{std::cout << std::endl << "INVALID POINT" << std::endl;}
      }
      
    }else{//AI Player
      int x = (helpers::generateNumber(10))-1;
      int y = (helpers::generateNumber(10))-1;
      pointCoord = {y,x};
    }
    for (auto &i: allShipList[(notCurrentPlayer.getPlayerId())-1]){
      if (currentPlayer.getPlayerId() == 1){
        b2Board = i.isShipHit(pointCoord, b2Board);
        i.isShipSunk();
      }else{
        b1Board = i.isShipHit(pointCoord, b1Board);
        i.isShipSunk();
      }
    }
    player1Win = areAllPlayerShipsDead(allShipList[1]);
    player2Win = areAllPlayerShipsDead(allShipList[0]);
    if ((player1Win)||(player2Win)){
      play = !play;
    }
    int endTurnSelection;
    if (currentPlayer.getPlayerType() == 1){
      endTurnSelection = gameLoopMenu();
    }else{
      pressAnyKeyToContinue();
    }
    if (endTurnSelection == 1){
      std::cout << std::endl<< "Next Player...";
    }else if (endTurnSelection == 2){
      shipOverview("Player " + std::to_string(currentPlayer.getPlayerId()), allShipList[0]);
      std::cout << std::endl<< "Next Player...";
    }else if (endTurnSelection == 3){
      exit(0);
    }
    turn++;
  }
  std::cout << std::endl << "P1 Win? " << player1Win;
  std::cout << std::endl << "P2 Win? " << player2Win;
}