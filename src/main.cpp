/* DISSERTACAO MESTRADO ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
   ALUNO:MARCIO ALEXANDRE DIAS GARRIDO
   PROFESSOR DR. VINICIUS NUNES
*/

#include "RTClib.h"
const int chipSelect = 10;
RTC_DS1307 RTC;
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <photodetector16.h>
File dataFile;
DateTime now;
unsigned long tempo = 0;

void setup() {
 
  Serial.begin(9600);       
  //Wire.begin();
  //RTC.begin();
  //if (! RTC.isrunning()) {
  //  Serial.println("RTC não esta funcionando!");
  //  RTC.adjust(DateTime(__DATE__, __TIME__));
  }
 // Serial.println("Iniciando SD...");
 // if (!SD.begin(chipSelect)) {
 //   Serial.println("Falha no SD, ou nao esta inserido");
 //   return;
  //}
 // Serial.println("SD iniciado");
 // now = RTC.now();
 // dataFile = SD.open("log.txt", FILE_WRITE);
 // dataFile.print("Iníncio da gravação: ");
 // dataFile.print(now.day(), DEC);
 // dataFile.print('/');
 // dataFile.print(now.month(), DEC);
 // dataFile.print('/');
 // dataFile.print(now.year(), DEC);
  //dataFile.println(" ");
 // dataFile.print(" - ");
 // dataFile.print(now.hour(), DEC);
 // dataFile.print(":");
 // dataFile.print(now.minute(), DEC);
 // dataFile.print(":");
 // dataFile.println(now.second(), DEC);
 // /dataFile.println(" ");
 // dataFile.close();
//}


void loop()
{
  
tempo = millis();
 while(millis() < tempo + 500) {
 }
 // now = RTC.now();
 Serial.print(" Photo Central");
 Serial.print(" -> ");
 Serial.print(0);
 Serial.print(" Valor: ");
Serial.print(lerphoto10(0));
  for (int i = 1; i <=3 ; i++) {
  Serial.print(" Photo");
  Serial.print(" -> ");
  Serial.print(i);
  Serial.print(" Valor: ");
  Serial.print(lerphoto10(i));
  if ((i) == 3) {
Serial.println();
  }
  }
  

}
