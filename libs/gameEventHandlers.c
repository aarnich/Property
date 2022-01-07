#define DEFAULT_STARTING_BALANCE 0
#define DEFAULT_STATEKEY 999999999
#define DEFAULT_RAILROAD_RENT 35
#define DEFAULT_ELECTRIC_MULTI 8
#define DEFAULT_RENOVATION_COST 50
#define DEFAULT_LUCKY_PRIME_MAX 100
#define DEFAULT_LUCKY_PRIME_MIN 200
#define DEFAULT_LUCKY_NONPRIME_MIN 50
#define DEFAULT_LUCKY_NONPRIME_MAX 150
#include <stdbool.h>
#include <stdio.h>
#include "inputHelpers.c"
typedef struct Player{
    int nPosition;
    int nBalance;
    int nLuck;
    char* name;
};
typedef struct range{
    int max;
    int min;
};
typedef struct gameState{
    int nStateKey;
    int activePlayer;
    int nRailRoadRent;
    int nElectricCompanyMultiplier;
    int nRenovationCost;
    struct range primeRange;
    struct range nonPrimeRange;
    bool bSimultaneousWinConditions;
};
char* fetchPlayerName(){
    printf("Enter name:");
    char* name;
    scanf("%s",&name);
    if(name == NULL || name == ' '){
        printf("invalid name\n");
        return fetchPlayerName();
    }
    return name;
}
void displayWelcomeMessage(){
    printf("Welcome to Property!\n");
}
void showRules(){
    printf("Rules");
}
struct gameState initializeGameState(){
    struct gameState initGame;
    initGame.activePlayer = 0;
    initGame.bSimultaneousWinConditions = 0;
    initGame.nElectricCompanyMultiplier = DEFAULT_ELECTRIC_MULTI;
    initGame.nonPrimeRange.min = DEFAULT_LUCKY_NONPRIME_MIN;
    initGame.nonPrimeRange.max = DEFAULT_LUCKY_NONPRIME_MAX;
    initGame.primeRange.min = DEFAULT_LUCKY_PRIME_MIN;
    initGame.primeRange.max = DEFAULT_LUCKY_PRIME_MAX;
    initGame.nRenovationCost = DEFAULT_RENOVATION_COST;
    initGame.nRailRoadRent = DEFAULT_RAILROAD_RENT;
    initGame.nStateKey = DEFAULT_STATEKEY;
    return initGame;
}
struct gameState settingsPrompt(struct gameState initialState){
    printf("[W] Edit Feelin' Lucky's Range");
    printf("[A] Edit Renovation Cost");
    printf("[S] Edit Railroad Rent");
    printf("[D] Edit The Electric Company's Multiplier");
    char validSettingsInput[4] = {'W','A','S','D'};
    char cSettingsSelect = handleInput(validSettingsInput,4);
    switch(cSettingsSelect){
        case A:

    }
}
void feelingLuckySubMenu(int* nonPrimeMax, int* nonPrimeMin, int* PrimeMax, int* PrimeMin){
    printf("[W] Edit Non Prime Range");
    printf("[S] Edit Prime Range");
    char subMenuInput[2] = {'W','S'};
    char cSettingsSelect = handleInput(subMenuInput,2);
    switch(cSettingsSelect){
        case W:

        case S:

    }
}
void nonPrimeMenu(int* nonPrimeMax, int* nonPrimeMin){
    printf("[W] Edit Non Prime Max");
    printf("[S] Edit Non Prime Min");
    char subMenuInput[2] = {'W','S'};
    char cSettingsSelect = handleInput(subMenuInput,2);
    switch(cSettingsSelect){
        case W:
            printf("Enter Non Prime Maximum Value:");
        case S:

    }
}
struct Player startGame(){ 
    displayWelcomeMessage();
    showRules();
    struct gameState status = initializeGameState();

}
