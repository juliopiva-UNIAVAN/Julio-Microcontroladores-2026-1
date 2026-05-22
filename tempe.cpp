/*
**************************
* @file    sensortemp.cpp
* @brief   Estrutura do sensor TMP36.
**************************
* Date:     21/05/2026
* Author:   Julio Cesar Piva
* email:    juliopiva11@gmail.com
* Project:  Atividade1_6sensores
* Version:  1.0
**************************
*/

#include "sensor.h"
  
float lerTemperatura(struct sensortemp *sensor)
{
    int leitura;

    leitura = analogRead(sensor->valorsensor);

    sensor->vsensor = leitura * (5.0 / 1023.0);

    sensor->temp = (sensor->vsensor - 0.5) * 100.0;

    return sensor->temp;
}