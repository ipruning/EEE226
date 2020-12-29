#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "LED_API.h"
#include "System_API.h"
#include "My_Define.h"

void Array_Generate(int array[], int seed);
void Array_Display(int array[], int level);
void Array_Input(int array[], int arrayLength);
bool Array_Compare(int arrayA[], int arrayB[]);
void Array_Reset(int array[]);