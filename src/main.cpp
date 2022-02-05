#include <Thermistor3.h>

// begin object Thermistor in pin 0
Thermistor temp1(7);
Thermistor temp2(6);
int hotwire_port = 9; 
double temperatura1, temperatura2 = 0;
// value of resistor in ohms
double resistor = 10000;

int readvalue,read2 = 0; // Ler valor porta
float volts,velocidade,percentual = 0;


// number of samples
int sample = 15;

void setup()
{
  pinMode(hotwire_port, INPUT);
  Serial.begin(115200);
  
}

void loop()
{

  readvalue = analogRead(0); 
  Serial.print(readvalue * (5.0 / 1023.0), 4);
  Serial.print(" ");

  readvalue = analogRead(1);
  Serial.print(readvalue * (5.0 / 1023.0), 4);
  Serial.print(" ");

  readvalue = analogRead(2);
  Serial.print(readvalue * (5.0 / 1023.0), 4);
  Serial.print(" ");

  readvalue = analogRead(3);
  Serial.print(readvalue * (5.0 / 1023.0), 4);
  
  for (int index = 0; index < sample; index++)
  {
      double temperature1 = temp1.getTemp(resistor);
      temperatura1 += temperature1;
      double temperature2 = temp2.getTemp(resistor);
      temperatura2 += temperature2;
      // a small delay for read again
      delayMicroseconds(1);
    }

    
  Serial.print(" ");
  Serial.print(temperatura1 = temperatura1 / sample, 0);
  Serial.print(" ");
  Serial.print(temperatura2 = temperatura2 / sample, 0);
  Serial.print(" ");

readvalue = analogRead(hotwire_port);
  volts = readvalue * (5.2 / 1023.0);
  
  velocidade=((volts-1)/(5-1))*39.8+0.1;
   Serial.print(velocidade, 2);
    Serial.print(" ");
    Serial.println();
  Serial.println();
  

}