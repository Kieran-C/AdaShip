#include <iostream>
#include "board.h"
#include "menu.h"
#include "iniHandler.h"
#include "Player.h"
#include "libarys/ini.h"

void gamemodeSetup(int mode, mINI::INIStructure setup){
  switch(mode){
    case 1: {
      Player p1(1, 1, setup["ships"].size(), 0);
      Player p2(2, 1, setup["ships"].size(), 0);
      break;
    }
    case 2:{
      Player p1(1, 1, setup["ships"].size(), 0);
      Player p2(1, 1, setup["ships"].size(), 0);
      break;
    }
    case 3: {
      Player p1(1, 2, setup["ships"].size(), 0);
      Player p2(2, 2, setup["ships"].size(), 0);
      break;
    }
    case 4: {
      Player p1(1, 2, setup["ships"].size(), 0);
      Player p2(1, 2, setup["ships"].size(), 0);
      break;
    }
    case 5: {
      Player p1(1, 3, setup["ships"].size(), 5);
      Player p2(2, 3, setup["ships"].size(), 5);
      break;
    }
    case 6: {
      Player p1(1, 3, setup["ships"].size(), 5);
      Player p2(1, 3, setup["ships"].size(), 5);
      break;
    }
    case 7: {
      Player p1(2, 3, setup["ships"].size(), 5);
      Player p2(2, 3, setup["ships"].size(), 5);
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
}