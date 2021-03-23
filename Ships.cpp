#include "Ships.h"
#include "libarys/ini.h"
#include <iomanip>
#include <vector>
#include <iostream> 
#include <algorithm>

Ships::Ships(std::string type, std::string passedDirection, mINI::INIStructure setup){
  shipType = type;
  shipTypeAbbreviation = type[0];
  length = std::stoi(setup["ships"][type]);
  active = true;
  direction = passedDirection;
  health = std::stoi(setup["ships"][type]);
  placed = false;
  shipXCoordinates;
  shipYCoordinates;
  if (type[0] == 'c'){
    shipId = 1;
  }else if (type[0] == 'b'){
    shipId = 2;
  }else if (type[0] == 'd'){
    shipId = 3;
  }else if (type[0] == 's'){
    shipId = 4;
  }else if (type[0] == 'p'){
    shipId = 5;
  }else{
    shipId = 0;
  }
}

std::string Ships::getType(){
  return Ships::shipType;
}

void Ships::setType(std::string type){
  Ships::shipType = type;
}

int Ships::getLength(){
  return Ships::length;
}

void Ships::setLength(int passedLength){
  Ships::length = passedLength;
}

bool Ships::getActive(){
  return Ships::active;
}

void Ships::setActive(bool passedActive){
  Ships::active = passedActive;
}

std::string Ships::getDirection(){
  return Ships::direction;
}

void Ships::setDirection(std::string passedDirection){
  Ships::direction = direction;
}

int Ships::getHealth(){
  return Ships::health;
}

void Ships::setHealth(int passedHealth){
  Ships::health = passedHealth;
}

char Ships::getTypeAbbreviation(){
  return Ships::shipTypeAbbreviation;
}

void Ships::setTypeAbbreviation(char typeAbb){
  Ships::shipTypeAbbreviation = typeAbb;
}

bool Ships::getPlaced(){
  return Ships::placed;
}

void Ships::setPlaced(bool passedPlaced){
  Ships::placed = passedPlaced;
}

std::vector<int> Ships::getXCoordinates(){
  return Ships::shipXCoordinates;
}

void Ships::setXCoordinates(std::vector<int> shipXCoords){
  Ships::shipXCoordinates = shipXCoords;
}

std::vector<int> Ships::getYCoordinates(){
  return Ships::shipYCoordinates;
}

void Ships::setYCoordinates(std::vector<int> shipYCoords){
  Ships::shipYCoordinates = shipYCoordinates;
}

void Ships::setShipId(int passedId){
  Ships::shipId = passedId;
}

int Ships::getShipId(){
  return Ships::shipId;
}

void Ships::appendNewCoordinate(char axis, int coord){
  if (axis == 'x'){
    Ships::shipXCoordinates.push_back(coord);
  }else if (axis == 'y'){
    Ships::shipYCoordinates.push_back(coord);
  }
}

void Ships::clearXCoordinates(){
  Ships::shipXCoordinates.clear();
}

void Ships::clearYCoordinates(){
  Ships::shipYCoordinates.clear();
}

bool Ships::isShipSunk(){
  if (Ships::getHealth() <= 0){
    Ships::setActive(false);
    return true;
  }else{
    return false;
  }
}

std::vector<std::vector<int>> Ships::isShipHit(std::vector<int> coords, std::vector<std::vector<int>> board){
  std::vector<std::vector<int>> updatedBoard;
  auto yResult = std::find(Ships::shipYCoordinates.begin(), Ships::shipYCoordinates.end(), coords[0]);
  auto xResult = std::find(Ships::shipXCoordinates.begin(), Ships::shipXCoordinates.end(), coords[1]);
  if ((yResult != end(Ships::shipYCoordinates)) && (xResult != end(Ships::shipXCoordinates))){
    std::cout << std::endl << "HIT SHIP AT: X - " << coords[1] << " Y - " << coords[0];
    int indexYResult = std::distance(Ships::shipYCoordinates.begin(), yResult);
    int indexXResult = std::distance(Ships::shipXCoordinates.begin(), xResult);
    Ships::shipYCoordinates.erase(Ships::shipYCoordinates.begin() + indexYResult);
    Ships::shipXCoordinates.erase(Ships::shipXCoordinates.begin() + indexXResult);
    Ships::setHealth(Ships::getHealth()-1);
    board[coords[0]][coords[1]] = 6;
    updatedBoard = board;
    return updatedBoard;
  }else{
    if (board[coords[0]][coords[1]] == 0){
      board[coords[0]][coords[1]] = 7;
      updatedBoard = board;
    }else {
      updatedBoard = board;
    }
    return updatedBoard;
  }
}