// This is a library of functions used for numerical operations
// Written by: Aaron Gumapac
#include "numericalOperations.h"
int checkIfInRange(int num, int min, int max){
    if(num <= max && num >= min)
        return 1;
    
    return 0;
}
