
# README ABOUT ARDUINO SETTINGS# marciogarrido@id.uff.br

### Firsts steps to configure your application ###

1 - Exemples of statistic
https://platformio.org/lib/show/1363/Statistic/installation

2 - Adjust in main.cpp how many ports do you want to read - 

# EXEMPLE OF APPLICATION

#include <SPI.h>
#include <unophoto.h> 
#include <Statistic.h> 
#include <sensor_temp.h> 
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

