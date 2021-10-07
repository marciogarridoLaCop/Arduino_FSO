/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE TEMERATURA
*/

// Conexão do termistor



// Parâmetros do circuito
const double vcc = 4.95;
const double R = 100000.0;
int nAmostras;

float get_temp1(int atraso)
{
	
	double v = (vcc * analogRead(pinTermistor1) / 1024.0);
	double rt = (vcc * R) / v - R;
    t = beta / log(rt / rx);
	t = t - 273.0;
	myStats.add(t+1);
    Serial.println(myStats.count());
	//Serial.println(nAmostras);
	
	if (myStats.count() == nAmostras)
   {
    return myStats.average();
   }
	startx = millis();
	
}
float get_temp2(int atraso)
{
	double v = (vcc * analogRead(pinTermistor2) / 1024.0);
	double rt = (vcc * R) / v - R;
    t = beta / log(rt / rx);
	t = t - 273.0;
	myStats.add(t+1);
  
	if (myStats.count() == nAmostras)
 {
    return (myStats.average(), 4);
 }
    myStats.clear();
    startx = millis();
}