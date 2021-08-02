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
double x_position,steps=0;
float axle =55;

void setup()
{
	Serial.begin(9600); 
	Serial.flush();
	Serial.println ("Press enter to reading values");
	x_position=(-(axle/2));
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

void generete_values(int delay)
{
	time = millis();
	while (millis() < time + delay)
	{
	//Aguarda sem parar o processamento
	}
	 
	
	if (steps > abs((x_position*2))) {
		Serial.print("Finished");
	}
	else
	{
	Serial.print(readphoto10(0),2);
	Serial.print(" ");
	Serial.print(x_position+steps);
	steps=steps+1;
	}
	
	/*
	for (int i = 1; i <= 3; i++)
	{
		Serial.print(readphoto10(i));
		Serial.print(" ");
		if ((i) == 3)
		{
			Serial.println();
		}
	}
	*/
	Serial.println();
}



void read_serial_string(){
	Serial.flush();
	char character;
	information="";
	while(Serial.available() > 0) {
		// read byte
		character = Serial.read();
		// check if return keyboard ware pressed
		if (character == '\n'){
			// Concat values
		 generete_values(0);
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
	 read_serial_string();
	 
		}
}
