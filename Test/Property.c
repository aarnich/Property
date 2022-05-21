#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Player{
    int nPosition;
    float fBalance;
};
int rollDice(int lowerBound, int upperBound){
    int nRollRange = (upperBound - lowerBound) + 1;
    int nRandomRoll = rand() % nRollRange + lowerBound;
    return nRandomRoll;
}
int exponentiateNum(int base, int power){
    int nExponentiatedNum = 1;
    if (power == 0)
    {
        return nExponentiatedNum;
    }
    
    for (size_t i = power; i > 0; i--)
    {
        nExponentiatedNum *= base;
    }
    return nExponentiatedNum;
}
int getDigitAtIndex(int numToParse, int index){ //index starts at 0 and is ordered from right to left
    int nDivisor = exponentiateNum(10,index);
    int nNormalizedNum = numToParse/nDivisor;

    return nNormalizedNum % 10;
}
int normalizeNumByIndex(int numToParse, int index){ //index starts at 0 and is ordered from right to left
    int nReducedNum = numToParse / exponentiateNum(10,index);
    int nExpandedNum = nReducedNum * exponentiateNum(10,index);
    return nExpandedNum;
}
int getHighestBalance(struct Player Player1, struct Player Player2){
    return Player1.fCashOnHand * (Player1.fCashOnHand > Player2.fCashOnHand)
    printf("Players possess the same amount of money\n");
    return 0;
}
/*

the paramater stateKey refers to the 9-digit binary string used to track property states
the paramter digitToPass refers to the integer meant to replace the digit at the given index
the parameter indexOfDigit refers to the index of the digit to be replaced going from right to left, eg. the rightmost digit is the 0th digit.

*/
int mutateStateKeyDigit(int stateKey, int digitToPass, int indexOfDigit){   
/*
    if (digitToPass > 9)
    {
       printf("Insertion of digits greater than or equal to 10 is not allowed\nInput has been normalized automatically : %d/10\n", digitToPass);
       digitToPass /= 10;
    }
    normalize inputs greater than 9 by their ones digit;
 */   
    int normalizedNum = normalizeNumByIndex(stateKey, indexOfDigit+1);
    int numToInsert = digitToPass * exponentiateNum(10,indexOfDigit);
    int nTrailingDigits = stateKey % exponentiateNum(10,indexOfDigit);
    int mutatedStateKey = normalizedNum + numToInsert + nTrailingDigits;
    return mutatedStateKey;
}
// assign states to 9 digit interger
/*
int stateMachine(int stateKey){
    return 0;
}
*/
void gameLoop(struct Player Player1, struct Player Player2, float winningAmount){
    float fHighestBalance = 0; //init highest balance
    do
    {
        float fHighestBalance = getHighestBalance(Player1, Player2);
        /* code */
    } while (fHighestBalance < winningAmount);
}
int main(int argc, char const *argv[])
{
    int nStateKey = 999999999; //Initialize StateKey
    srand(time(0));
    return 0;
}