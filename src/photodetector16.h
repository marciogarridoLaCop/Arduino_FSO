
/* 
MARCIO GARRIDO 2021
BIBLIOTECA DE LEITURA 16 BITS
RESOLUCAO DE 5 VOLTS / 1024 UNIDADES.
0,0049 VOLTS
*/

int valorLido = 0; //Ler valor porta
float tensao = 0; //Valor convertido em volts (V)


float lerphoto10(int porta){
  valorLido = analogRead(porta);
  tensao = valorLido * (5.0/1023.0); //Converter valores em volts 
  if (tensao > 5)
    tensao = 0;
  return tensao;
}
