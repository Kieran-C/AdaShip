///this is the main game loop, lots of data that has been setup prior to the game starting gets passed in and mainloop takes over. Game loop puts the program into a big while loop, this allows for the turn based system as everytime it gets the end of the instruction set, I switch the players and the loop restarts, the only exit conditions from the loop is if a user chooses the quit option in the menu, or a player wins
void mainLoop(Player& player1, Player& player2, board& b1, board& b2, std::vector<std::vector<int>>& b1Board, std::vector<std::vector<int>>& b2Board, mINI::INIStructure setup, std::vector<std::vector<Ships>>& allShipList);
///playerShooting is used to get the point the player wants to target. returns a string with the text based version of the point, ie the version that matches the axis scale in draw board
std::string playerShooting();
///convertPointToCoord takes the string point from playerShooting and converts it into a vector of ints which can be used as a reference point in the player board. This allows for the board to be checked and updated on that particular point
std::vector<int> convertPointToCoord(std::string point);
///areAllPlayerShipsDead checks the list of ships to see if all ships have sunk. Returns boolean.
bool areAllPlayerShipsDead(std::vector<Ships> ships);