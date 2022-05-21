#include <stdio.h>

// This function handles contextual input for the UI

void diceRollMenu() { printf("Roll dice\n"); }

int checkIfRollerOwnsProperty(int player, int property) {
  int nOwnershipStatus;
  if (property == 0)
    return 0;
  if (player % 2 == property % 2)
    return 1;
  return 0;
}

int readStatekeyDigit(int index, int stateKey);

int buyPropertyPrompt(int playerNum) {
  char cSelection = ' ';
  scanf("%c", &cSelection);
  int nPropertyValue;
  switch (cSelection) {
  case 'Y':
  case 'y':
    if (playerNum == 1)
      nPropertyValue = 1;
    else
      nPropertyValue = 2;
    break;
  case 'N':
  case 'n':
    nPropertyValue = 0;
    break;
  default:
    printf("Invalid Input\n");
    return buyPropertyPrompt(playerNum);
  }
  return nPropertyValue;
}

int renovatePropertPrompt(int playerNum) {
  char cSelection = ' ';
  scanf("%c", &cSelection);
  int nRenovationValue;
  switch (cSelection) {
  case 'Y':
  case 'y':
    if (playerNum == 1)
      nRenovationValue = 3;
    else
      nRenovationValue = 4;
    ;
    break;
  case 'N':
  case 'n':
    nRenovationValue = 0;
    break;
  default:
    printf("Invalid Input\n");
    return buyPropertyPrompt(playerNum);
  }
  return nRenovationValue;
}

int forAddNum(int num) {
  for (; num > 100; num += num) {
    printf("%d", num);
  }
  return num;
}

// after a dice roll, show context menu

int propertyContextMenu(int propertyIndex, int playerNum, int stateKey) {
  int propertyStatus = readStatekeyDigit(propertyIndex, stateKey);
  int nPropertyValue = 0;
  switch (propertyStatus) {
  case 0:
    printf("Buy property?\n");
    nPropertyValue = buyPropertyPrompt(playerNum);
    break;
  case 1:
  case 2:
    if (playerNum == propertyStatus) { // check if current player owns property
      printf("Renovate property?\n");
      nPropertyValue = renovatePropertPrompt(playerNum);
    } else
      printf("You paid rent\n");
    break;
  case 3:
  case 4:
    if (playerNum % 2 ==
        propertyStatus % 2) // check if current player owns renovated property
      printf("You did nothing, you own this renovated property\n");
    else
      printf("You paid rent\n");
    break;
  default:
    printf("invalid\n");
    break;
  }
  return nPropertyValue;
}

int modifyStateKey(int stateKey, int index, int value);

int propertyInputHandler(int stateKey, int value, int propertyIndex) {
  return modifyStateKey(stateKey, propertyIndex, value);
}
