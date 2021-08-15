/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE TEMERATURA
*/


// Conexão do termistor
const int pinTermistor = A6;
 
// Parâmetros do termistor
const double beta = 3960.0; 
const double r0 = 100000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta/t0);
 
// Parâmetros do circuito
const double vcc = 4.95;
const double R = 100000.0;
 
// Numero de amostras na leitura
const int nAmostras = 5;

// Laço perpétuo
void read_temp(int delay) {
  
  time = millis();
	while (millis() < time + delay)// Le o sensor algumas vezes
  {
  int soma = 0;
  for (int i = 0; i < nAmostras; i++) {
    soma += analogRead(pinTermistor);
    delay (10);
  }
  // Determina a resistência do termistor
  double v = (vcc*soma)/(nAmostras*1024.0);
  double rt = (vcc*R)/v - R;
 
  // Calcula a temperatura
  double t = beta / log(rt/rx);
  t=t-273.0;
  Serial.println (t,1);
  }
}
