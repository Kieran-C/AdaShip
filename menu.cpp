#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include "menu.h"
// #include "Ships.h"


std::vector<std::string> modes{"One Player VS Computer", "Two Player Game", "One Player VS Computer (salvo)", "Two player game (salvo)", "One player v computer (hidden mines)", "Two player game (hidden mines)", "Computer v computer (hidden mines)", "Quit"}; 

int mainMenu(){
  std::cout << "BATTLESHIPS - Kieran Caruana";
  std::cout << "\n\nModes:\n\n";
  for(int i = 0; i < modes.size(); i++){
    std::cout << i+1 << ".\t" << modes[i] << "\n";
  }
  bool valid = false;
  int select;
  while (!valid){
    std::cout << std::endl << "Please enter a game mode number: ";
    std::string strSelect;
    std::cin >> strSelect;
    if ((strSelect == "1") || (strSelect == "2") || (strSelect == "3")|| (strSelect == "4")|| (strSelect == "5")|| (strSelect == "6")|| (strSelect == "7")|| (strSelect == "8")){
      select = stoi(strSelect);
      valid = true;
    }else{
      std::cout << std::endl << "INVALID SELECTION" << std::endl;
    }
  }
  return select;
}

void shipOverview(std::string player, std::vector<Ships> ships){
  std::cout << std::endl << std::endl << std::setfill('-') << std::left << std::setw(35) << "|----" + player + "'s Ships" << "|" << std::endl;
  std::string placement;
  std::string floating;
  for (auto &y: ships){
    if (y.getPlaced() == 1){
      placement = "Placed";
    }else{placement = "Not Placed";}
    if (y.getActive() == false){
      floating = "Sunk";
    }else {
      floating = "Afloat";
    }
    std::cout << "|" << std::setfill(' ') << std::right << std::setw(35) << "|" << std::endl << "|" << std::setfill(' ') << std::left << std::setw(30) << y.getType() + ":" <<std::right << std::setw(5) <<"|"<<std::endl;
     std::cout << std::left << std::setw(30) << "|Board Status: " + placement + "/" + floating << std::right << std::setw(6) << "|" << std::endl;
     std::cout << std::left << std::setw(30) << "|Health: " + std::to_string(y.getHealth()) << std::right << std::setw(6) << "|" << std::endl;
   }
  std::cout << std::setfill('-') << std::left << std::setw(35) << "|----" << "|" << std::endl; 
}

int confirmationMenu(){
  int selection;
  std::string strSelection;
  bool valid = false;
  std::cin.ignore();
  while(!valid){
    std::cout << std::endl << "Please select an option to continue: " << std::endl;
    std::cout << "1 - Continue to game" << std::endl;
    std::cout << "2 - Reset Board" << std::endl;
    std::cout << "3 - Quit" << std::endl;
    std::cout << "Please choose option 1, 2 or 3: ";
    std::getline(std::cin, strSelection);
    if ((strSelection == "1") || (strSelection == "2") || (strSelection == "3")){
      selection = stoi(strSelection);
      valid = true;
      return selection;
    }else{
      std::cout << std::endl << "INVALID SELECTION - confirmation menu - " << strSelection << std::endl;
    }
  }
  return selection;
}

int gameLoopMenu(){
  int selection;
  std::string strSelection;
  bool valid = false;
  std::cin.ignore();
  while(!valid){
    std::cout << std::endl << "What would you like to do next?" << std::endl;
    std::cout << "1 - End Turn" << std::endl;
    std::cout << "2 - View Your Ships stats" << std::endl;
    std::cout << "3 - Quit" << std::endl;
    std::cout << "Please choose option 1, 2 or 3: ";
    std::cin >> strSelection;
    if ((strSelection == "1") || (strSelection == "2") || (strSelection == "3")){
      selection = stoi(strSelection);
      valid = true;
    }else{
      std::cout << std::endl << "INVALID SELECTION - gameloop" << std::endl;
    }
  }
  return selection;
}

void pressAnyKeyToContinue(){
  std::cin.clear();
  std::cin.ignore(1000000000, '\n');
  std::cout << std::endl << "Press Enter to continue" << std::endl;
  std::cin.get();
}

void win(int player){
  if (player == 1){
    std::cout << std::endl << std::endl; 
    std::cout << std::endl << " _____  _           __     ________ _____"; 
    std::cout << std::endl << "|  __ \\| |        /\\ \\   / /  ____|  __ \\ ";   
    std::cout << std::endl << "| |__) | |       /  \\ \\_/ /| |__  | |__) | "; 
    std::cout << std::endl << "|  ___/| |      / /\\ \\   / |  __| |  _  /  "; 
    std::cout << std::endl << "| |    | |____ / ____ \\| | | |____| | \\ \\  "; 
    std::cout << std::endl << "|_|    |______/_/    \\_\\_| |______|_|  \\_\\ "; 
    std::cout << std::endl << "                                            "; 
    std::cout << std::endl << "                                            "; 
    std::cout << std::endl << "  __  "; 
    std::cout << std::endl << " /_ | "; 
    std::cout << std::endl << "  | | "; 
    std::cout << std::endl << "  | | "; 
    std::cout << std::endl << "  | | "; 
    std::cout << std::endl << "  |_| "; 
    std::cout << std::endl << "      "; 
    std::cout << std::endl << "      "; 
    std::cout << std::endl << "__          _______ _   _  _____ "; 
    std::cout << std::endl << "\\ \\        / /_   _| \\ | |/ ____|"; 
    std::cout << std::endl << " \\ \\  /\\  / /  | | |  \\| | (___  "; 
    std::cout << std::endl << "  \\ \\/  \\/ /   | | | . ` |\\___ \\ "; 
    std::cout << std::endl << "   \\  /\\  /   _| |_| |\\  |____) |"; 
    std::cout << std::endl << "    \\/  \\/   |_____|_| \\_|_____/ "; 
  }else if(player == 2){
    std::cout << std::endl << std::endl; 
    std::cout << std::endl << " _____  _           __     ________ _____"; 
    std::cout << std::endl << "|  __ \\| |        /\\ \\   / /  ____|  __ \\ ";   
    std::cout << std::endl << "| |__) | |       /  \\ \\_/ /| |__  | |__) | "; 
    std::cout << std::endl << "|  ___/| |      / /\\ \\   / |  __| |  _  /  "; 
    std::cout << std::endl << "| |    | |____ / ____ \\| | | |____| | \\ \\  "; 
    std::cout << std::endl << "|_|    |______/_/    \\_\\_| |______|_|  \\_\\ "; 
    std::cout << std::endl << "                                            "; 
    std::cout << std::endl << "                                            "; 
    std::cout << std::endl << "   ___   "; 
    std::cout << std::endl << "  |__ \\ "; 
    std::cout << std::endl << "     ) | "; 
    std::cout << std::endl << "    / / "; 
    std::cout << std::endl << "   / /_  "; 
    std::cout << std::endl << "  |____| "; 
    std::cout << std::endl << "      "; 
    std::cout << std::endl << "      "; 
    std::cout << std::endl << "__          _______ _   _  _____ "; 
    std::cout << std::endl << "\\ \\        / /_   _| \\ | |/ ____|"; 
    std::cout << std::endl << " \\ \\  /\\  / /  | | |  \\| | (___  "; 
    std::cout << std::endl << "  \\ \\/  \\/ /   | | | . ` |\\___ \\ "; 
    std::cout << std::endl << "   \\  /\\  /   _| |_| |\\  |____) |"; 
    std::cout << std::endl << "    \\/  \\/   |_____|_| \\_|_____/ "; 
  }
}