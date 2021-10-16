/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE TEMERATURA
*/

const int pinTermistor1 = A6;
const int pinTermistor2 = A7;
// Parâmetros do termistor
double t, t1, t2 = 0;
unsigned long time = 0;
const double beta = 3960.0;
const double r0 = 100000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta / t0);
const double vcc = 4.95;
const double R = 100000.0;

float get_temp1()
{

	double v = (vcc * analogRead(pinTermistor1) / 1024.0);
	double rt = (vcc * R) / v - R;
	t = beta / log(rt / rx);
	t = t - 273.0;
	return t;
}
float get_temp2()
{
	double v = (vcc * analogRead(pinTermistor2) / 1024.0);
	double rt = (vcc * R) / v - R;
	t = beta / log(rt / rx);
	t = t - 273.0;
	return t;
}