/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
	 ALUNO:MARCIO ALEXANDRE DIAS GARRIDO
	 PROFESSOR DR. VINICIUS NUNES
*/
#include "RTClib.h"
const int chipSelect = 10;
RTC_DS1307 RTC;
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <photodetector10.h>
File dataFile;
DateTime now;
unsigned long time = 0;
String information = "";
double x_position, steps = 0;
float axle = 30;
bool start;

void setup()
{
	Serial.begin(9600);
	Serial.flush();
	Serial.println("Press enter to reading values");
	x_position = (-(axle / 2));
}

void generate_text(int delay)
{
	time = millis();
	while (millis() < time + delay)
	{
		//Wait without stop processesing
	}
	Serial.print(" Center Photo");
	Serial.print(" -> ");
	Serial.print(0);
	Serial.print(" Value: ");
	Serial.print(readphoto10(0));
	for (int i = 1; i <= 3; i++)
	{
		Serial.print(" Photo");
		Serial.print(" -> ");
		Serial.print(i);
		Serial.print(" Value: ");
		Serial.print(readphoto10(i));
		if ((i) == 3)
		{
			Serial.println();
		}
	}
	Serial.println();
}

void generete_values(int detector, int delay)
{
	if (start == false)
	{
		start = true;
		switch (detector)
		{
		case 1:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("   x");
			break;
		case 2:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("  y2");
			Serial.print(" ");
			Serial.print("   x");
			break;
		case 3:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("  y2");
			Serial.print(" ");
			Serial.print("  y3");
			Serial.print(" ");
			Serial.print("   x");
			break;
		case 4:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("  y2");
			Serial.print(" ");
			Serial.print("  y3");
			Serial.print(" ");
			Serial.print("  y4");
			Serial.print(" ");
			Serial.print("   x");
			break;
		}
		Serial.println("");
	}

	{
		time = millis();
		while (millis() < time + delay)
		{
			//Aguarda sem parar o processamento
		}
		if (detector == 1)
		{
			if (steps > abs((x_position * 2)))
			{
				steps = steps + 1;
				Serial.print("Finished");
				Serial.print(" ");
				Serial.println();
			}
			else
			{
				Serial.print(readphoto10(detector - 1), 2);
				Serial.print(" ");
				Serial.print(x_position + steps - 1);
				Serial.println();
			}
		}

		if (detector > 1)
		{
			if (steps > abs((x_position * 2)))
			{
				steps = steps + 1;
				Serial.print("Finished");
				Serial.print(" ");
				Serial.println();
			}
			else
			{
				for (int i = 1; i <= detector; i++)
				{
					Serial.print(readphoto10(i - 1), 2);
					Serial.print(" ");
					if ((i) == detector)
					{
					}
				}
				steps = steps + 1;
			}
		}
		if (steps > abs((x_position * 2) - 1))
		{
		}
		else
		{
			Serial.print(x_position + steps - 1);
			Serial.println();
		}
	}
}

void read_serial_string(int n_off_detector)
{
	if (start == false)
		Serial.flush();
	char character;
	information = "";
	while (Serial.available() > 0)
	{
		// read byte
		character = Serial.read();
		// check if return keyboard ware pressed
		if (character == '\n')
		{
			// Concat values
			generete_values(n_off_detector, 0);
			information.concat(character);
			// wait buffer to read the next packet
			delay(10);
		}
	}
}

void loop()
{
	if (Serial.available())
	{
		read_serial_string(3);
	}
}
