/*////////////////////////////////////
//        HEADER FILE MOTORES       //
//      THE WEST WOLVES 8 2024      //
////////////////////////////////////*/
//
/*LIBRERIA CONTROL DE MOTORES*/
#include <THMotor.h>
//
#define CORRECCION_MD 0
#define CORRECCION_MI 0
#define VEL_RED 128
#define VEL_GIRO 128
#define VEL_MAX 255
/*Objetos tipo motor*/
THMotor MOTOR_D(M_A_1, M_A_2, M_A_E);
THMotor MOTOR_I(M_B_1, M_B_2, M_B_E);
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