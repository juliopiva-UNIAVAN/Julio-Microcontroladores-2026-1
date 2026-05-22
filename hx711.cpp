/*
**************************
* @file    sensor_hx711.cpp
* @brief   Processamento e conversão dos dados brutos do ADC de 24-bits.
**************************
* Date:     21/05/2026
* Author:   Julio Cesar Piva
* email:    juliopiva11@gmail.com
* Project:  Atividade1_6sensores
* Version:  1.0
**************************
*/

#include "sensor_hx711.h"

float lerPeso(HX711 *scaleDevice, struct ConfigHX711 *config)
{
    long raw = scaleDevice->read_average(10);
    return (raw - config->rawZero) * config->ganhoHX;
}