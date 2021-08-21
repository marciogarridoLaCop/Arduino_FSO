/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
	 ALUNO:MARCIO ALEXANDRE DIAS GARRIDO
	 PROFESSOR DR. VINICIUS NUNES
*/

#include <SPI.h>
#include <unophoto10real.h>

void setup()
{
	axle=40000000;
	Serial.begin(2000000);
	Serial.flush();
	Serial.println("Press enter to reading values");	
	
}

void loop()
{
	if (Serial.available()){

	//Exemplo read_sensor(4,5,50); até 4 sensores ópticos, média de 5 amostras do phototransistor e média de 50 amostras de cada thermistor
	read_sensor(4,1,20);
	}
}
