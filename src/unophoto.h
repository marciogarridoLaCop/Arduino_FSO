/* DISSERTACAO DE MESTRADO EM ENGENHARIA ELETRICA E TELECOMUNICACOES - UFF 2018.2 
	 ALUNO:MARCIO ALEXANDRE DIAS GARRIDO.
	 PROFESSOR DR. VINICIUS NUNES
	 BIBLIOTECA DE LEITURA DE TEMPERATURA (THERMISTOR ) E TENSAO
*/

int readvalue = 0; //Ler valor porta
float volts = 0;   //Valor convertido em volts (V)
String information = "";
String message = "No one parameter selected";
double steps = 0;
bool start;

float readphoto(int porta)
{
	readvalue = analogRead(porta);
	volts = readvalue * (5.0 / 1023.0); //Converter valores em volts
	if (volts > 5)
		volts = 0;
	return volts;
}

void generete_values(int detector, int amostras)
{
	
	if (detector == 1 )
	{

		Serial.print(readphoto(detector), 10);
		Serial.print(" ");
		steps = steps + 1;
	}

	if (detector > 1)
	{

		for (int i = 1; i <= detector; i++)
		{
			Serial.print(readphoto(i), 10);
			Serial.print(" ");
			if ((i) == detector)
			{
			}
		}
		steps = steps + 1;
	}
//Serial.println();
}

void read_sensor(bool simulated, int sensors, int amostras_photo)
{
	if (simulated == true)
	{
		if (start == false)
			Serial.flush();
		char character;
		information = "";
		while (Serial.available() > 0)
		{
			character = Serial.read();
			// check if return keyboard ware pressed
			if (character == '\n')
			{
				generete_values(sensors,amostras_photo);
				information.concat(character);
				delay(10);
			}
		}
	}
	else
	{
		Serial.flush();
		generete_values(sensors,amostras_photo);
	}
}
