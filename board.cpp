#include <iostream>
#include "libarys/ini.h"
#include <string>
#include <iomanip>
#include <vector>
#include "board.h"

board::board(mINI::INIStructure setup){
  width = stoi(setup["board"]["x"]);
  height = stoi(setup["board"]["y"]);
}

int board::getWidth(){
  return board::width;
}

void board::setWidth(int passedWidth){
  board::width = passedWidth;
}

int board::getHeight(){
  return board::height;
}

void board::setHeight(int passedHeight){
  board::height = passedHeight;
}

int board::boardDraw(mINI::INIStructure setup){
  int maxX = 0;
  for (int y = 0; y < stoi(setup["board"]["y"]); y++){
    for (int i = 0; i < (stoi(setup["board"]["x"])+1); i++){
      if ((y == 0) && (i != 0)) {
        std::cout << "-----";
        if (maxX < i){
          maxX = i;
        }
      }
      if (y != 0){
        if (i == 0){
          std::cout << "|";
        }else{
          std::cout <<std::setw(5) << "|";
        }
      }
    }
    std::cout << "\n";
  }
  for (int i = 0; i < maxX; i++){
    std::cout << "-----";
  }
  return 1;
}

std::vector<std::vector<int>> createBoardMap(mINI::INIStructure setup){
  std::vector<std::vector<int>> boardLayout;
  std::vector<int> row;
  for (int i = 0; i < stoi(setup["board"]["y"]); i++){
    for (int x = 0; x < stoi(setup["board"]["x"]); x++){
      row.push_back(0);
    }
    std::cout << std::endl;
    boardLayout.push_back(row);
    row.clear();
  }

  // for (int i = 0; i < boardLayout.size(); i++){
  //   for (int x = 0; x < boardLayout[0].size(); x++){
  //     std::cout << boardLayout[i][x] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  return boardLayout;
}

std::vector<std::vector<int>> addShipsToBoard(std::vector<std::vector<int>> boardLayout){
  std::vector<std::vector<int>> boardMap;
  
  return boardMap;
}

void boardSetup(mINI::INIStructure setup) {
  std::vector<std::vector<int>> boardLayout = createBoardMap(setup);
  // board::boardDraw(setup, boardLayout);
}