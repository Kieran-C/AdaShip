#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <random>
#include "helpers.h"

//function comments are above function declaration in header file

int helpers::generateNumber(int maxValue){
    std::random_device rdev;
    std::mt19937 rgen(rdev());
    std::uniform_int_distribution<int> idist(1, maxValue); //(inclusive, inclusive)
    return idist(rgen);
}