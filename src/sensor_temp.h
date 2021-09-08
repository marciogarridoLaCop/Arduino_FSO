/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE TEMERATURA
*/

// Conexão do termistor

char clat[11];
const int pinTermistor1 = A4;
const int pinTermistor2 = A5;
// Parâmetros do termistor
double t=0;
unsigned long time = 0;
const double beta = 3960.0;
const double r0 = 100000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta / t0);

// Parâmetros do circuito
const double vcc = 4.95;
const double R = 100000.0;
int nAmostras = 50;

float get_temp1(int atraso)
{
	time = millis();
	while (millis() < time + atraso) // Le o sensor algumas vezes
	{
		int soma = 0;
		for (int i = 0; i < nAmostras; i++)
		{
			soma += analogRead(pinTermistor1);
			delay(1);
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
			delay(1);
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