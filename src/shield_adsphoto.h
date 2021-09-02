/* 

#include <Arduino.h>
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1X15 ads;
double vx,kx=0; //
const float mx = 0.1875F;

// declaração das variáveis de entrada analogicas
int16_t adc0;
 
 
float lerphoto(int porta)
 {
   kx = pow(10, 3);   //  constante para ajustar casa decimal da conversão Digital / Analogica ADS1115
   ads.begin();
   adc0 = ads.readADC_SingleEnded(porta);
   vx = (adc0 * mx);
  //  analogRead(analogPin1);  // leitura da porta A0
  vx=vx/kx; // Convert D/A
   if (vx > 5)
     vx = 0;
   return vx;
 }
 */