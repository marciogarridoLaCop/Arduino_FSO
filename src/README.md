
# README ABOUT ARDUINO SETTINGS# marciogarrido@id.uff.br

### Firsts steps to configure your application ###


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

