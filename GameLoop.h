void mainLoop(Player& player1, Player& player2, board& b1, board& b2, std::vector<std::vector<int>>& b1Board, std::vector<std::vector<int>>& b2Board, mINI::INIStructure setup, std::vector<std::vector<Ships>>& allShipList);
std::string playerShooting();
std::vector<int> convertPointToCoord(std::string point);