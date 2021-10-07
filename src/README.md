
# README ABOUT ARDUINO SETTINGS# marciogarrido@id.uff.br

### Firsts steps to configure your application ###

1 - Exemples of statistic
https://platformio.org/lib/show/1363/Statistic/installation

#include "Statistic.h"

Statistic myStats;

uint32_t start;
uint32_t stop;

bool useStdDev = true;

void setup(void)
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("Demo Statistics lib ");
  Serial.println(STATISTIC_LIB_VERSION);
  myStats.clear(useStdDev);
  start = millis();
}

void loop(void)
{
  long rn = random(0, 9999);
  myStats.add(rn / 100.0 + 1);
  if (myStats.count() == 10000)
  {
    stop = millis();
    Serial.print("        Count: ");
    Serial.println(myStats.count());
    Serial.print("          Min: ");
    Serial.println(myStats.minimum(), 4);
    Serial.print("          Max: ");
    Serial.println(myStats.maximum(), 4);
    Serial.print("      Average: ");
    Serial.println(myStats.average(), 4);
    if (useStdDev)
    {
      Serial.print("     variance: ");
      Serial.println(myStats.variance(), 4);
      Serial.print("    pop stdev: ");
      Serial.println(myStats.pop_stdev(), 4);
      Serial.print(" unbias stdev: ");
      Serial.println(myStats.unbiased_stdev(), 4);
    }
    Serial.print("     time(ms): ");
    Serial.println(stop - start);
    Serial.println("=====================================");
    useStdDev = !useStdDev;
    myStats.clear(useStdDev);
    start = millis();
  }
}

// -- END OF FILE --



2 - Adjust in main.cpp how many ports do you want to read - 

# EXEMPLE OF APPLICATION

#include <SPI.h>
#include <unophoto.h> Lib from photo read
#include <Statistic.h> Lib from statistic 
#include <sensor_temp.h> lib from temp read
Statistic myStats[5]; array of 5

bool simulated;  
void setup()
{
  Serial.begin(115200);
  Serial.flush();
  simulated = false; read for steps or not
  Serial.println("Press enter to read values");
}
void loop()
{
  if (Serial.available()) hearing port 
  {
    catch values from sensors 

	myStats[0].add(readphoto(0));
    myStats[1].add(readphoto(1));
    myStats[2].add(readphoto(2));
    myStats[3].add(readphoto(3));
    myStats[4].add(get_temp1());
    myStats[5].add(get_temp2());

    chech if is simulated or not 
    if (simulated == true)
    {
      if (start == false)
      Serial.flush();
      char character;
      information = "";
      while (Serial.available() > 0)
      {
        character = Serial.read();
        // check if return keyboard ware pressed
        if (character == '\n')
        {
          // valor de amostras lidas e posterior informação de minimo,maxima e média
          if (myStats[0].count() == 10)
          {

            for (int i = 0; i < 5; i++)
            {
              Serial.print(myStats[i].minimum(), 4);
              Serial.print(" ");
              Serial.print(myStats[i].maximum(), 4);
              Serial.print(" ");
              Serial.print(myStats[i].average(), 4);
              Serial.print(" ");
            }
            myStats[0].clear();
            Serial.println();
          }
          information.concat(character);
          delay(10);
        }
      }
    }

    else
    {
      Serial.flush();
      // valor de amostras lidas e posterior informação de minimo,maxima e média
      if (myStats[0].count() == 10)
      {

        for (int i = 0; i <= 5; i++)
        {
          Serial.print(myStats[i].minimum(), 4);
          Serial.print(" ");
          Serial.print(myStats[i].maximum(), 4);
          Serial.print(" ");
          Serial.print(myStats[i].average(), 4);
          Serial.print(" ");
        }
        myStats[0].clear();
        Serial.println();
      }
    }
  }
}


#

