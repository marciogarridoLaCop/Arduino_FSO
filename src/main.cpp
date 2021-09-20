/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
	 ALUNO:MARCIO ALEXANDRE DIAS GARRIDO.
	 PROFESSOR DR. VINICIUS NUNES
*/

#include <SPI.h>
#include <unophoto.h>
void setup()
{
	Serial.begin(9600);
	Serial.flush();
	Serial.println("Press enter to read values");		
}

void loop()
{
	if (Serial.available()){
	//Exemplo read_sensor(false,4,1,20,true,false,false); leitura seré por steps, até 4 sensores ópticos, média de 5 amostras do phototransistor e média de 50 amostras de cada thermistor, executar leitura dos detectores, executar leitura do thermistores, printar textos
	read_sensor(false,4,1,20,true,false,false);
	}
}