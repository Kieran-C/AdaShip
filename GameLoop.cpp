#include <iostream>
#include "Player.h"
#include "board.h"
#include "Ships.h"

std::vector<char> charAlpha {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

std::vector<int> convertPointToCoord(std::string point){
  std::string strYCoord = ""; 
  int xCoord;
  for (int i = 1; i <= point.size(); i++){
    strYCoord = strYCoord + point[i];
  }
  int yCoord = stoi(strYCoord);
  yCoord--;
  auto it = std::find(charAlpha.begin(), charAlpha.end(), point[0]);
  if (it != charAlpha.end()){
    int xIndex = it - charAlpha.begin();
    xCoord = xIndex + 1;
    xCoord--;
  }
  std::vector<int> pointCoords {yCoord, xCoord};
  return pointCoords;
}

std::string playerShooting(){
  std::string shotPoint;
  std::cout << std::endl << "Please enter coordinate to fire at: ";
  std::cin >> shotPoint;
  return shotPoint;
}

void mainLoop(Player& player1, Player& player2, board& b1, board& b2, std::vector<std::vector<int>>& b1Board, std::vector<std::vector<int>>& b2Board, mINI::INIStructure setup, std::vector<std::vector<Ships>>& allShipList){
  bool play = true;
  int turn = 1;
  Player& currentPlayer = player1;
  Player& notCurrentPlayer = player2;
  std::vector<int> pointCoord;
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
      std::string point = playerShooting();
      pointCoord = convertPointToCoord(point);
    }else{//AI Player
      std::cout << std::endl << "AI PLAYER NOT YET IMPLEMENTED";
      pointCoord = {0,0};
    }
    for (auto &i: allShipList[(notCurrentPlayer.getPlayerId())-1]){
        if (currentPlayer.getPlayerId() == 1){
          b2Board = i.isShipHit(pointCoord, b2Board);
        }else{
          b1Board = i.isShipHit(pointCoord, b1Board);
        }
      }
    turn++;
  }
}