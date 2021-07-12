#include <Arduino.h>
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1X15 ads;
double vx,kx,k2x=0; //
const float mx = 0.1875F;

// declaração das variáveis de entrada analogicas
int16_t adc0, adc1, adc2, adc3;


float lerphoto1()
{
  kx = pow(10, 3);   //  constante para ajustar casa decimal da conversão Digital / Analogica ADS1115
  k2x = pow(10, -3); //  constante para ajustar casa decimal da conversão Digital / Analogica Arduino
  ads.begin();
  adc0 = ads.readADC_SingleEnded(0);
  vx = (adc0 * mx);
  //  analogRead(analogPin1);  // leitura da porta A0
   vx=vx/kx; // Convert D/A
  if (vx > 5)
    vx = 0;
  return vx;
}