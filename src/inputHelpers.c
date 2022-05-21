/*
This is a library of functions used for input handling
Written by: Aaron Gumapac
*/
#include "inputHelpers.h"
#include "numericalOperations.h"
char capitalizeChar(char c){
    if(!checkIfInRange(c,97,122)){
        if(checkIfInRange(c,65,90))
         return c;
        // printf("function called: %s",__func__); uncomment if you would like to know which function called capitalizeChar(char c)
        // printf("invalid char/n"); uncomment if an error prompt is needed for chars you cannot capitalize
        return '0';
    }
    
    return c - 32;
}
char handleInput(char validInputs[], int nElements){
    //This function returns a validInput given any user input
    char cInitInput; 
    scanf("%c",&cInitInput);
    char cNormalizedInput = capitalizeChar(cInitInput);
    for (int i = 0; i < nElements; i++)
    {
        if(cNormalizedInput != validInputs[i]){
            continue;
        }
        return cNormalizedInput;
    }
    return handleInput(validInputs,nElements);
}