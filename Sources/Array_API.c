#include "Array_API.h"

/*
function    Array_Generate
brief:      Generate the array required for the Simon game. The msTicks passed into the function are used as seeds to generate a "true" random array of length arrayLength.
param:      int [], int
return:     void
*/
void Array_Generate(int array[], int seed)
{
  srand(seed); // When the function Array_Generate is called, the values of msTicks are all different, because the player's operation time is random.
  int count = 0;
  for (count = 0; count < MAX_LEVEL; count++)
  {
    array[count] = rand() % 3 + 1; // In the array 0 means undefined, 1 means red, 2 means green, 3 means blue.
  }
}

/*
function    Array_Display
brief:      This function takes the sequence stored in the array and displays it to the player using LEDs.
param:      int [], int
return:     void
*/
void Array_Display(int array[], int arrayLength)
{
  int count = 0;
  for (count = 0; count < arrayLength; count++)
  {
    switch (array[count])
    {
    case 1:
      LED_SetRatio16(0xFFFF, 0x0000, 0x0000); // Red
      break;
    case 2:
      LED_SetRatio16(0x0000, 0xFFFF, 0x0000); // Green
      break;
    case 3:
      LED_SetRatio16(0x0000, 0x0000, 0xFFFF); // Blue
    default:
      break;
    }
    Delay(400);
    LED_SetRatio16(0x0000, 0x0000, 0x0000);
    Delay(400);
  }
}

/*
function    Array_Input
brief:      Takes "arrayLength" inputs from the player and stores the data in "array[]".
param:      int [], int
return:     void
*/
void Array_Input(int array[], int arrayLength)
{
  int count = 0;
  for (count = 0; count < arrayLength; count++)
  {
    TSS1_Monitor();
    if (TSS1_cKey0.Position != 0)
    {
      if (TSS1_cKey0.Position < TSS1_LEFT_BOUNDARY)
      {
        LED_SetRatio16(0xFFFF, 0x0000, 0x0000); // Prompt the player for the colour he has inputed.
        Delay(400);
        LED_SetRatio16(0x0000, 0x0000, 0x0000);
        array[count] = 1;
      }
      else if (TSS1_cKey0.Position < TSS1_RIGHT_BOUNDARY && TSS1_cKey0.Position > TSS1_LEFT_BOUNDARY)
      {
        LED_SetRatio16(0x0000, 0xFFFF, 0x0000);
        Delay(400);
        LED_SetRatio16(0x0000, 0x0000, 0x0000);
        array[count] = 2;
      }
      else if (TSS1_cKey0.Position > TSS1_RIGHT_BOUNDARY)
      {
        LED_SetRatio16(0x0000, 0x0000, 0xFFFF);
        Delay(400);
        LED_SetRatio16(0x0000, 0x0000, 0x0000);
        array[count] = 3;
      }
    }
  }
}

/*
function    Array_Compare
brief:      Based on the two input arrays, compare the elements of the arrays to see if they are the same, and return True when the elements are the same, or return if they are not.
param:      int [], int []
return:     bool
*/
bool Array_Compare(int arrayA[], int arrayB[])
{
  bool arraysEqual = true; // Flag variables
  int count = 0;           // Loop control variables

  do
  {
    if (arrayA[count] != arrayB[count])
    {
      arraysEqual = false;
      break;
    }
    count++;
  } while (arrayB[count] != 0 && (count < MAX_LEVEL));

  if (arraysEqual == true)
    return true;
  else
    return false;
}

/*
function    Array_Reset
brief:      Set the elements in the array to 0
param:      int []
return:     void
*/
void Array_Reset(int array[])
{
  int count = 0;
  for (count = 0; count < MAX_LEVEL; count++)
  {
    array[count] = 0;
  }
}