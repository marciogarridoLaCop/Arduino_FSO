/* DISSERTACAO MESTRADO ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
   ALUNO:MARCIO ALEXANDRE DIAS GARRIDO

   PROFESSOR DR. VINICIUS NUNES
   AS ENTRADAS ANALOGICAS, NO CASO DO ARDUINO UNO, POSSUEM UMA RESOLUCAO DE 10 BITS PARA CONVERSAO ANALOGICA DIGITAL.
   NESTE MICROCONTROLADOR,ISSO GERA UMA RESOLUCAO DE 5 VOLTS / 1024 UNIDADES.
   OU SEJA, 0,0049 VOLTS. NO CASO,4.9 mV POR UNIDADE
*/
#include <Arduino.h>
#include <Wire.h>
//#include <Adafruit_ADS1X15.h>
//Adafruit_ADS1X15 ads;
#include "RTClib.h"
const int chipSelect = 10;
RTC_DS1307 RTC;
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <photodetector.h>
File dataFile;
DateTime now;


void setup() {

  //setup clock
  Wire.begin();
  RTC.begin();
  //Verificar se o RTC esta rodando
  if (! RTC.isrunning()) {
    Serial.println("RTC não esta funcionando!");
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  //---------------------------------------------------------------------------------------
  Serial.println("Iniciando SD...");
// Validando se o cartão esta OK
  if (!SD.begin(chipSelect)) {
    Serial.println("Falha no SD, ou nao esta inserido");
    return;
  }
  Serial.println("SD iniciado");
  //---------------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------------
  //Start de gravação
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
  //---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------

void loop()
{
  delay(2000);
  //Pegar Hora
  now = RTC.now();
  Serial.println(" Leitura Feita");  
  //printar_dados();
  Serial.read();
 // gravar_cartao();
}
//---------------------------------------------------------------------------------------