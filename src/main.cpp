/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2
   ALUNO:MARCIO ALEXANDRE DIAS GARRIDO.
   PROFESSOR DR. VINICIUS NUNES
*/
#include <SPI.h>
#include <unophoto.h>
#include <sensor_temp.h>
#include <Thermistor3.h>
Thermistor temp1(7);
Thermistor temp2(6);

int hotwire_port = 9;
double temperatura1, temperatura2 = 0;
double resistor = 10000;
float velocidade = 0;
int sample = 15;
bool simulated;
void setup()
{
    Serial.begin(2000000);
    Serial.flush();
    simulated = true;
    Serial.println("Press enter to read values");
}

void printar()
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

        delayMicroseconds(1);
    }

    Serial.print(" ");
    Serial.print(temperatura1 = temperatura1 / sample, 0);
    Serial.print(" ");
    Serial.print(temperatura2 = temperatura2 / sample, 0);
    Serial.print(" ");

    readvalue = analogRead(hotwire_port);
    volts = readvalue * (5.2 / 1023.0);

    velocidade = ((volts - 1) / (5 - 1)) * 39.8 + 0.1;
    Serial.print(velocidade, 2);
    Serial.print(" ");
    Serial.println();
}
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