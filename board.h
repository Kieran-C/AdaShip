#include <vector>
#include "libarys/ini.h"

class board{
  private:
    int width;
    int height;
    std::vector<std::vector<int>> createBoardMap(mINI::INIStructure setup);
    
  public:
    int getWidth();
    void setWidth(int passedWidth);
    int getHeight();
    void setHeight(int passedHeight);
    board(mINI::INIStructure setup);
    void boardSetup(mINI::INIStructure setup);
    int boardDraw(mINI::INIStructure setup);
};