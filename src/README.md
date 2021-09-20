
# README ABOUT ARDUINO SETTINGS# marciogarrido@id.uff.br

### Firsts steps to configure your application ###

1 - Choose the library for your project.

unophoto.h - Read each return press - For 10 bits resolution ( Arduino uno port from A0 to An) limited from arduino type, in this case, six ports. 
shield_adsphoto.h - For 16 bits resolution (Ads 1115 port from A0 to An) limited from Ads port type, in this case, four ports.

2 - Adjust in main.cpp how many ports do you want to read - 

| Function name           | Description                    |
| ----------------------- | ------------------------------ |
| `read_serial_string(n,mean read detector,mean temp)` | read and show sensors values   |

# EXEMPLE 

#

if (Serial.available()){
	// Exemplo read_sensor(false,4,1,20,true,false,false); leitura seré por steps, até 4 sensores ópticos, média de 5 amostras do phototransistor e média de 50 amostras de cada thermistor, ///// executar leitura dos detectores, executar leitura do thermistores, printar textos.
	read_sensor(false,4,1,20,true,false,false);
}