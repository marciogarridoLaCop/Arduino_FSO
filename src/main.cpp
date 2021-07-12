/* DISSERTACAO MESTRADO ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
   ALUNO:MARCIO ALEXANDRE DIAS GARRIDO
   PROFESSOR DR. VINICIUS NUNES
*/
#include <Arduino.h>
#include <Wire.h>
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
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC não esta funcionando!");
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  Serial.println("Iniciando SD...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Falha no SD, ou nao esta inserido");
    return;
  }
  Serial.println("SD iniciado");
  now = RTC.now();
  dataFile = SD.open("log.txt", FILE_WRITE);
  dataFile.print("Iníncio da gravação: ");
  dataFile.print(now.day(), DEC);
  dataFile.print('/');
  dataFile.print(now.month(), DEC);
  dataFile.print('/');
  dataFile.print(now.year(), DEC);
  dataFile.println(" ");
  dataFile.print(" - ");
  dataFile.print(now.hour(), DEC);
  dataFile.print(":");
  dataFile.print(now.minute(), DEC);
  dataFile.print(":");
  dataFile.println(now.second(), DEC);
  dataFile.println(" ");
  dataFile.close();
}
void loop()
{
  tempo = millis()
  while(millis() < tempo + 2000) {
  }
  now = RTC.now();
  for (int i = 0; i <=3 ; i++) {
  Serial.print("Photo : ");
  Serial.print(i);
  Serial.print(lerphoto(i));
  Serial.read();
  }
}
