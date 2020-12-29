/* ###################################################################
**     Filename    : main.c
**     Project     : Assignment_1
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-03-10, 12:51, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "RED_LED.h"
#include "TU1.h"
#include "GREEN_LED.h"
#include "BLUE_LED.h"
#include "TU2.h"
#include "TIMER_1MS.h"
#include "TU3.h"
#include "TSS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

/* Custom Functions */
#include "Array_API.h"
#include "LED_API.h"
/* msTicks is a global variable. It accumulates one per millisecond. */
uint32_t msTicks = 0;
/* ispressed is a global variable. It accumulates once when there is an input to the touchpad. */
int ispressed = 0;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /* Initialising arrays. At the end of the entire game. The array is reset using Array_Reset(). */
  /* MAX_LEVEL is defined in the header file My_Define.h. */
  /* In the array 0 and \0 means undefined. 1 means red, 2 means green, 3 means blue. */
  int array_simon[MAX_LEVEL] = {0};
  int array_input[MAX_LEVEL] = {0};
  /* The game will start at Level 1 and when the Level equals MAX_LEVEL, the player wins the game. */
  int level = 1;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  TSS1_Configure();
  /* For example: for(;;) { } */
  for (;;)
  {
    /* 1. Game initialisation */
    LED_Welcome();                        // Welcome players with a running light.
    TSS1_Monitor();                       // Wait for the player to touch the touch pad and start the game.
    Array_Generate(array_simon, msTicks); // Generate the Simon sequence to be used in this round of play.

    /* 2. Game start */
    do
    {
      /* 2.1 Flashing white LEDs alert the player that "this is a new level". */
      LED_GameStart();

      /* 2.2 Display the Simon sequence */
      Array_Display(array_simon, level);

      /* 2.3 Player input sequence */
      Array_Input(array_input, level);
      Delay(400);

      /* 2.4 The system checks that the two sequences are identical. */
      if (Array_Compare(array_simon, array_input) == false) // When two arrays do not match, break
      {
        break;
      }
      level++;                    // The difficulty level of the game has been increased by one level.
    } while (level <= MAX_LEVEL); // When the player has not cleared MAX_LEVEL, stay in the do while loop.

    /* 3. The system notifies the player if he have won the game. */
    if (level == MAX_LEVEL + 1) // Victory
    {
      LED_Victory();
    }
    else // Lose
    {
      LED_Lose();
    }

    /* 4. Preparing for the next game */
    level = 1;                // Reset level
    Array_Reset(array_simon); // Reset array
    Array_Reset(array_input); // Reset array
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
  PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for (;;)
  {
  }
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
