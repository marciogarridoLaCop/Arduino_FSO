/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE TEMERATURA
*/

// Conexão do termistor

  char clat[11];

// Parâmetros do termistor
const double beta = 3960.0;
const double r0 = 100000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta / t0);

// Parâmetros do circuito
const double vcc = 4.95;
const double R = 100000.0;

// Numero de amostras na leitura
const int nAmostras = 30;

void get_temp(int atraso)
{
  time = millis();
  while (millis() < time + atraso) // Le o sensor algumas vezes
  {
    int soma = 0;
    for (int i = 0; i < nAmostras; i++)
    {
      soma += analogRead(pinTermistor);
      delay(10);
    }
    // Determina a resistência do termistor
    double v = (vcc * soma) / (nAmostras * 1024.0);
    double rt = (vcc * R) / v - R;

    // Calcula a temperatura
    double t = beta / log(rt / rx);
    t = t - 273.0;
  //  Serial.println(t, 1);
    dtostrf(t,2,2,clat);
    Serial.println(clat);
    Serial.read();
  }
}
unsigned int buffer_pos = 0;

// Leitura
void read_temp(int atraso){

get_temp(1);

}