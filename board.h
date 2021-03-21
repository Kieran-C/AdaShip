#include <vector>
#include "libarys/ini.h"

class board{
  private:
    int width;
    int height;
    std::vector<std::vector<int>> createBoardMap(mINI::INIStructure setup);
  public:
    board(mINI::INIStructure setup);
    static void boardSetup(mINI::INIStructure setup);
};