// /*////////////////////////////////////
// //     HEADER FILE INFRARROJOS      //
// //      THE WEST WOLVES 8 2024      //
// ////////////////////////////////////*/
// //
// /*Pins de la REGLETA*/
// #define TCRT_F_0 16
// #define TCRT_F_1 17
// #define TCRT_F_3 18
// #define TCRT_F_4 19
// /*Pins de TCRT5000 TRASEROS*/
// // #define TCRT_T_1 7
// // #define TCRT_T_2 8
// //
// /*Funcion de inicializacion de pins de los sens. IR*/
// void initIR() {
//   pinMode(TCRT_F_0, INPUT);
//   pinMode(TCRT_F_1, INPUT);
//   pinMode(TCRT_F_3, INPUT);
//   pinMode(TCRT_F_4, INPUT);
//   // pinMode(TCRT_T_1, INPUT);
//   // pinMode(TCRT_T_2, INPUT);
// }
// /*Funcion que le hacigna un peso posicional dentro de un byte a los sensores de la regleta*/
// byte regleta() {
//   return ((1 * digitalRead(TCRT_F_0)) + (2 * digitalRead(TCRT_F_1)) + (8 * digitalRead(TCRT_F_3)) + (16 * digitalRead(TCRT_F_4)));
// }