#include "LED_API.h"

/*
function    LED_SetRatio16
brief:      This function wraps RED_LED_SetRatio16, GREEN_LED_SetRatio16, BLUE_LED_SetRatio16 to make it easier to call.
param:      unsigned short, unsigned short, unsigned short
return:     void
*/
void LED_SetRatio16(unsigned short RED_LED_Ratio, unsigned short GREEN_LED_Ratio, unsigned short BLUE_LED_Ratio)
{
  RED_LED_SetRatio16(RED_LED_DeviceData, RED_LED_Ratio);
  GREEN_LED_SetRatio16(GREEN_LED_DeviceData, GREEN_LED_Ratio);
  BLUE_LED_SetRatio16(BLUE_LED_DeviceData, BLUE_LED_Ratio);
}

/*
function    LED_SetRatio8
brief:      This function uses the more common 8bit RGB Code to control the LEDs. e.g. LED_SetRatio8(256, 256, 0)
param:      unsigned short, unsigned short, unsigned short
return:     void
*/
void LED_SetRatio8(unsigned short RED_LED_Ratio, unsigned short GREEN_LED_Ratio, unsigned short BLUE_LED_Ratio)
{
  LED_SetRatio16(RED_LED_Ratio * 257, GREEN_LED_Ratio * 257, BLUE_LED_Ratio * 257);
}

/*
function    LED_Fade
brief:      This function will control the LED to display a fade colour. The time required for the fade is controlled by Fade_Time_1MS.
brief:      Specific use cases can be found in LED_Welcome() and LED_Victory().
param:      unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, float
return:     void
*/
void LED_Fade(unsigned short RED_Before, unsigned short GREEN_Before, unsigned short BLUE_Before, unsigned short RED_After, unsigned short GREEN_After, unsigned short BLUE_After, float Fade_Time_1MS)
{

  int count = 0;
  float RED_Interval = (RED_After - RED_Before) / Fade_Time_1MS;
  float BLUE_Interval = (BLUE_After - BLUE_Before) / Fade_Time_1MS;
  float GREEN_Interval = (GREEN_After - GREEN_Before) / Fade_Time_1MS;
  LED_SetRatio8(RED_Before, GREEN_Before, BLUE_Before);
  for (count = 0; count < Fade_Time_1MS; count++)
  {
    LED_SetRatio8(RED_Before + RED_Interval * count, GREEN_Before + GREEN_Interval * count, BLUE_Before + BLUE_Interval * count);
    Delay(1);
  }
}

/*
function    LED_Welcome
brief:      A fade light in purple indicates the start of a game.
brief:      Selected colour #D100F5 -> #6500FF -> #000BE6 -> #0D81FC -> 0CE3F5 -> #D100F5
param:      void
return:     void
*/
void LED_Welcome()
{
  int count = 0;
  for (count = 0; count < 1; count++)
  {
    LED_Fade(0xD1, 0x00, 0xF5, 0x65, 0x00, 0xFF, 500);
    LED_Fade(0x65, 0x00, 0xFF, 0x00, 0x0B, 0xE6, 500);
    LED_Fade(0x00, 0x0B, 0xE6, 0x0D, 0x81, 0xFC, 500);
    LED_Fade(0x0D, 0x81, 0xFC, 0x0C, 0xE3, 0xF5, 500);
    LED_Fade(0x0C, 0xE3, 0xF5, 0xD1, 0x00, 0xF5, 900);
  }
}

/*
function    LED_GameStart
brief:      This function is used to prompt the player for the start of a round of play.
brief:      white -> white -> white
param:      void
return:     void
*/
void LED_GameStart()
{
  LED_SetRatio16(0x0000, 0x0000, 0x0000);
  Delay(220);
  LED_SetRatio16(0xDDDD, 0xDDDD, 0xDDDD);
  Delay(220);
  LED_SetRatio16(0x0000, 0x0000, 0x0000);
  Delay(220);
  LED_SetRatio16(0xDDDD, 0xDDDD, 0xDDDD);
  Delay(220);
  LED_SetRatio16(0x0000, 0x0000, 0x0000);
  Delay(220);
  LED_SetRatio16(0xDDDD, 0xDDDD, 0xDDDD);
  Delay(1100);
  LED_SetRatio16(0x0000, 0x0000, 0x0000);
  Delay(1100);
}

/*
function    LED_Victory
brief:      The function will activate a green fade light to indicate a match win.
brief:      #00D891 -> #06D13E -> #0FEB07 -> #59D404 -> #9BFA00 -> #00D891
param:      void
return:     void
*/
void LED_Victory()
{
  int count = 0;
  for (count = 0; count < 5; count++)
  {
    LED_Fade(0x00, 0xD8, 0x91, 0x06, 0xD1, 0x3E, 200);
    LED_Fade(0x06, 0xD1, 0x3E, 0x0F, 0xEB, 0x07, 200);
    LED_Fade(0x0F, 0xEB, 0x07, 0x59, 0xD4, 0x04, 200);
    LED_Fade(0x59, 0xD4, 0x04, 0x9B, 0xFA, 0x00, 200);
    LED_Fade(0x9B, 0xFA, 0x00, 0x00, 0xD8, 0x91, 500);
  }
  LED_Fade(0x00, 0xD8, 0x91, 0x00, 0x00, 0x00, 500);
  Delay(2000);
}

/*
function    LED_Lose
brief:      This function will activate the LED to flash in orange.
param:      void
return:     void
*/
void LED_Lose()
{
  int count = 0;
  for (count = 0; count < 6; count++)
  {
    LED_SetRatio8(0xFF, 0x46, 0x00);
    Delay(100);
    LED_SetRatio8(0x00, 0x00, 0x00);
    Delay(100);
  }
  Delay(2000);
}