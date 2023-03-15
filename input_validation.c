#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"
// This program is for validation purposes.

/*
This function makes sure that the given input is not a space. Takes in the number of arguments read and the number of arguments 
needed from the user.
*/
bool isValidFormat(const int numArgsRead, const int numArgsNeed){
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do{
        scanf("%c", &character);
        if(!isspace(character)){
            formatIsGood = false;
        }
    }while(character != '\n');
    return formatIsGood;
}









