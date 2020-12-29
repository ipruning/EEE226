#include "GREEN_LED.h"
#include "BLUE_LED.h"
#include "RED_LED.h"
#include "TU1.h"
#include "TSS1.h"
#include "System_API.h"
#include "My_Define.h"

void LED_SetRatio16(unsigned short RED_LED_Ratio, unsigned short GREEN_LED_Ratio, unsigned short BLUE_LED_Ratio);
void LED_SetRatio8(unsigned short RED_LED_Ratio, unsigned short GREEN_LED_Ratio, unsigned short BLUE_LED_Ratio);
void LED_Fade(unsigned short RED_Before, unsigned short GREEN_Before, unsigned short BLUE_Before, unsigned short RED_After, unsigned short GREEN_After, unsigned short BLUE_After, float Fade_Time_1MS);
void LED_Welcome();
void LED_GameStart();
void LED_Victory();
void LED_Lose();