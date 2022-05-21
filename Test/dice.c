#include <math.h>
int rollDice(int lowerBound, int upperBound) {
  int nRollRange = (upperBound - lowerBound) + 1;
  int nRandomRoll = rand() % nRollRange + lowerBound;
  return nRandomRoll;
}
