#include <vector>
#include "libarys/ini.h"


class board{
  private:
  //board attributes
    int width;
    int height;
    std::string name;
    
  public:
    ///getter for board width.Takes no args. Returns int
    int getWidth();
    ///setter for board width.Takes int. Returns void
    void setWidth(int passedWidth);
    ///getter for board height.Takes no args. Return int
    int getHeight();
    ///setter for board height. Takes int. Return void
    void setHeight(int passedHeight);
    ///constructor for board, sets board attributes. Takes ini setup file, and the passed name for the board.
    board(mINI::INIStructure setup, std::string passedName);
    ///boardDraw is responsible for drawing the board. It takes setup file and a board, which is the borad going to be drawn. It works through it and sets up the axis and headers, before then looping through the board vector and placing the ships accordingly
    int boardDraw(mINI::INIStructure setup, std::vector<std::vector<int>> board);
    ///createBoardMap setups the vector board filled with 0's this is so I can then go back and assign ship ID's to certain places. These are the values boardDraw uses when drawing the board
    std::vector<std::vector<int>> createBoardMap(mINI::INIStructure setup);
};