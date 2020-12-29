#include "System_API.h"

/*
function    Delay
brief:      Create a delay of dlyTicks milliseconds according to the parameters passed in.
param:      uint32_t
return:     void
*/
void Delay(uint32_t dlyTicks)
{
  uint32_t curTicks;
  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks)
    ;
}

/*
function    TSS1_Monitor
brief:      Jumps out of the loop after the touchpad has at least one input.
param:      void
return:     void
*/
void TSS1_Monitor()
{
  TSS1_Configure();
  ispressed = 0;
  while (ispressed < 2)
  {
    TSS_Task();
  }
}