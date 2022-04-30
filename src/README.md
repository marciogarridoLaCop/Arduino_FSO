
# README ABOUT ARDUINO SETTINGS# marciogarrido@id.uff.br

### Firsts steps to configure your application ###

simulated (false or true). When do you set for true, the code will run until someone press enter to run again. 
If the parameter are defined with false, it will run without steping

```
  void loop()
{
    if (Serial.available())
    {
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
                    printar();
                }
                information.concat(character);
                delay(10);
            }
        }
        else
        {
            printar();
        }
    }
}
```

