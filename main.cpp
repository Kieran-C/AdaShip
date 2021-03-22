#include <iostream>
#include "board.h"
#include "menu.h"
#include "iniHandler.h"
#include "Player.h"
#include "libarys/ini.h"
#include <vector>
#include "Ships.h"
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

std::vector<std::vector<int>> placeShips(std::vector<std::vector<int>> board, std::vector<Ships> ships){
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
        if (((xCoord >= 0) && (xCoord <= board[0].size()) ) && ((yCoord >= 0) && (yCoord <= board.size()))){
          coordSelect = false;
        }
        std::cout << std::endl << "X: " << xCoord << " Y: " << yCoord << std::endl;
      }
      
      bool validCoords = false;
      bool dirSelect = true;
      while (dirSelect){
        xCoords.clear();
        yCoords.clear();
        std::cout << std::endl << "Please choose a direction for your " << ships[i].getType() << "(Left, Right or Down): ";
        std::string dir;
        std::cin >> dir;
        if (dir == "down"){
          for (int x = 0; x < ships[i].getLength(); x++){
            yCoords.push_back(yCoord + x);
            xCoords.push_back(xCoord);
          }
          dirSelect = false;
        }else if(dir == "left"){
          for (int x = 0; x < ships[i].getLength(); x++){
            xCoords.push_back(xCoord - x);
            yCoords.push_back(yCoord);
          }
          dirSelect = false;
        }else if(dir == "right"){
          for (int x = 0; x < ships[i].getLength(); x++){
            xCoords.push_back(xCoord + x);
            yCoords.push_back(yCoord);
          }
          dirSelect = false;
        }else{std::cout << "Invalid direction";}
      }
      for (int x = 0; x < xCoords.size(); x++){
        if ((board[yCoords[x]][xCoords[x]] == 0) && (yCoords[x] >= 0) && (xCoords[x] >= 0) && (yCoords[x] < board.size()) && (xCoords[x] < board[0].size())){
          coordValidCheck += 1;
        }
      }
      if (coordValidCheck == ships[i].getLength()){
        for (int x = 0; x < yCoords.size(); x++){
          auto it = board[yCoords[x]].begin() + xCoords[x];
          board[yCoords[x]].insert(it, 1);
        }
        shipInvalid = false;
      }
    }
  }
  return board;
}

void gamemodeSetup(int mode, mINI::INIStructure setup){
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
  board b1(setup);
  board b2(setup);
  std::vector<std::vector<int>> b1Board = b1.createBoardMap(setup);
  std::vector<std::vector<int>> b2Board = b2.createBoardMap(setup);
  int mode = menu();
  gamemodeSetup(mode, setup);
  b1.boardDraw(setup, b1Board);
  std::cout << std::endl;
  b2.boardDraw(setup, b2Board);
  std::cout << std::endl;
  b1Board = placeShips(b1Board, allShipList[0]);
  b1.boardDraw(setup, b1Board);

  // for (int i = 0; i < allShipList.size(); i++){
  //   for (int x = 0; x < allShipList[i].size(); x++){
  //     std::cout << "Player " << i <<" length: " << allShipList[i][x].getLength() << std::endl;
  //   }
  // }
}