/*////////////////////////////////////
//        HEADER FILE MOTORES       //
//      THE WEST WOLVES 8 2024      //
////////////////////////////////////*/
//
#define CORRECCION_MD 0 //Factor de correccion de velocidad motor derecho (PWM)
#define CORRECCION_MI 35 //Factor de correccion de velocidad motor izquierdo (PWM)
#define VEL_RED 160 //Velocidad lenta de movimiento del robor (PWM)
#define VEL_GIRO 128  //Velocidad de la rueda lenta al momento de girar (NO ROTAR) (PWM)
#define VEL_MAX 255 //Velocidad maxima del robor (PWM)
//
/*Pins de MOTORES*/
#define M_A_E 5
#define M_A_1 7
#define M_A_2 6
#define M_B_1 4
#define M_B_2 2
#define M_B_E 3
/*Funcion de inicializacion de pins de los motores*/
void initMotores(){
  pinMode(M_A_1, OUTPUT);
  pinMode(M_A_2, OUTPUT);
  pinMode(M_A_E, OUTPUT);
  pinMode(M_B_1, OUTPUT);
  pinMode(M_B_2, OUTPUT);
  pinMode(M_B_E, OUTPUT);
}

/*Objetos tipo motor*/
THMotor MOTOR_D(M_A_1, M_A_2, M_A_E);
THMotor MOTOR_I(M_B_1, M_B_2, M_B_E);

/*FUNCIONES DE MOVIMIENTO DEL ROBOT*/
void detener() {
  MOTOR_D.run(RELEASE);
  MOTOR_I.run(RELEASE);
}
void adelante() {
  MOTOR_D.run(FORWARD);
  MOTOR_I.run(FORWARD);
}
void atras() {
  MOTOR_D.run(BACKWARD);
  MOTOR_I.run(BACKWARD);
}
void rotar_derecha() {
  MOTOR_D.run(BACKWARD);
  MOTOR_I.run(FORWARD);
}
void rotar_izquierda() {
  MOTOR_D.run(FORWARD);
  MOTOR_I.run(BACKWARD);
}
void girar_derecha() {
  MOTOR_D.setSpeed(VEL_GIRO - CORRECCION_MD);
  MOTOR_I.setSpeed(VEL_MAX);
  MOTOR_D.run(FORWARD);
  MOTOR_I.run(FORWARD);
}
void girar_izquierda() {
  MOTOR_D.setSpeed(VEL_MAX);
  MOTOR_I.setSpeed(VEL_GIRO - CORRECCION_MD);
  MOTOR_D.run(FORWARD);
  MOTOR_I.run(FORWARD);
}
void girar_derecha_atras() {
  MOTOR_D.setSpeed(VEL_GIRO - CORRECCION_MD);
  MOTOR_I.setSpeed(VEL_MAX);
  MOTOR_D.run(BACKWARD);
  MOTOR_I.run(BACKWARD);
}
void girar_izquierda_atras() {
  MOTOR_D.setSpeed(VEL_MAX);
  MOTOR_I.setSpeed(VEL_GIRO - CORRECCION_MD);
  MOTOR_D.run(BACKWARD);
  MOTOR_I.run(BACKWARD);
}
