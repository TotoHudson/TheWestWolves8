// /*////////////////////////////////////
// //     HEADER FILE ULTRASONICOS     //
// //      THE WEST WOLVES 8 2024      //
// ////////////////////////////////////*/
// //
// /*pins Hc-Sr04*/
// #define HCSR_D_TRIG 8
// #define HCSR_D_ECHO 12
// #define HCSR_I_TRIG 9
// #define HCSR_I_ECHO 13
// #define HCSR_F_D_TRIG 10
// #define HCSR_F_D_ECHO 14
// #define HCSR_F_I_TRIG 11
// #define HCSR_F_I_ECHO 15
// //
// /*Funcion de inicializacion de pines de los sensores Hc-sr04*/
// void initUltraSonicos() {
//   pinMode(HCSR_D_TRIG, OUTPUT);
//   pinMode(HCSR_I_TRIG, OUTPUT);
//   pinMode(HCSR_F_D_TRIG, OUTPUT);
//   pinMode(HCSR_F_I_TRIG, OUTPUT);
//   pinMode(HCSR_D_ECHO, INPUT);
//   pinMode(HCSR_I_ECHO, INPUT);
//   pinMode(HCSR_F_D_ECHO, INPUT);
//   pinMode(HCSR_F_I_ECHO, INPUT);
// }
// /*Objetos tipo UltrasonicSensor*/
// UltrasonicSensor HCSR_D(HCSR_D_ECHO, HCSR_D_TRIG);
// UltrasonicSensor HCSR_I(HCSR_I_ECHO, HCSR_I_TRIG);
// UltrasonicSensor HCSR_F_D(HCSR_F_D_ECHO, HCSR_F_D_TRIG);
// UltrasonicSensor HCSR_F_I(HCSR_F_I_ECHO, HCSR_F_I_TRIG);
