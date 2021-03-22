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

std::vector<std::string> alphabet {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

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

int board::boardDraw(mINI::INIStructure setup, std::vector<std::vector<int>> board){
  int maxX = 0;
  for (int y = 0; y <= stoi(setup["board"]["y"]); y++){
    for (int i = 0; i < (stoi(setup["board"]["x"])+1); i++){
      
      if ((y == 0) && (i != 0)) {
        std::cout << "|" << std::setfill('-') << std::setw(4) << alphabet[i-1] << std::setfill(' ');
        if (maxX < i){
          maxX = i;
        }
      }
      if (y != 0){
        if (i == 0){
          std::cout << "|";
        }else{
          if (board[y-1][i-1] != 0){
            std::cout <<std::setw(4)<< board[y-1][i-1] << "|";
          }else{std::cout <<std::setw(5)<< "|";}
          
        }
      }
    }
    if (y != 0){
      std::cout << y <<"\n";
    }else{std::cout << "|\n";}
    
  }
  for (int i = 0; i < maxX; i++){
    std::cout << "|----";
  }
  std::cout << "|";
  return 1;
}

std::vector<std::vector<int>> board::createBoardMap(mINI::INIStructure setup){
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
  return boardLayout;
}
