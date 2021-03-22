#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "menu.h"
// #include "Ships.h"

std::vector<std::string> modes{"One Player VS Computer", "Two Player Game", "One Player VS Computer (salvo)", "Two player game (salvo)", "One player v computer (hidden mines)", "Two player game (hidden mines)", "Computer v computer (hidden mines)", "Quit"}; 

int mainMenu(){
  std::cout << "BATTLESHIPS - Kieran Caruana";
  std::cout << "\n\nModes:\n\n";
  for(int i = 0; i < modes.size(); i++){
    std::cout << i+1 << ".\t" << modes[i] << "\n";
  }
  std::cout << std::endl << "Please enter a game mode number: ";
  int select;
  std::cin >> select;
  return select;
}

void shipOverview(std::string player, std::vector<Ships> ships){
  std::cout << std::endl << std::endl << std::setfill('-') << std::left << std::setw(35) << "|----" + player + "'s Ships" << "|" << std::endl;
  std::string placement;
  for (auto &y: ships){
    if (y.getPlaced() == 1){
      placement = "Placed";
    }else{placement = "Not Placed";}
      std::cout << "|" << std::setfill(' ') << std::right << std::setw(35) << "|" << std::endl << "|" << std::setfill(' ') << std::left << std::setw(30) << y.getType() + ":" <<std::right << std::setw(5) <<"|"<<std::endl;
     std::cout << std::left << std::setw(30) << "|Board Status: " + placement << std::right << std::setw(6) << "|" << std::endl;
     std::cout << std::left << std::setw(30) << "|Health: " + std::to_string(y.getHealth()) << std::right << std::setw(6) << "|" << std::endl;
   }
  std::cout << std::setfill('-') << std::left << std::setw(35) << "|----" << "|" << std::endl; 
}

int confirmationMenu(){
  int selection;
  std::cout << std::endl << "Please select an option to continue: " << std::endl;
  std::cout << "1 - Continue to game" << std::endl;
  std::cout << "2 - Reset Board" << std::endl;
  std::cout << "3 - Quit" << std::endl;
  std::cout << "Please choose option 1, 2 or 3: ";
  std::cin >> selection;
  return selection;
}