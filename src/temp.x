/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE TEMERATURA
*/
#include <Thermistor.h>

Thermistor temp1(4); // Which port the Thermistor is connected
Thermistor temp2(5); // Which port the Thermistor is connected


float temperature_base()
{
    int temperature_base = temp.getTemp(); 
    return temperature;
}

float temperature_top()
{
    int temperature_top = temp.getTemp(); 
    return temperature;
}