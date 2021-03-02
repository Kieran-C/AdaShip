#include <iostream>
#include "board.h"
#include "libarys/ini.h"
int main() {
  std::cout << "Starting up...\n";
  mINI::INIStructure setup = readIni();
  std::cout << setup["board"]["x"];
}