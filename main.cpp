#include <iostream>
#include "board.h"
#include "menu.h"
#include "iniHandler.h"
#include "Player.h"
#include "libarys/ini.h"
#include <vector>

std::vector<Player> playerList;

void gamemodeSetup(int mode, mINI::INIStructure setup){
  switch(mode){
    case 1: {
      playerList.push_back(Player (1, 1, 1, setup["ships"].size(), 0));
      playerList.push_back(Player (2, 2, 1, setup["ships"].size(), 0));
      std::cout << std::endl << "Player ID: " << playerList[0].getPlayerId() << std::endl;
      std::cout << std::endl << "Player ID: " << playerList[1].getPlayerId() << std::endl;
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
  int mode = menu();
  gamemodeSetup(mode, setup);
  setupShips()
}