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
#include <gameEventHandlers.h>
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
    methodPtr ptrSettingsPrompt = &settingsPrompt;
    struct gameState localizedInitialState = initialState;
    printf("[W] Edit Feelin' Lucky's Range");
    printf("[A] Edit Renovation Cost");
    printf("[S] Edit Railroad Rent");
    printf("[D] Edit The Electric Company's Multiplier");
    char validSettingsInput[4] = {'W','A','S','D'};
    char cSettingsSelect = handleInput(validSettingsInput,4);
    switch(cSettingsSelect){
        case 'A':
            feelingLuckySubMenu(
                localizedInitialState.nonPrimeRange.max,
                localizedInitialState.nonPrimeRange.min,
                localizedInitialState.primeRange.max,
                localizedInitialState.primeRange.min,
                ptrSettingsPrompt
                );
            break;
    }
    return localizedInitialState;
}
void changeParam(int* parameterPtr, char* stringMsg){
    int init;
    printf("%s", stringMsg);
    scanf("%d",&init);
    parameterPtr = init;
}
void feelingLuckySubMenu(int* nonPrimeMax, int* nonPrimeMin, int* PrimeMax, int* PrimeMin, methodPtr settingsMenu){
    methodPtr ptrFeelingLuckyPrompt = &feelingLuckySubMenu;
    printf("[W] Edit Non Prime Range");
    printf("[S] Edit Prime Range");
    printf("[B] Go Back");
    char subMenuInput[3] = {'W','S','B'};
    char cSettingsSelect = handleInput(subMenuInput,3);
    switch(cSettingsSelect){
        case 'W':
            nonPrimeMenu(nonPrimeMax, nonPrimeMin, ptrFeelingLuckyPrompt);
            break;
        case 'S':
            primeMenu(PrimeMax, PrimeMin, ptrFeelingLuckyPrompt);
            break;
        case 'B':
        default:
            printf("Crtiical Error, called by: %s",__func__);
            break;
    }
}
void nonPrimeMenu(
    int* nonPrimeMax, 
    int* nonPrimeMin, 
    methodPtr feelingLuckyMenu)
    {
    printf("[W] Edit Non Prime Max\n");
    printf("[S] Edit Non Prime Min\n");
    printf("[B] Back\n");
    char subMenuInput[3] = {'W','S','B'};
    char cSettingsSelect = handleInput(subMenuInput,3);
    switch(cSettingsSelect){
        case 'W':
            changeParam(nonPrimeMax, "Enter New Max Value");
            nonPrimeMenu(nonPrimeMax, nonPrimeMin, feelingLuckyMenu);
            break;
        case 'S':
            changeParam(nonPrimeMin, "Enter New Min Value");
            nonPrimeMenu(nonPrimeMax, nonPrimeMin, feelingLuckyMenu);
            break;
        case 'B':
            goBack(feelingLuckyMenu);
            break;
        default:
            printf("Critical Error, called by: %s",__func__);
            break;
    }
}
void primeMenu(
    int* primeMax, 
    int* primeMin, 
    methodPtr superMenu) 
    {
    printf("[W] Edit Prime Max\n");
    printf("[S] Edit Prime Min\n");
    printf("[B] Back\n");
    char subMenuInput[2] = {'W','S'};
    char cSettingsSelect = handleInput(subMenuInput,2);
    switch(cSettingsSelect){
        case 'W':
            changeParam(primeMax, "Enter New Max Value");
            nonPrimeMenu(primeMax, primeMin, superMenu);
            break;
        case 'S':
            changeParam(primeMin, "Enter New Min Value");
            nonPrimeMenu(primeMax, primeMin, superMenu);
            break;      ;
        case 'B':
            goBack(superMenu);
            break;
        default:
            printf("Critical Error, called by: %s",__func__);
            break;
    }
}
struct Player startGame(){ 
    displayWelcomeMessage();
    showRules();
    struct gameState status = initializeGameState();
    status = settingsPrompt(status);
}
