#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1X15 ads;
#include "RTClib.h"
const int chipSelect = 10;
RTC_DS1307 RTC;
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
File dataFile;
DateTime now;

// declaração das variáveis de entrada analogicas
int16_t adc0, adc1, adc2, adc3;

int analogPin5 = A0;
String Photo = "Photo";

// declaração das variáveis de armazemento dos valores
double val1, val2, val3, val4, val5, k,k2 = 0; //

const float multiplier = 0.1875F;
//---------------------------------------------------------------------------------------
// leitura do primeiro photodetector
float lerphoto1()
{
  adc0 = ads.readADC_SingleEnded(0);
  val1 = (adc0 * multiplier);
  //  analogRead(analogPin1);  // leitura da porta A0
   val1=val1/k; // Convert D/A
  if (val1 > 5)
    val1 = 0;
  return val1;
}

// leitura do segundo photodetector
float lerphoto2()
{
  adc1 = ads.readADC_SingleEnded(1);
  val2 = adc1 * multiplier;
  val2=val2/k;
  if (val2 > 5)
    val2 = 0;
  return val2;
}

// leitura do terceiro photodetector
float lerphoto3()
{
  adc2 = ads.readADC_SingleEnded(2);
  val3 = adc2 * multiplier;
  val3=val3/k;
  if (val3 > 5)
    val3 = 0;
  return val3;
}

// leitura do quarto photodetector
float lerphoto4()
{
  adc3 = ads.readADC_SingleEnded(3);
  val4 = adc3 * multiplier;
  val4=val4/k;
  if (val4 > 5)
    val4 = 0;
  return val4;
}

// leitura do photodetector central
float lerphoto5()
{
  val5 = analogRead(analogPin5);  // leitura da porta A0
  val5=4.9*k2*val5;
  if (val5 > 6)
     val5 = 0;
  return val5;
}
//---------------------------------------------------------------------------------------

void setup() {

  // Descomentar o que interessa
  // ads.setGain(GAIN_TWOTHIRDS);  +/- 6.144V  1 bit = 0.1875mV (default)
  // ads.setGain(GAIN_ONE);        +/- 4.096V  1 bit = 0.125mV
  // ads.setGain(GAIN_TWO);        +/- 2.048V  1 bit = 0.0625mV
  // ads.setGain(GAIN_FOUR);       +/- 1.024V  1 bit = 0.03125mV
  // ads.setGain(GAIN_EIGHT);      +/- 0.512V  1 bit = 0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    +/- 0.256V  1 bit = 0.0078125mV
  ads.begin();

  Serial.begin(9600);           //  setup serial
  k = pow(10, 3);   //  constante para ajustar casa decimal da conversão Digital / Analogica ADS1115
  k2 = pow(10, -3); //  constante para ajustar casa decimal da conversão Digital / Analogica Arduino
  //---------------------------------------------------------------------------------------
  //setup clock
  Wire.begin();
  RTC.begin();
  //Verificar se o RTC esta rodando
  if (! RTC.isrunning()) {
    Serial.println("RTC não esta funcionando!");
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  //---------------------------------------------------------------------------------------

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
  dataFile.print("Photo1 : ");
  dataFile.print(lerphoto1());
  dataFile.print(" , ");
  dataFile.print("Photo2 : ");
  dataFile.print(lerphoto2());
  dataFile.print(" , ");
  dataFile.print("Photo3 : ");
  dataFile.print(lerphoto3());
  dataFile.print(" , ");
  dataFile.print("Photo4 : ");
  dataFile.print(lerphoto4());
  dataFile.print(" , ");
  dataFile.print("PhotoC : ");
  dataFile.print(lerphoto5());
  dataFile.print(" - ");
  dataFile.print(now.hour(), DEC);
  dataFile.print(":");
  dataFile.print(now.minute(), DEC);
  dataFile.print(":");
  dataFile.println(now.second(), DEC);
  dataFile.println(" ");
  dataFile.close();

  //---------------------------------------------------------------------------------------

}

//---------------------------------------------------------------------------------------
void gravar_cartao()
{
  //Abrir arquivo para gravar
  dataFile = SD.open("log.txt", FILE_WRITE);

  // Se arquivo presente, gravar.
  if (dataFile) {
    dataFile.print("P1 : ");
    dataFile.print(lerphoto1());
    dataFile.print(" , ");
    dataFile.print("P2 : ");
    dataFile.print(lerphoto2());
    dataFile.print(" , ");
    dataFile.print("P3 : ");
    dataFile.print(lerphoto3());
    dataFile.print(" , ");
    dataFile.print("P4 : ");
    dataFile.print(lerphoto4());
    dataFile.print(" , ");
    dataFile.print("PC : ");
    dataFile.print(lerphoto5());
    dataFile.print(" - ");
    dataFile.print(now.hour(), DEC);
    dataFile.print(":");
    dataFile.print(now.minute(), DEC);
    dataFile.print(":");
    dataFile.println(now.second(), DEC);
    // dataFile.println(" ");
    dataFile.close();
  }
  // Se o arquivo nao abrir, gerar erro:
  else {
    Serial.println("erro ao abrir log.txt");
  }
}

//---------------------------------------------------------------------------------------

void printar_dados()
{

float valores[5];  
 int amostras=0;
 for (int amostras=0; amostras<=10;amostras++)
Serial.print("P1 : ");
  Serial.print(lerphoto1());
  Serial.print(" , ");
  Serial.print("P2 : ");
  Serial.print(lerphoto2());
  Serial.print(" , ");
  Serial.print("P3 : ");
  Serial.print(lerphoto3());
  Serial.print(" , ");
  Serial.print("P4 : ");
  Serial.print(lerphoto4());
  Serial.print(" , ");
  Serial.print("Pc : ");
  Serial.print(lerphoto5());
  Serial.print(" - ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.println(now.second(), DEC);

{
  valores[amostras]=lerphoto5();
}
int tamanho = sizeof(valores)/sizeof(float);
float soma=0, media_=0, variancia_=0, desviopadrao_=0, somadosquadrados=0;

for (short i=0; i < tamanho; ++i){
soma += valores[i];
}
media_= soma/tamanho;

for (short i=0; i < tamanho; ++i){
somadosquadrados += sq (valores[i]-media_);
}
variancia_ = somadosquadrados / (tamanho-1);
desviopadrao_ = sqrt (variancia_);

Serial.print( media_);
Serial.print( desviopadrao_);

}


void loop()
{
  delay(2000);
  //Pegar Hora
  now = RTC.now();
  Serial.println(" Leitura Feita");  
  printar_dados();
  Serial.read();
 // gravar_cartao();
}
//---------------------------------------------------------------------------------------