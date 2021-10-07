/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
	 ALUNO:MARCIO ALEXANDRE DIAS GARRIDO.
	 PROFESSOR DR. VINICIUS NUNES
*/

#include <SPI.h>
#include <unophoto.h>
#include <Statistic.h>

Statistic myStats,myStats2;
uint32_t startx;
uint32_t stop;

const int pinTermistor1 = A4;
const int pinTermistor2 = A5;
// Parâmetros do termistor
double t,t1,t2 = 0;
unsigned long time = 0;
const double beta = 3960.0;
const double r0 = 100000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta / t0);
const double vcc = 4.95;
const double R = 100000.0;

// Parâmetros do termistor

void setup()
{
  Serial.begin(115200);
  Serial.flush();
  Serial.println("Press enter to read values");
  start = millis();
}



void loop()
{
  if (Serial.available()){
  double v = (vcc * analogRead(pinTermistor1) / 1024.0);
	double rt = (vcc * R) / v - R;
  t = beta / log(rt / rx);
	t = t - 273.0;
  
  double v2 = (vcc * analogRead(pinTermistor2) / 1024.0);
  double rt2 = (vcc * R) / v2 - R;
  t2 = beta / log(rt2 / rx);
  t2 = t2 - 273.0;
  
  read_sensor(false,4,1);
  myStats.add(t);
  Serial.print(myStats.maximum());
  Serial.print(" ");
  myStats2.add(t2);
  Serial.print(myStats2.maximum());
  Serial.println();
  
  if (myStats.count() == 10)
  {
    myStats.clear();
    myStats2.clear();
  }
  }
}