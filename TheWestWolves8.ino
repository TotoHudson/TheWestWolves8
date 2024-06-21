#include "TheWestWolves8.h"
void setup() {
  /*Iniciando puerto Bluetooth*/
  Serial.begin(115200);
  SerialBT.begin("TheWestWolf_tec8");
  Serial.println("LISTO PARA EMPAREJAR...");
  void init();
  Serial.println("PINES DEFINIDOS...");
  Serial.println("\\FIN SETUP//");
}

void loop() {
    lecturaBT();
    sumo();
}
/*Funcion iniciacion para sumo*/
void init() {
  pinMode(M_A_1, OUTPUT);
  pinMode(M_A_2, OUTPUT);
  pinMode(M_A_E, OUTPUT);
  pinMode(M_B_1, OUTPUT);
  pinMode(M_B_2, OUTPUT);
  pinMode(M_B_E, OUTPUT);
  pinMode(TCRT_F_0, INPUT);
  pinMode(TCRT_F_1, INPUT);
  pinMode(TCRT_F_2, INPUT);
  pinMode(TCRT_F_3, INPUT);
  pinMode(TCRT_F_4, INPUT);
  pinMode(TCRT_T_1, INPUT);
  pinMode(TCRT_T_2, INPUT);
}