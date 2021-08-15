/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
	 ALUNO:MARCIO ALEXANDRE DIAS GARRIDO
	 PROFESSOR DR. VINICIUS NUNES
*/

#include <SPI.h>
#include <unophoto10.h>



void setup()
{
	axle=50;
	Serial.begin(9600);
	Serial.flush();
	Serial.println("Press enter to reading values");	
	
}
void loop()
{
	if (Serial.available())
	{
	read_sensor(2);

	}
}
