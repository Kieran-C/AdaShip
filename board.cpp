#include <iostream>
#include "libarys/ini.h"
#include <string>
#include <iomanip>

mINI::INIStructure readIni(){
  mINI::INIFile file("adashipConfig.ini");
  mINI::INIStructure ini;
  try {
    bool readSuccess = file.read(ini);
    std::cout << "INI file read successfully\n\n";
    return ini;
  }catch (std::exception e) {
    std::cout << "Error reading INI file\nGot following error: ";
    std::cerr << e.what();
  }
}

int boardDraw(mINI::INIStructure setup){
  int maxX = 0;
  for (int y = 0; y < stoi(setup["board"]["y"]); y++){
    for (int i = 0; i < (stoi(setup["board"]["x"])+1); i++){
      if ((y == 0) && (i != 0)) {
        std::cout << "-----";
        if (maxX < i){
          maxX = i;
        }
      }
      if (y != 0){
        if (i == 0){
          std::cout << "|";
        }else{
          std::cout <<std::setw(5) << "|";
        }
      }
    }
    std::cout << "\n";
  }
  for (int i = 0; i < maxX; i++){
    std::cout << "-----";
  }
  return 1;
}

void boardSetup() {
  mINI::INIStructure setup = readIni();
  boardDraw(setup);
}