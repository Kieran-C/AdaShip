#include <iostream>
#include "board.h"
#include "menu.h"
#include "iniHandler.h"
#include "player.h"
#include "libarys/ini.h"

void gamemodeSetup(int mode, mINI::INIStructure setup){
  switch(mode){
    case 1 :
      Player p1(1, 1, setup, 0);
      Player p2(2, 1, setup, 0);
      std::cout << std::endl << p1.
  }
}

int main() {
  std::cout << "Starting up...\n\n";
  int mode = menu();
  mINI::INIStructure setup = readIni();
  gamemodeSetup(mode, setup);
}

