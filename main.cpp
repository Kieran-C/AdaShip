#include <iostream>
#include "board.h"
#include "menu.h"
#include "libarys/ini.h"

int main() {
  std::cout << "Starting up...\n";
  menu();
  boardSetup();
}