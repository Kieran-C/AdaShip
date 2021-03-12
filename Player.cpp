#include <iostream>
#include "Player.h"

Player::Player(int passedPlayerType, int passedMode, int passedNumberOfShips, int passedBombs){
    playerType = passedPlayerType;
    bombs = passedBombs;
    if (passedMode == 1){
      shotsPerRound = 1;
    }else if (passedMode == 2){
      shotsPerRound = passedNumberOfShips;
    }else if (passedMode == 3){
      shotsPerRound = 1;
    }else {
      shotsPerRound = 0;
    }
    numOfShips = passedNumberOfShips;
}


void Player::setShotsPerRound(int s) {
  Player::shotsPerRound = s;
}

int Player::getShotsPerRound() {
  return Player::shotsPerRound;
}

void Player::setPlayerType(int t){
  Player::playerType = t;
}

int Player::getPlayerType(){
  return Player::playerType;
}

void Player::setNumOfShips(int s){
  Player::numOfShips = s;
}

int Player::getNumOfShips(){
  return Player::numOfShips;
}

void Player::setNumOfBombs(int b){
  Player::bombs = b;
}

int Player::getNumOfBombs(){
  return Player::bombs;
}

bool Player::checkForShipAtLocation(std::string loc, bool destroyIfFound){
  for (int i = 0; i <= Player::shipLocations.size(); i++){
    if ((Player::shipLocations[i].compare(loc)) && (destroyIfFound)){
      Player::shipLocations.erase(Player::shipLocations.begin()+i);
    }
  }
}