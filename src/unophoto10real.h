
/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE LEITURA 10 BITS
*/
const int pinTermistor1 = A4;
const int pinTermistor2 = A5;
int readvalue = 0; //Ler valor porta
float volts = 0;   //Valor convertido em volts (V)
String information = "";
double x_position, steps, t = 0;
unsigned long time = 0;
bool start;
float axle = 30;
// Parametros do termistor
const double beta = 3960.0;
const double r0 = 100000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta / t0);

// Parâmetros do circuito
const double vcc = 4.95;
const double R = 100000.0;

// Numero de amostras na leitura
const int nAmostras = 4;

float readphoto10(int porta)
{
	readvalue = analogRead(porta);
	volts = readvalue * (5.0 / 1023.0); //Converter valores em volts
	if (volts > 5)
		volts = 0;
	return volts;
}
float get_temp1(int atraso)
{
	time = millis();
	while (millis() < time + atraso) // Le o sensor algumas vezes
	{
		int soma = 0;
		for (int i = 0; i < nAmostras; i++)
		{
			soma += analogRead(pinTermistor1);
			delay(10);
		}
		// Determina a resistência do termistor
		double v = (vcc * soma) / (nAmostras * 1024.0);
		double rt = (vcc * R) / v - R;

		// Calcula a temperatura
		t = beta / log(rt / rx);
		t = t - 273.0;
	}
	return t;
}
float get_temp2(int atraso)
{
	time = millis();
	while (millis() < time + atraso) // Le o sensor algumas vezes
	{
		int soma = 0;
		for (int i = 0; i < nAmostras; i++)
		{
			soma += analogRead(pinTermistor2);
			delay(10);
		}
		// Determina a resistência do termistor
		double v = (vcc * soma) / (nAmostras * 1024.0);
		double rt = (vcc * R) / v - R;

		// Calcula a temperatura
		t = beta / log(rt / rx);
		t = t - 273.0;
	}
	return t;
}
void generete_values(int detector, int delay)
{
	if (start == false)
	{
		start = true;
		x_position = axle;

		switch (detector)
		{
		case 1:
			Serial.print("Sample");
			Serial.print(",");
			Serial.print("y1");
			Serial.print(",");
			Serial.print("T1");
			Serial.print(",");
			Serial.print(",T2");

			break;
		case 2:
			Serial.print("Sample");
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
			Serial.print("Sample");
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
			Serial.print("y5");
			Serial.print(",");
			Serial.print("T1");
			Serial.print(",");
			Serial.print("T2");
			Serial.print(",");
			break;
		case 6:
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
	{
		time = millis();
		while (millis() < time + delay)
		{
			//Aguarda sem parar o processamento
		}
		if (detector == 1)
		{
			if (steps > abs(x_position))
			{
				Serial.print("Finished");
				Serial.print(" ");
				Serial.println();
			}
			else
			{
				Serial.print(steps, 0);
				Serial.print(",");
				Serial.print(readphoto10(detector - 1), 2);
				Serial.print(",");
				steps = steps + 1;
			}
		}

		if (detector > 1)
		{
			if (steps > abs((x_position)))
			{
				steps = steps + 1;
				Serial.print("Finished");
				Serial.print(" ");
				Serial.println();
			}
			else
			{
				Serial.print(steps, 0);
				Serial.print(",");
				for (int i = 1; i <= detector; i++)
				{
					Serial.print(readphoto10(i - 1), 2);
					Serial.print(",");
					if ((i) == detector)
					{
					}
				}
				steps = steps + 1;
			}
		}
		if (steps > abs((x_position)))
		{
		}
		else
		{
			Serial.print(get_temp1(1));
			Serial.print(",");
			Serial.print(get_temp2(1));
			//	Serial.print(",");
			Serial.println();
		}
	}
}

void read_sensor(int sensors)
{
	Serial.flush();

	generete_values(sensors, 0);
	delay(1);
}
