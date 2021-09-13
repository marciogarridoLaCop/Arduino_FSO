
/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE LEITURA 10 BITS
*/
#include <sensor_temp.h>
int readvalue = 0; //Ler valor porta
float volts = 0;   //Valor convertido em volts (V)
String information = "";
String message ="No one parameter selected";
double steps = 0;
bool start;

float readphoto10(int porta, int amostrasx)
{
	readvalue = 0;
	for (int i = 0; i < amostrasx; i++)
	{
		readvalue += analogRead(porta) / amostrasx;
	}
	volts = readvalue * (5.0 / 1023.0); //Converter valores em volts
	if (volts > 5)
		volts = 0;
	return volts;
}

void generete_values(int detector, int delay, int amostras, bool photo, bool temp, bool texto)
{
	if (start == false)
	{
		start = true;
		if (texto == true)
		{
			switch (detector)
			{
			case 1:
				Serial.print("x");
				Serial.print(",");
				Serial.print("y1");
				Serial.print(",");
				Serial.print("T1");
				Serial.print(",");
				Serial.print("T2");

				break;
			case 2:
				Serial.print("x");
				Serial.print(",");
				Serial.print("y1");
				Serial.print(",");
				Serial.print("y2");
				Serial.print(",");
				Serial.print("T1");
				Serial.print(",");
				Serial.print("T2");

				break;
			case 3:
				Serial.print("x");
				Serial.print(",");
				Serial.print("y1");
				Serial.print(",");
				Serial.print("y2");
				Serial.print(",");
				Serial.print("y3");
				Serial.print(",");
				Serial.print("T1");
				Serial.print(",");
				Serial.print("T2");
				Serial.print(",");

				break;
			case 4:
				Serial.print("Sample");
				Serial.print(",");
				Serial.print("y1");
				Serial.print(",");
				Serial.print("y2");
				Serial.print(",");
				Serial.print("y3");
				Serial.print(",");
				Serial.print("y4");
				Serial.print(",");
				Serial.print("T1");
				Serial.print(",");
				Serial.print("T2");

				break;
			case 5:
				Serial.print("x");
				Serial.print(",");
				Serial.print("y1");
				Serial.print(",");
				Serial.print("y2");
				Serial.print(",");
				Serial.print("y3");
				Serial.print(",");
				Serial.print("y4");
				Serial.print(",");
				Serial.print("y5");
				Serial.print(",");
				Serial.print("T1");
				Serial.print(",");
				Serial.print("T2");
				Serial.print(",");
				break;
			case 6:
				Serial.print("x");
				Serial.print(",");
				Serial.print("y1");
				Serial.print(",");
				Serial.print("y2");
				Serial.print(",");
				Serial.print("y3");
				Serial.print(",");
				Serial.print("y4");
				Serial.print(",");
				Serial.print("y5");
				Serial.print(",");
				Serial.print("y6");
				Serial.print("T1");
				Serial.print(",");
				Serial.print("T2");

				break;
			}
			Serial.println("");
		}
	}
	{
		time = millis();
		while (millis() < time + delay)
		{
			//Aguarda sem parar o processamento
		}
		if (detector == 1 and photo == true)
		{
			
				Serial.print(readphoto10(detector - 1, amostras), 10);
				Serial.print(" ");
				steps = steps + 1;
		}

		if (detector > 1 and photo == true)
		{
			
				for (int i = 1; i <= detector; i++)
				{
					Serial.print(readphoto10(i - 1, amostras), 10);
					Serial.print(" ");
					if ((i) == detector)
					{
					}
				}
				steps = steps + 1;
			
		}	
		if (temp== true)
		{
				
				Serial.print(get_temp1(1));
				Serial.print(" ");
				Serial.print(get_temp2(1));
		}
		if (photo == false and temp == false)
		Serial.print(message);
	}
	Serial.println();
}

void read_sensor(int sensors, int amostras_photo, int amostras_temp, bool detector, bool temp, bool somente_numeros)
{
	Serial.flush();
	generete_values(sensors, 0, amostras_photo, detector, temp, somente_numeros);
	nAmostras = amostras_temp;
	delay(1);
}
