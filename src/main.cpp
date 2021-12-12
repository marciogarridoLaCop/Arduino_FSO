#include <Thermistor3.h>

// begin object Thermistor in pin 0
Thermistor temp1(7);
Thermistor temp2(6);

// value of resistor in ohms
double resistor = 9700;

int readvalue = 0; // Ler valor porta
float volts = 0;


// number of samples
int sample = 1;

void setup()
{
  Serial.begin(2000000);
}

void loop()
{
  readvalue = analogRead(0); 
  Serial.print(readvalue * (5.0 / 1023.0);, 2);
  Serial.print(" ");

  readvalue = analogRead(1);
  Serial.print(readvalue * (5.0 / 1023.0);, 2);
  Serial.print(" ");

  readvalue = analogRead(2);
  Serial.print(readvalue * (5.0 / 1023.0);, 2);
  Serial.print(" ");

  readvalue = analogRead(3);
  Serial.print(readvalue * (5.0 / 1023.0);, 2);
  Serial.print(" ");
 
  Serial.print(temp1.getTemp(resistor);, 0);
  Serial.print(" ");
  Serial.print(temp2.getTemp(resistor);, 0);
  Serial.println();
}