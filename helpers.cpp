#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int generateNumber(int maxValue){
    srand((unsigned) time(0));
    int result = 1 + (rand() % maxValue);
}