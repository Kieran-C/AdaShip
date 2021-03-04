#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> modes{"One Player VS Computer", "Two Player Game", "One Player VS Computer (salvo)", "Two player game (salvo)", "One player v computer (hidden mines)", "Two player game (hidden mines)", "Computer v computer (hidden mines)", "Quit"}; 

int menu(){
  std::cout << modes.size();
  return modes.size();
}