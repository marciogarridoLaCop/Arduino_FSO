
/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE LEITURA 16 BITS
RESOLUCAO DE 5 VOLTS / 1024 UNIDADES.
0,0049 VOLTS
*/

#include <Arduino.h>
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1X15 ads;
double vx,kx=0; //
const float mx = 0.1875F;
int16_t adc0;


float lerphoto(int porta)
{
  kx = pow(10, 3);   //  constante para ajustar casa decimal da conversão Digital / Analogica ADS1115
  ads.begin();
  adc0 = ads.readADC_SingleEnded(porta);
  vx = (adc0 * mx);
  vx=vx/kx; // Convert D/A
  if (vx > 5)
    vx = 0;
  return vx;
}