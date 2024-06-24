/*////////////////////////////////////
//  HEADER FILE ROBOT SEGUIDOR DE   //
//  DE LINEAS Y ESQUIVA OBSTACULOS  //
////////////////////////////////////*/
//
bool ARRANQUE_FLAGG = true;
//
#define GRAD90 0  //Tiempo que tarda el robor en girar 90 grados
//
/*Funcion que posiciona el robot en la linea*/
void arranque();
//
/*FUNCION PRINCIPAL CON EL FUNCIONAMIENTO DEL SIGUE LINEAS*/
int sigueLineas() {
  arranque();
  /*CONDICION 1*/
  /*3 SENSORES AFUERA 2 ADENTRO*/
  if (regleta() == 0B00011100) {
    adelante();
    do {
    } while (regleta() == 0B00011100);
    return 0;
  
  /*CONDICION 2*/
  /*TODOS LOS SENSORES AFUERA*/
  } else if (regleta() == 0B00011111) {
    MOTOR_D.setSpeed(VEL_MAX);
    MOTOR_I.setSpeed(VEL_MAX);
    MOTOR_D.run(RELEASE);
    MOTOR_I.run(FORWARD);
    do {
    } while (regleta() > 0B00011100);
    return 0;
  /*CONDICION 4*/
  /*TODOS LOS SENSORES ADENTRO*/
  } else if (regleta() == 0B00000000) {
    MOTOR_D.setSpeed(VEL_MAX);
    MOTOR_I.setSpeed(VEL_MAX);
    MOTOR_D.run(FORWARD);
    MOTOR_I.run(RELEASE);
    do {
    } while (regleta() < 0B00011100);
    return 0;
  /*CONDICION 5*/
  /*MAS DE 3 SENSORES AFUERA*/
  } else if (regleta() > 0B00011100) {
    girar_derecha();
    do {
    } while (regleta() > 0B00011100);
    return 0;
  /*CONDICION 6*/
  /*MAS DE 2 SENSORES ADENTRO*/
  } else if (regleta() < 0B00011100) {
    girar_izquierda();
    do {
    } while (regleta() < 0B00011100);
    return 0;
  }
}
//
void arranque() {
  if (ARRANQUE_FLAGG) {
    MOTOR_D.setSpeed(VEL_MAX);
    MOTOR_I.setSpeed(VEL_MAX);
    rotar_izquierda();
    delay(GRAD90);
    detener();
    delay(5);
    adelante();
    do {
    } while (regleta() == 0B00011111);
    detener();
    delay(5);
    rotar_derecha();
    do {

    } while (regleta() == 0B00011100);
    detener();
    delay(5);
    ARRANQUE_FLAGG = false;
  }
}
