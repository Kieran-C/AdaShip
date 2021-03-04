#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

std::vector<std::string> modes{"One Player VS Computer", "Two Player Game", "One Player VS Computer (salvo)", "Two player game (salvo)", "One player v computer (hidden mines)", "Two player game (hidden mines)", "Computer v computer (hidden mines)", "Quit"}; 

int menu(){
  std::cout << "BATTLESHIPS - Kieran Caruana";
  std::cout << "\n\nModes:\n\n";
  for(int i = 0; i < modes.size(); i++){
    std::cout << i+1 << ".\t" << modes[i] << "\n";
  }
  std::cout << std::endl << "Please enter a game mode number: ";
  int select;
  std::cin >> select;
  return 0;
}