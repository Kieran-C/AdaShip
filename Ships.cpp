#include "Ships.h"
#include "libarys/ini.h"
#include <iomanip>
#include <vector>
#include <iostream> 

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