#include <iostream>
#include "libarys/ini.h"

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