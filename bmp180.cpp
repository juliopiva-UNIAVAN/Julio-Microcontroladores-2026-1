/*
**************************
* @file    sensor_bmp180.cpp
* @brief   Funções de leitura BMP180.
**************************
* Date:     21/05/2026
* Author:   Julio Cesar Piva
* email:    juliopiva11@gmail.com
* Project:  Atividade1_6sensores
* Version:  1.0
**************************
*/

#include "sensor_bmp180.h"

float lerBMPTemperatura(Adafruit_BMP085 *bmpDevice)
{
    return bmpDevice->readTemperature();
}

float lerBMPPressao(Adafruit_BMP085 *bmpDevice)
{
    return bmpDevice->readPressure() / 100.0;
}