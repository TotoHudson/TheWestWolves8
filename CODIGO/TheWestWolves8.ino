#include "TheWestWolves8.h"

void setup() {
  /*Inicializacion puerto Bluetooth*/
  Serial.begin(115200);
  SerialBT.begin("TheWestWolf_tec8");
  Serial.println("LISTO PARA EMPAREJAR...");
  /*declaracion de puertos y pines*/
  initMotores();
  Serial.println("Pins motores definidos...");
  initIR(); 
  Serial.println("Pins IR sens definidos...");
  initUltraSonicos();
  Serial.println("Pins ultrasonicos definidos...");
  Serial.println("PINES DEFINIDOS...");
  /*Fondos virtuales de los sensores HC-sr04*/
  HCSR_F_I.MaxRange(MAXRANGE);
  HCSR_F_D.MaxRange(MAXRANGE);
  HCSR_I.MaxRange(MAXRANGE);
  HCSR_D.MaxRange(MAXRANGE);
  
  Serial.println("\\FIN SETUP//");
}

void loop() {
  sumo();
}
