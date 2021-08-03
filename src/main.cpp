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
float axle = 30;


void setup()
{
	Serial.begin(9600);
	Serial.flush();
	Serial.println("Press enter to reading values");
	x_position = (-(axle / 2));
}

void loop()
{
	if (Serial.available())
	{
		read_serial_string(3);
	}
}
