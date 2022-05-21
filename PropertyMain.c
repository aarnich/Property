/*
Description: Property is a CLI-game that imitates the board game 'Monopoly' 
Programmed by: Aaron Gumapac S15B 
Last modified: January 6, 2021 
Version: 1.0 
[Acknowledgements: Geekhacks.org 
*/
#include "libs/gameEventHandlers.h"
#include <stdio.h>
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0]) 
int main()
{
    char cLoopPrompt = 'N';
    displayGreeting();
    displayMain(); //displays the game's main menu
    char cMainMenuInputs[2] = {'G','E'}; //all valid inputs for the given prompt
    char cMainMenuChoice = handleInput(
        cMainMenuInputs, ARRAY_SIZE(cMainMenuInputs)
        ); //returns only valid inputs
    if (cMainMenuChoice == 'G') {
        do {
           startGame();
           printf("Play again?");
           char cLoopInputs[2] = {'Y','N'};
           cLoopPrompt = handleInput(
               cLoopInputs, ARRAY_SIZE(cLoopInputs)
               );
        } while (cLoopPrompt == 'Y');
    }
    return 0;
}
