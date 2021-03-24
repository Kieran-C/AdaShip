#include "Ships.h"

///mainMenu displays the main menu, which asks the user to select a game mode after having first dispalyed the options. returns the int the user selected
int mainMenu();
///shipOverview displays the table of ship properties. This includes if it has been placed, if it is sunk and how much health it has left 
void shipOverview(std::string player, std::vector<Ships> ships);
///confirmationMenu displays user options before gameloop starts, returns int of user selection
int confirmationMenu();
///gameLoopMenu gives the options after users turn to either end there turn, view player details or quit the game. Returns the int of user selection
int gameLoopMenu();
///pressAnyKeyToContinue just holds the program until a user presses enter. Returns void
void pressAnyKeyToContinue();
///win prints ascii art corrosponding with the winning player. It takes an int arguemnt and this is the winning players ID so it knows which ascii art to print. Returns void
void win(int player);