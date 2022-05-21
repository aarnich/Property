/* header file for gameEventHandlers.c */
#include "UIHelpers.h"
#include <stdbool.h>
typedef struct Player{
    int nPosition;
    int nBalance;
    int nLuck;
    char* name;
}Player;
typedef struct range{
    int max;
    int min;
}range;
typedef struct gameState{
    int nStateKey;
    int activePlayer;
    int nRailRoadRent;
    int nElectricCompanyMultiplier;
    int nRenovationCost;
    struct range primeRange;
    struct range nonPrimeRange;
    bool bSimultaneousWinConditions;
}gameState;
extern char* fetchPlayerName();
extern struct gameState initializeGameState();
extern struct gameState settingsPrompt(struct gameState initialState);
extern void changeParam(int* parameterPtr, char* stringMsg);
extern void feelingLuckySubMenu(
    int* nonPrimeMax,
    int* nonPrimeMin, 
    int* primeMax, 
    int* primeMin, 
    methodPtr settingsMenu);
extern void nonPrimeMenu(
    int* nonPrimeMax, 
    int* nonPrimeMin, 
    methodPtr feelingLuckyMenu);
extern void nonPrimeMenu(
    int* nonPrimeMax, 
    int* nonPrimeMin, 
    methodPtr feelingLuckyMenu);
extern void primeMenu(
    int* primeMax, 
    int* primeMin, 
    methodPtr superMenu);