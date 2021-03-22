#include <iostream>
#include "board.h"
#include "menu.h"
#include "iniHandler.h"
#include "Player.h"
#include "libarys/ini.h"
#include <vector>
#include <iomanip>
#include "helpers.h"

std::vector<Player> playerList;
std::vector<std::vector<Ships>> allShipList;
std::vector<std::string> shipTypes {"carrier", "battleship", "destroyer", "submarine", "patrolBoat"};

std::vector<char> alpha {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

std::vector<Ships> createShips(int numOfShips, bool mines, mINI::INIStructure setup){
  std::vector<Ships> shipList;
  for (int i = 0; i < numOfShips; i++){
    shipList.push_back(Ships (shipTypes[i], "down", setup));
  }
  return shipList;
}

std::vector<std::vector<int>> placeShips(std::vector<std::vector<int>> board, std::vector<Ships>& ships, bool ai){
  std::string autoPlace;
  if (!ai){
    std::cout << std::endl << "Do you want to auto-place your ships? (y/n): ";
    std::cin >> autoPlace;
    if (autoPlace == "y"){
      ai = true;
    }
  }
  for (int i = 0; i < ships.size(); ++i){
    bool shipInvalid = true;
    while(shipInvalid){
      bool coordSelect = true;
      int yCoord;
      int xCoord;
      int coordValidCheck = 0;
      std::vector<int> yCoords;
      std::vector<int> xCoords;
      while (coordSelect){
        if (!ai){
          std::cout << std::endl << "Please choose starting coordinate for your " << ships[i].getType() << " (length: " << ships[i].getLength() << "): ";
          std::string coord;
          std::cin >> coord;
          std::string strYCoord = ""; 
          for (int i = 1; i <= coord.size(); i++){
            strYCoord = strYCoord + coord[i];
          }
          yCoord = stoi(strYCoord);
          yCoord--;
          auto it = std::find(alpha.begin(), alpha.end(), coord[0]);
          if (it != alpha.end()){
            int xIndex = it - alpha.begin();
            xCoord = xIndex + 1;
            xCoord--;
          }
        }else{
          xCoord = (helpers::generateNumber(board[0].size()));
          yCoord = (helpers::generateNumber(board.size()));
        }
        if (((xCoord >= 0) && (xCoord <= board[0].size()) ) && ((yCoord >= 0) && (yCoord <= board.size()))){
          coordSelect = false;
        }
      }
      
      bool validCoords = false;
      bool dirSelect = true;
      while (dirSelect){
        std::string dir;
        xCoords.clear();
        yCoords.clear();
        if (!ai){
          std::cout << std::endl << "Please choose an orientation for your " << ships[i].getType() << "(horizontal or vertical): ";
          std::cin >> dir;
        }else{
          int ori = helpers::generateNumber(2);
          if (ori == 1){
            dir = "vertical";
          }else {
            dir = "horizontal";
          }
        }
        if (dir == "vertical"){
          yCoords.clear();
          xCoords.clear();
          for (int x = 0; x < ships.at(i).getLength(); x++){
            yCoords.push_back(yCoord + x);
            xCoords.push_back(xCoord);
          }
          dirSelect = false;
        }else if(dir == "horizontal"){
          for (int x = 0; x < ships[i].getLength(); x++){
            xCoords.push_back(xCoord + x);
            yCoords.push_back(yCoord);
          }
          dirSelect = false;
        }else{std::cout << "Invalid direction";}
      }
      for (int x = 0; x < xCoords.size(); x++){
        if ((yCoords[x] >= 0) && (xCoords[x] >= 0) && (yCoords[x] <= board.size()-1) && (xCoords[x] < board[0].size())){
          if (board[yCoords[x]][xCoords[x]] == 0){
            coordValidCheck += 1;
          }
        }else {
          // std::cout << std::endl << "[ERROR] X: " << xCoords[x] << " Y: " << yCoords[x] << " are not valid coordinates";
        }
      }
      if (coordValidCheck == ships[i].getLength()){
        for (int x = 0; x < yCoords.size(); x++){
          board[yCoords[x]][xCoords[x]] = 1;
          ships[i].setPlaced(true);
        }
        shipInvalid = false;
      }
    }
  }
  std::cout << std::endl << std::endl;
  return board;
}

void gamemodeSetup(int mode, mINI::INIStructure setup, board board1, board board2){
  switch(mode){
    case 1: {
      playerList.push_back(Player (1, 1, 1, setup["ships"].size(), 0));
      playerList.push_back(Player (2, 2, 1, setup["ships"].size(), 0));
      allShipList.push_back(createShips(setup["ships"].size(), false, setup));
      allShipList.push_back(createShips(setup["ships"].size(), false, setup));
      break;
    }
    case 2:{
      playerList.push_back(Player (1, 1, 1, setup["ships"].size(), 0));
      playerList.push_back(Player (2, 1, 1, setup["ships"].size(), 0));
      break;
    }
    case 3: {
      playerList.push_back(Player (1, 1, 2, setup["ships"].size(), 0));
      playerList.push_back(Player (2, 2, 2, setup["ships"].size(), 0));
      break;
    }
    case 4: {
      playerList.push_back(Player (1, 1, 2, setup["ships"].size(), 0));
      playerList.push_back(Player (2, 1, 2, setup["ships"].size(), 0));
      break;
    }
    case 5: {
      playerList.push_back(Player (1, 1, 3, setup["ships"].size(), 5));
      playerList.push_back(Player (2, 2, 3, setup["ships"].size(), 5));
      break;
    }
    case 6: {
      playerList.push_back(Player (1, 1, 3, setup["ships"].size(), 5));
      playerList.push_back(Player (2, 1, 3, setup["ships"].size(), 5));
      break;
    }
    case 7: {
      playerList.push_back(Player (1, 2, 3, setup["ships"].size(), 5));
      playerList.push_back(Player (2, 2, 3, setup["ships"].size(), 5));
      break;
    }
    case 8: {
      std::cout << std::endl << "Quitting..." << std::endl;
      exit(1);
      break;
    }
    default: {
      std::cout << "ERROR - INVALID MODE!" << std::endl;
      break;
    }
  }
}

int main() {
  std::cout << "Starting up...\n\n";
  mINI::INIStructure setup = readIni();
  board b1(setup, "Player 1");
  board b2(setup, "Player 2");
  std::vector<std::vector<int>> b1Board = b1.createBoardMap(setup);
  std::vector<std::vector<int>> b2Board = b2.createBoardMap(setup);
  int mode = mainMenu();
  gamemodeSetup(mode, setup, b1, b2);
  // b1.boardDraw(setup, b1Board);
  // std::cout << std::endl;
  // b2.boardDraw(setup, b2Board);
  // std::cout << std::endl;
  b1Board = placeShips(b1Board, allShipList[0], false);
  b1.boardDraw(setup, b1Board);
  shipOverview("Player 1", allShipList[0]);
  //  for (auto &y: allShipList[0]){
  //    std::cout << std::endl << y.getType() << ": " << y.getPlaced();
  //  }

  // for (int i = 0; i < allShipList.size(); i++){
  //   for (int x = 0; x < allShipList[i].size(); x++){
  //     std::cout << "Player " << i <<" length: " << allShipList[i][x].getLength() << std::endl;
  //   }
  // }
}