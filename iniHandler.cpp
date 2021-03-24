#include <iostream>
#include "libarys/ini.h"

//function comments are above function declaration in header file

mINI::INIStructure readIni(){
  mINI::INIFile file("adaship_config.ini");
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