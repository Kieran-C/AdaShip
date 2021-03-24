#include <iostream>
#include "libarys/ini.h"
#include <string>
#include <iomanip>
#include <vector>
#include "board.h"

board::board(mINI::INIStructure setup, std::string passedName){
  width = stoi(setup["board"]["x"]);
  height = stoi(setup["board"]["y"]);
  name = passedName;
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
  std::cout << std::right << std::endl << std::setfill('-') << std::setw((width*5)/2) << "-";
  std::cout << board::name;
  std::cout << std::setfill('-') << std::setw((width*5)/2) << "-" << std::endl << std::endl;
  int maxX = 0;
  for (int y = 0; y <= stoi(setup["board"]["y"]); y++){
    for (int i = 0; i < (stoi(setup["board"]["x"])+1); i++){
      
      if ((y == 0) && (i != 0)) {
        std::cout << "|" << std::setfill('-') << std::setw(5) << "-" + alphabet[i-1] + "--" << std::setfill(' ');
        if (maxX < i){
          maxX = i;
        }
      }
      if (y != 0){
        if (i == 0){
          std::cout << "|";
        }else{
          if (board[y-1][i-1] != 0){
            std::string shipPiece;
            int piece = board[y-1][i-1];
            if (piece == 1){
              shipPiece = "C";
            }else if (piece == 2){
              shipPiece = "B";
            }else if (piece == 3){
              shipPiece = "D";
            }else if (piece == 4){
              shipPiece = "S";
            }else if (piece == 5){
              shipPiece = "P";
            }else if (piece == 6){
              printf("\033[31m");
              shipPiece = "h";
            }else if (piece == 7){
              printf("\033[33m");
              shipPiece = "m";
            }
            std::cout << std::right <<std::setw(5)<< " " + shipPiece + "  ";
            printf("\033[0m");
            std::cout<< "|";
          }else{std::cout <<std::setw(6)<< "|";}
          
        }
      }
    }
    if (y != 0){
      std::cout << y <<"\n";
    }else{std::cout << "|\n";}
    
  }
  for (int i = 0; i < maxX; i++){
    std::cout << "|-----";
  }
  std::cout << "|";
  // ------- PRINTS GRID AS TEXT --------------
  // std::cout << std::endl << std::endl;
  // for (auto &y: board){
  //   for (auto &x: y){
  //     std::cout << x;
  //   }
  //   std::cout << std::endl;
  // }
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
