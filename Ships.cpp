#include "Ships.h"
#include "libarys/ini.h"
#include <iomanip>
#include <vector>
#include <iostream>

// std::vector<ships> shipList;  

Ships::Ships(std::string type, std::string passedDirection, mINI::INIStructure setup){
  shipType = type;
  shipTypeAbbreviation = type[0];
  length = std::stoi(setup["ships"][type]);
  active = true;
  direction = passedDirection;
  health = std::stoi(setup["ships"][type]);
  placed = false;
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