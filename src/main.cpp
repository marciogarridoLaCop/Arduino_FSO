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
unsigned long tempo = 0;
int incomingByte = 0;	// para dados seriais que estão entrando

void setup()
{
  Serial.begin(9600);
}

void gerar_texto(int retardo)
{
  tempo = millis();
  while (millis() < tempo + retardo)
  {
  //Aguarda sem parar o processamento
  } 
  Serial.print(" Photo Central");
  Serial.print(" -> ");
  Serial.print(0);
  Serial.print(" Valor: ");
  Serial.print(readphoto10(0));
  for (int i = 1; i <= 3; i++)
  {
    Serial.print(" Photo");
    Serial.print(" -> ");
    Serial.print(i);
    Serial.print(" Valor: ");
    Serial.print(readphoto10(i));
    if ((i) == 3)
    {
      Serial.println();
    }
  }
  Serial.println();
}

void gerar_valores(int retardo)
{
  tempo = millis();
  while (millis() < tempo + retardo)
  {
  //Aguarda sem parar o processamento
  }
  //Serial.print(" ");
  //Serial.print(0);
  Serial.print(readphoto10(0));
  //Serial.print(" ");
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

void loop()
{
  // envia dados apenas quando dados forem também recebidos:
	//if (Serial.available() > 0) {
		// lê o byte que está entrando:
	//	incomingByte = Serial.read();

		// diga o que você recebeu:
	//	Serial.print("Eu recebi : ");
	//	Serial.println(incomingByte, DEC);
  
  if(Serial.available()) { // se estiver recebendo algo pela serial
  Serial.read(); 
  //gerar_texto(500);
  gerar_valores(1000);
  }
}
