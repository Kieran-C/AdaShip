#include <vector>
#include "libarys/ini.h"
#include "Player.h"

class board{
  private:
    int width;
    int height;
    
  public:
    int getWidth();
    void setWidth(int passedWidth);
    int getHeight();
    void setHeight(int passedHeight);
    board(mINI::INIStructure setup);
    void boardSetup(mINI::INIStructure setup);
    int boardDraw(mINI::INIStructure setup);
    std::vector<std::vector<int>> createBoardMap(mINI::INIStructure setup);
    std::vector<std::vector<int>> addShipsToBoard(std::vector<std::vector<Ships>> allShipList, std::vector<std::vector<int>> boardLayout);
};