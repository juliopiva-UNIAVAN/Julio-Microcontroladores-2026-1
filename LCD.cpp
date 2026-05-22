/*
**************************
* @file    display_lcd.cpp
* @brief   LCD - Incializa o LCD
**************************
* Date:     21/05/2026
* Author:   Julio Cesar Piva
* email:    juliopiva11@gmail.com
* Project:  Atividade1_6sensores
* Version:  1.0
**************************
*/

#include "display_lcd.h"

void initLCD(LiquidCrystal_I2C *lcd)
{
    if (lcd != NULL)
    {
        lcd->init();
        lcd->backlight();
    }
}