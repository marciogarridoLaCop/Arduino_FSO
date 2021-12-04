#include <Thermistor3.h>

// begin object Thermistor in pin 0
Thermistor temp1(7);
Thermistor temp2(6);

// value of resistor in ohms
double resistor = 10000;

int readvalue, readvalue1, readvalue2, readvalue3, readvalue4 = 0; // Ler valor porta
float volts = 0;

// variable to store the average of read
double average1 = 0;
double average2 = 0;

// number of samples
int sample = 1000;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  // Read the data and plus to variable average
  for (int index = 0; index < sample; index++)
  {
    double temperature1 = temp1.getTemp(resistor);
    double temperature2 = temp2.getTemp(resistor);
    average1 += temperature1;
    average2 += temperature2;
    delayMicroseconds(1);
  }

  readvalue = analogRead(0);
  volts = readvalue * (5.0 / 1023.0);
  Serial.print(volts, 2);
  Serial.print(" ");

  readvalue = analogRead(1);
  volts = readvalue * (5.0 / 1023.0);
  Serial.print(volts, 2);
  Serial.print(" ");

  readvalue = analogRead(2);
  volts = readvalue * (5.0 / 1023.0);
  Serial.print(volts, 2);
  Serial.print(" ");

  readvalue = analogRead(3);
  volts = readvalue * (5.0 / 1023.0);
  Serial.print(volts, 2);
  Serial.print(" ");

  average1 = average1 / sample;
  average2 = average2 / sample;
  Serial.print(average1, 1);
  Serial.print(" ");
  Serial.print(average2, 1);
  Serial.println();

  delay(10);
}