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
#include <unophoto10.h>
File dataFile;
DateTime now;

void setup()
{
	axle=30;
	Serial.begin(9600);
	Serial.flush();
	Serial.println("Press enter to reading values");	
}
void loop()
{
	if (Serial.available())
	{
		read_serial_string(2);
	}
}
