/*
**************************
* @file    sensortemp.h
* @brief   Estrutura do sensor TMP36.
**************************
* Date:     21/05/2026
* Author:   Julio Cesar Piva
* email:    juliopiva11@gmail.com
* Project:  Atividade1_6sensores
* Version:  1.0
**************************
*/

#include <Arduino.h>

struct sensortemp
{
    int valorsensor;

    float vsensor;
    float temp;
};
/*
**********************
* @name  lerTemperatura
* @brief Esta função deve ser chamada cada vez que for necessário ler o sensor TMP36
*
*********************
* @input:   *sensor         - ponteiro para variável da struct sensorTemp
*           
* @return:  temp            - Temperatura em graus celsius 
*/
float lerTemperatura(struct sensortemp *sensor);