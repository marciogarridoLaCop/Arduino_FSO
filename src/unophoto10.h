
/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE LEITURA 10 BITS
set a2d prescaled factor to 128
16 MHz / 128 = 125 KHz, inside the desired 50-200 KHz range.
XXX: this will not work properly for other clock speeds, and
this code should use F_CPU to determine the prescaled factor.
*/

int readvalue = 0; //Ler valor porta
float volts = 0;   //Valor convertido em volts (V)
String information = "";
double x_position, steps = 0;
unsigned long time = 0;
bool start;
float axle = 30;

float readphoto10(int porta)
{
	readvalue = analogRead(porta);
	volts = readvalue * (5.0 / 1023.0); //Converter valores em volts
	if (volts > 5)
		volts = 0;
	return volts;
}
void generete_values(int detector, int delay)
{
	if (start == false)
	{
		start = true;
		x_position = (-(axle / 2));

		switch (detector)
		{
		case 1:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("   x");
			break;
		case 2:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("  y2");
			Serial.print(" ");
			Serial.print("   x");
			break;
		case 3:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("  y2");
			Serial.print(" ");
			Serial.print("  y3");
			Serial.print(" ");
			Serial.print("   x");
			break;
		case 4:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("  y2");
			Serial.print(" ");
			Serial.print("  y3");
			Serial.print(" ");
			Serial.print("  y4");
			Serial.print(" ");
			Serial.print("   x");
			break;
		case 5:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("  y2");
			Serial.print(" ");
			Serial.print("  y3");
			Serial.print(" ");
			Serial.print("  y4");
			Serial.print(" ");
			Serial.print("  y5");
			Serial.print(" ");
			Serial.print("   x");
			break;
			case 6:
			Serial.print("  y1");
			Serial.print(" ");
			Serial.print("  y2");
			Serial.print(" ");
			Serial.print("  y3");
			Serial.print(" ");
			Serial.print("  y4");
			Serial.print(" ");
			Serial.print("  y5");
			Serial.print(" ");
			Serial.print("  y6");
			Serial.print(" ");
			Serial.print("   x");
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
			if (steps > abs((x_position * 2)))
			{
				steps = steps + 1;
				Serial.print("Finished");
				Serial.print(" ");
				Serial.println();
			}
			else
			{
				Serial.print(readphoto10(detector - 1), 2);
				Serial.print(" ");
				Serial.print(x_position + steps - 1);
				Serial.println();
			}
		}

		if (detector > 1)
		{
			if (steps > abs((x_position * 2)))
			{
				steps = steps + 1;
				Serial.print("Finished");
				Serial.print(" ");
				Serial.println();
			}
			else
			{
				for (int i = 1; i <= detector; i++)
				{
					Serial.print(readphoto10(i - 1), 2);
					Serial.print(" ");
					if ((i) == detector)
					{
					}
				}
				steps = steps + 1;
			}
		}
		if (steps > abs((x_position * 2) - 1))
		{
		}
		else
		{
			Serial.print(x_position + steps - 1);
			Serial.println();
		}
	}
}

void read_serial_string(int sensors)
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
			generete_values(sensors, 0);
			information.concat(character);
			delay(10);
		}
	}
}
