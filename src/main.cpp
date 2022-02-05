#include <Thermistor3.h>

// begin object Thermistor in pin 0
Thermistor temp1(7);
Thermistor temp2(6);

// value of resistor in ohms
double resistor = 10000;

int readvalue = 0; // Ler valor porta
float volts = 0;


// number of samples
<<<<<<< HEAD
int sample = 1000;
=======
int sample = 1;
>>>>>>> 8b74db9f76ae5f8b4e4b665459b4416bb40a54cd

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
<<<<<<< HEAD

  average1 = average1 / sample;
  average2 = average2 / sample;
  Serial.print(average1, 1);
  Serial.print(" ");
  Serial.print(average2, 1);
=======
 
  Serial.print(temp1.getTemp(resistor);, 0);
  Serial.print(" ");
  Serial.print(temp2.getTemp(resistor);, 0);
>>>>>>> 8b74db9f76ae5f8b4e4b665459b4416bb40a54cd
  Serial.println();
}