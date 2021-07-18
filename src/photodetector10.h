
/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE LEITURA 10 BITS
set a2d prescaled factor to 128
16 MHz / 128 = 125 KHz, inside the desired 50-200 KHz range.
XXX: this will not work properly for other clock speeds, and
this code should use F_CPU to determine the prescaled factor.
*/

float vx,kx=0; //
int valorLido = 0; //Ler valor porta
float tensao = 0; //Valor convertido em volts (V)


float lerphoto10(int porta){
  valorLido = analogRead(porta);
  tensao = valorLido * (5.0/1023.0); //Converter valores em volts 
  if (tensao > 5)
    tensao = 0;
  return tensao;
}