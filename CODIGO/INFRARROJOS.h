/*////////////////////////////////////
//     HEADER FILE INFRARROJOS      //
//      THE WEST WOLVES 8 2024      //
////////////////////////////////////*/
//
#if GPIO_DEFINED //Si estan definidos los GPIOS
/*Pins de la REGLETA*/
#define TCRT_F_0 GPIO2
#define TCRT_F_1 GPIO3
#define TCRT_F_2 GPIO4
#define TCRT_F_3 GPIO5
#define TCRT_F_4 GPIO6
/*Pins de TCRT5000 TRASEROS*/
#define TCRT_T_1 GPIO7
#define TCRT_T_2 GPIO8
#endif
//
/*Funcion de inicializacion de pins de los sens. IR*/
void initIR() {
  pinMode(TCRT_F_0, INPUT);
  pinMode(TCRT_F_1, INPUT);
  pinMode(TCRT_F_2, INPUT);
  pinMode(TCRT_F_3, INPUT);
  pinMode(TCRT_F_4, INPUT);
  pinMode(TCRT_T_1, INPUT);
  pinMode(TCRT_T_2, INPUT);
}
/*Funcion que le hacigna un peso posicional dentro de un byte a los sensores de la regleta*/
byte regleta() {
  return ((1 * digitalRead(TCRT_F_0)) + (2 * digitalRead(TCRT_F_1)) + (4 * digitalRead(TCRT_F_2)) + (8 * digitalRead(TCRT_F_3)) + (16 * digitalRead(TCRT_F_4)));
}