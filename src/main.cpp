/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2
   ALUNO:MARCIO ALEXANDRE DIAS GARRIDO.
   PROFESSOR DR. VINICIUS NUNES
*/
#include <SPI.h>
#include <unophoto.h>
#include <Statistic.h>
#include <sensor_temp.h>
Statistic myStats[6];

bool simulated;
int interacoes;
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
    myStats[0].add(readphoto(0));
    myStats[1].add(readphoto(1));
    myStats[2].add(readphoto(2));
    myStats[3].add(readphoto(3));
    myStats[4].add(get_temp1());
    myStats[5].add(get_temp2());
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
            for (int i = 0; i < 6; i++)
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
            myStats[0].clear();
            myStats[1].clear();
            myStats[2].clear();
            myStats[3].clear();
            myStats[4].clear();
            myStats[5].clear();
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
        for (int i = 0; i <= 5; i++)
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

        myStats[0].clear();
        myStats[1].clear();
        myStats[2].clear();
        myStats[3].clear();
        myStats[4].clear();
        myStats[5].clear();

        Serial.println();
      }
    }
  }
}