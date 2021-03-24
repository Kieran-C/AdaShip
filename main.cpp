#include <iostream>
#include "board.h"
#include "menu.h"
#include "iniHandler.h"
#include "Player.h"
#include "libarys/ini.h"
#include <vector>
#include <iomanip>
#include "helpers.h"
#include "GameLoop.h"

///Main.cpp is responsible for most of the inital setup and getting the game into the mainloop all configured properly. Ship validation happens here as well as ship placement, player creation and board creation

std::vector<Player> playerList; //initalises list playerList which contains Player objects
std::vector<std::vector<Ships>> allShipList; //inistalises allShipList which is a vector of vector of Ships objects
std::vector<std::string> shipTypes {"carrier", "battleship", "destroyer", "submarine", "patrolBoat"};

std::vector<char> alpha {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

///createShips fucntion takes the number of ships needing creating and creates the correct number of ship objects and adds them to a list
std::vector<Ships> createShips(int numOfShips, bool mines, mINI::INIStructure setup){
  std::vector<Ships> shipList;
  for (int i = 0; i < numOfShips; i++){
    shipList.push_back(Ships (shipTypes[i], "down", setup));
  }
  return shipList;
}

///placeShips is responsible for adding the ships to the board. It contains all the code for ai placement and manual placement, which is toggled by the ai variable thats passed in. It returns an updated board map.
std::vector<std::vector<int>> placeShips(std::vector<std::vector<int>> board, std::vector<Ships>& ships, bool ai){
  std::string autoPlace;
  std::string autoPlaceOne;
  if (!ai){
    bool autoValid = false;
    while(!autoValid){
      std::cout << std::endl << "Do you want to auto-place your ships? (y/n): ";
      std::cin >> autoPlace;
      if (autoPlace == "y"){
        ai = true;
        autoValid = true;
      }else if (autoPlace == "n"){
        autoValid = true;
      }
    }
  }
  for (int i = 0; i < ships.size(); ++i){
    bool shipInvalid = true;
    if (autoPlaceOne == "y"){
      ai = false;
    }
    if (!ai){
      bool valid = false;
      while(!valid){
        std::cout << std::endl << "Do you want to auto-place your " << ships[i].getType() << "? (y/n)";
        std::cin.clear();
        std::cin >> autoPlaceOne;
        if(autoPlaceOne == "y"){
          ai = true;
          valid = true;
        }else if (autoPlaceOne == "n"){
          ai = false;
          valid = true;
        }
      }
    }
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
          board[yCoords[x]][xCoords[x]] = ships[i].getShipId();
          ships[i].setPlaced(true);
          ships[i].appendNewCoordinate('x', xCoords[x]);
          ships[i].appendNewCoordinate('y', yCoords[x]);
        }
        shipInvalid = false;
      }
    }
  }
  std::cout << std::endl << std::endl;
  return board;
}

///gamemodeSetup setups all the player objects and triggers the creation of the appropriete ships and adds them to a list. Returns void
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

///resetBoard clears the game board and reinitalizes it. It also removes the coords for the ship opbjects and sets them as not placed.
std::vector<std::vector<int>> resetBoard(std::vector<std::vector<int>> passedBoard, board& b, mINI::INIStructure setup, std::vector<Ships>& ships){
  for (auto &i: passedBoard){
    i.clear();
  }
  passedBoard.clear();
  for (auto &i: ships){
    i.setPlaced(false);
    i.clearXCoordinates();
    i.clearYCoordinates();
  }
  return b.createBoardMap(setup);
}

///areAllShipsPlaced is a simple function that goes through and check if each ship in the past list is placed. Returns true if they are, returns false if there not
bool areAllShipsPlaced(std::vector<Ships> ships){
  int totalShipsPlaced = 0;
  for (auto &i: ships){
    if (i.getPlaced() == true){
      totalShipsPlaced++;
    }
  }
  if (totalShipsPlaced == ships.size()){
    return true;
  }else{
    return false;
  }

}

///main is the main function of the game, responsible for starting the game up and calling all the consequent functions. It creates the players board objects, players board maps, calls the function to get the main menu up, ensures everything is ready (all ships places etc.) before allowing gameloop to commence
int main() {
  bool continueGame = false;
  std::cout << "Starting up...\n\n";
  mINI::INIStructure setup = readIni();
  board b1(setup, "Player 1");
  board b2(setup, "Player 2");
  std::vector<std::vector<int>> b1Board = b1.createBoardMap(setup);
  std::vector<std::vector<int>> b2Board = b2.createBoardMap(setup);
  bool modeValid = false;
  int mode;
  while (!modeValid){
    mode = mainMenu();
    if ((mode == 1) || (mode == 8)){
      modeValid = true;
      gamemodeSetup(mode, setup, b1, b2);
    }else if ((mode >= 2) && (mode <= 7)){
      std::cout << std::endl << "GAMEMODE STILL IN DEVELOPMENT" << std::endl;
    }
  }
  b1.boardDraw(setup, b1Board);
  b1Board = placeShips(b1Board, allShipList[0], false);
  b2Board = placeShips(b2Board, allShipList[1], true);
  b1.boardDraw(setup, b1Board);
  b2.boardDraw(setup, b2Board);
  shipOverview("Player 1", allShipList[0]);
  // shipOverview("Player 2", allShipList[1]);
  while (!continueGame){
    int subMenuDecision = confirmationMenu();
    if (subMenuDecision == 1){
      if (areAllShipsPlaced(allShipList[0])){
        continueGame = true;
        mainLoop(playerList[0], playerList[1], b1, b2, b1Board, b2Board, setup, allShipList);
      }else{
        std::cout << std::endl << "Cannot play game whilst not all ships are placed" << std::endl;
      }
    }else if (subMenuDecision == 2){
      b1Board = resetBoard(b1Board , b1, setup, allShipList[0]);
      b1.boardDraw(setup, b1Board);
      shipOverview("Player 1", allShipList[0]);
      std::string replace;
      bool replaceShips = false;
      while (!replaceShips){
        std::cout << std::endl << "Do you want to re-place your ships? (y/n) ";
        std::cin >> replace;
        if (replace == "y"){
          replaceShips = true;
          b1Board = placeShips(b1Board, allShipList[0], false);
        }else if(replace == "n"){
          replaceShips = true;
        }
      }
      b1.boardDraw(setup, b1Board);
      shipOverview("Player 1", allShipList[0]);
      
    }else if (subMenuDecision == 3){
      continueGame = true;
      exit(0);
    }else{
      std::cout << std::endl << "---- INVALID CHOICE ---";
    }
  }
}