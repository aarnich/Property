# Macihne Project Algorithm

### Tracker:
january 1: 60% done with UI handlers

### Entities
1. (2) Players.
2. (1) Dice.
3. (1) Board.
4. (9) Properties

### Position Types
* 0 Go 
* 1 Property
* 2 Electric Company 
* 3 Property
* 4 Jail Time 
* 5 Property
* 6 Feelin' Lucky 
* 7 Railroad
* 8 Property
* 9 Property

### Property Actions

if diceroller lands on unowned property:
  diceroller is given the choice to buy

if diceroller lands on property owned by the other player:
  diceroller pays rent

if diceroller lands on property owned by diceroller:

  if property is renovated:
    diceroller action = skip

  if property is not renovated:
    diceroller is given the choice to renovate

if diceroller lands on !property OR diceroller lands on renovated property owned by diceroller:
  diceroller action = skip

### Misc actions

if diceroller lands on 4 (Jail Time):
  diceroller action = skip
  diceroller nextaction = skip

if diceroller lands on 0 (Go):
  diceroller gains 200 currencies

if diceroller lands on 6 (Feelin' Lucky):
  diceroller.luck = RolleDice():
  if diceroller.luck IS A PRIME:
    diceroller gains currency rand(100,200);
  if diceroller.luck == 1
    diceroller next action = skip
else:
    diceroller loses currency rand(50,150);

### State Key

#### the state key is a 9 digit integer used to track properties on the board

ex. 012345678

the leftmost digit is the 9th property
the rightmost digit is the first property

### implement statekey manipulation methods
(Done)
### implement statekey access methods
(Todo)

#### Statekey Access Methods

### MUST DO
CREATE GAME STATE STRUCT
properties:
1. currentNodeOwner
2.  
### create game state handler function

readStateKeyAtIndex(statekey, index)
{
  ### index decides the position of the digit to be accessed
  within the statekey
  index -= 1;
  if(index < 0){
      print (invalid index)
    }
  ### remove unnecessary digits
  int modifiedStatekey = statekey/10^index
  ### return the last digit of the modifiedStatekey
  return modifiedStatekey mod 10;
}

evaluateStatekey(statekey, index)
{
  switch index:
    case 1:
}
evaluateProperty(digit)
{
  if digit mod 2 == 0
  
}











### PROGRAM LOOP
#define ARRAY_SIZE(arr) (sizeof arr) / sizeof arr[01]
#define initPos  0;   
#define DEFAULT_STARTING_BALANCE  0;
#define DEFAULT_WINNING_BALANCE 200000;
void showSettingsSubMenu(){
    printf("[1] Starting Balance\n");
    printf("[2] Winning Balance\n");
    printf("[3] Start Game\n")
  }
void changeStartingBalancePrompt(float* startingBalancePtr){
    printf("\n Enter Starting Balance \n");
    float fInputBal = 0;
    scanf("%f",&startingBalance);
    *startingBalance = fInputBalance;
  }
void changeWinningBalancePrompt(float* winnningBalancePtr){
    printf("\n Enter Winning Balance \n");
    scanf("%f",&winningBalance);
  }
void showBackPrompt(int (*ptr)()){
    printf("[B] Back"\n);

  }
void showSettingsScreen(float* startingBalance, float* winningBalance){
  printf("Change settings")
  char cChoice = handleInput(['Y','N']);
  if(cChoice == 'Y'){}
      do
      {
          int start = 0;
          showSettingsSubMenu();
          char cChoice = handleInput({'1','2','3'});
          switch(cChoice){
              case '1':
                changeStartingBalnacePrompt(&startingBalance);
                break;
              case '2':
                changeWinningBalancePrompt(&winningBalance);
                break;
              case '3':
                start = 1;
                break;
              default:
                showSettingsScreen();
                break;
            }
        }while(start != 1);
    }
}
Player createPlayer(float startingBalance, char* name, int position){
  Player player;
  player.name = name;
  player.fBalance = startingBalance;
  player.nPosition = position;
  return player;
  }
gameState initGameState(){
    gameState game;
    game.stateKey = 999999999;
    game.activePlayer = 0;
    return game;
  }
void startGame(float initialBalance, float winningBalance){
  float startingBalance = initialBalance;
  float winningBalance = winningBalance;
  float* ptrInitialBalance = &initialBalance;
  float* ptrWinningBalance = &winningBalance;
  showSettingsScreen(ptrInitalBalance,ptrWinningBalance);
  char* plName, p2Name;
  printf("Enter player 1 name");
  scanf("%s",&p1Name);
  printf("Enter player 2 name");
  scanf("%s",&p2Name);
  Player player1, player2;

  player1 = createPlayer(startingBalance, p1Name, initPos);
  player2 = createPlayer(startingBalance, p2Name, initPos);

  showWelcomeMessage();
  clearScreen();
  showRules();
  gameState status = initGameState();
  status.activePlayer = randomizeStartingPlayer(); 
  do{
      status = gameLoop(status, player1, player2);
    }
  while(getHighestBalance(float p1Balance, float p2Balance) < winningBalance);
}
Player gameLoop(gameState status, Player player1, Player player2){
      1. active player rolls dice
      2. evaluate result
      3. update gameState
      4. change active player
}

randomizeStartingPlayer(player1.name, player2.name){
      clearScreen();
      diceAnimation();
      char* startingPlayer = " ";
      int activePlayer = 0;
      if(rand() % 2 + 1 == 1){
        activePlayer = 1;
        startingPlayer = player1.name;
        }
      else{
        activePlayer = 2;
        startingPlayer = player2.name;
        }
      printf("%s, will roll the dice first!", startingPlayer);
      return activePlayer;
    }
typedef struct Player{
    int nPosition;
    char* name;
    float fBalance;
  };

typedef struct gameState{
    int stateKey;
    int activePlayer;
  };
int main(){
    displayGreeting();
    do
    {
    displayMain();//two button menu, start, exit
    char cChoice = handleInput(['G','E']);//takes the input of the user controlling the menu
    char cLoopPrompt = 'N';
    if(cChoice == 'G'){
      do{
          startGame(DEFAULT_STARTING_BALANCE,DEFAULT_WINNING_BALANCE);
          printf("Play Again?");
          cLoopPrompt = handleInput(['Y','N']);
        }
        while(cLoopPrompt == 'Y');

      displayWinningMessage(Player Winner);
      }
  }
  displayExitMessage():
}

