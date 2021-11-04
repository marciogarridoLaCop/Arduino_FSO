/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2
   ALUNO:MARCIO ALEXANDRE DIAS GARRIDO.
   PROFESSOR DR. VINICIUS NUNES
*/
#include <SPI.h>
#include <unophoto.h>
#include <Statistic.h>
#include <sensor_temp.h>
#include <Thermistor3.h>
Statistic myStats[6];
Thermistor temp1(4);
Thermistor temp2(5);

bool simulated;
int interacoes;
double resistor = 10000;
double temperatura1, temperatura2 = 0;
int sample = 500;

void setup()
{
  Serial.begin(115200);
  Serial.flush();
  simulated = true;
  Serial.println("Press enter to read values");
}
void loop()
{
  if (Serial.available())
  {
    //Read the data and plus to variable average
    for (int index = 0; index < sample; index++)
    {
      double temperature1 = temp1.getTemp(resistor);
      temperatura1 += temperature1;
      double temperature2 = temp2.getTemp(resistor);
      temperatura2 += temperature2;
      // a small delay for read again
      delayMicroseconds(1);
    }
    myStats[0].add(readphoto(0));
    myStats[1].add(readphoto(1));
    myStats[2].add(readphoto(2));
    myStats[3].add(readphoto(3));

    if (simulated == true)
    {
      Serial.flush();
      char character;
      information = "";
      while (Serial.available() > 0)
      {
        character = Serial.read();
        // check if return keyboard ware pressed
        if (character == '\n')
        {
          for (int i = 0; i < 4; i++)
          {
            /*
                Serial.print(myStats[i].minimum(), 4);
                Serial.print(" ");
                Serial.print(myStats[i].maximum(), 4);
                Serial.print(" ");
                */

            Serial.print(myStats[i].average(), 4);
            Serial.print(" ");
          }
          temperatura1 = temperatura1 / sample;
          temperatura2 = temperatura2 / sample;
          Serial.print(temperatura1, 2);
          Serial.print(" ");
          Serial.print(temperatura2, 2);
          Serial.print(" ");
          myStats[0].clear();
          myStats[1].clear();
          myStats[2].clear();
          myStats[3].clear();
          Serial.println();
        }
        information.concat(character);
        delay(10);
      }
    }
    else
    {
      Serial.flush();
      // valor de amostras lidas e posterior informação de minimo,maxima e média
      if (myStats[0].count() == 20)
      {
        /*
        varredura dos indices dos sensores
        */
        for (int i = 0; i < 4; i++)
        {
          /*
          Serial.print(myStats[i].minimum(), 4);
          Serial.print(" ");
          Serial.print(myStats[i].maximum(), 4);
          Serial.print(" ");
          */
          Serial.print(myStats[i].average(), 4);
          Serial.print(" ");
        }
        temperatura1 = temperatura1 / sample;
        temperatura2 = temperatura2 / sample;
        Serial.print(temperatura1, 2);
        Serial.print(" ");
        Serial.print(temperatura2, 2);
        Serial.print(" ");
        myStats[0].clear();
        myStats[1].clear();
        myStats[2].clear();
        myStats[3].clear();
        Serial.println();
      }
    }
  }
}