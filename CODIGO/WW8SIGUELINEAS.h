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
    } while (regleta() == 0B00000000);
    detener();
    delay(5);
    rotar_derecha();
    do {
 
    } while (regleta() == 0B000000011);
    detener();
    delay(5);
    ARRANQUE_FLAGG = false;
  }
}

void sigueLineas() {

  arranque();
  
}