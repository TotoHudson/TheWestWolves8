/*////////////////////////////////////
//     HEADER FILE ULTRASONICOS     //
//      THE WEST WOLVES 8 2024      //
////////////////////////////////////*/
//
#if GPIO_DEFINED //Si estan definidos los GPIOS
/*pins Hc-Sr04*/
#define HCSR_D_TRIG GPIO10
#define HCSR_D_ECHO GPIO12
#define HCSR_I_TRIG GPIO13
#define HCSR_I_ECHO GPIO14
#define HCSR_F_D_TRIG GPIO15
#define HCSR_F_D_ECHO GPIO32
#define HCSR_F_I_TRIG GPIO33
#define HCSR_F_I_ECHO GPIO34
#endif
//
/*Funcion de inicializacion de pines de los sensores Hc-sr04*/
void initUltraSonicos() {
  pinMode(HCSR_D_TRIG, OUTPUT);
  pinMode(HCSR_I_TRIG, OUTPUT);
  pinMode(HCSR_F_D_TRIG, OUTPUT);
  pinMode(HCSR_F_I_TRIG, OUTPUT);
  pinMode(HCSR_D_ECHO, INPUT);
  pinMode(HCSR_I_ECHO, INPUT);
  pinMode(HCSR_F_D_ECHO, INPUT);
  pinMode(HCSR_F_I_ECHO, INPUT);
}
/*Objetos tipo UltrasonicSensor*/
UltrasonicSensor HCSR_D(HCSR_D_ECHO, HCSR_D_TRIG);
UltrasonicSensor HCSR_I(HCSR_I_ECHO, HCSR_I_TRIG);
UltrasonicSensor HCSR_F_D(HCSR_F_D_ECHO, HCSR_F_D_TRIG);
UltrasonicSensor HCSR_F_I(HCSR_F_I_ECHO, HCSR_F_I_TRIG);
