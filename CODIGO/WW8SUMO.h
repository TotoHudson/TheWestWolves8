/*////////////////////////////////////
//  HEADER FILE ROBOT SUMO CONTROL  //
//      REMOTO POR BLUETOOTH        //
////////////////////////////////////*/
//
/*Comandos*/
char COMANDL = '0'; //COMANDO CONTROL IZQUIERDO
char COMANDR = '0'; //COMANDO CONTROL DERECHO
char COMAND = '0';
//
/*Dato recibido por bluetooth*/
char READ = '0';
//
/*Funcion que recibe y almacena los comandos recibidos por bluetooth*/
void lecturaBT();
//
/*FUNCION PRINCIPAL DEL SUMO*/
int sumo() {

  lecturaBT();

  if (COMANDR == '0') {
    MOTOR_D.setSpeed(VEL_RED - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_RED - CORRECCION_MI);
  }

  if (COMANDR != '0') {
    MOTOR_D.setSpeed(VEL_MAX - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_MAX - CORRECCION_MI);
  }

  //NADA PRESIONADO
  /*SE DETIENE EL ROBOT*/
  if (COMANDL == '0') {
    detener();
    Serial.println("SE DETIENE EL ROBOT");
    while (COMANDL == '0') {
      lecturaBT();
    }
    return 0;
  }
  //
  //
  if (COMANDL == 'F') {
    COMAND = COMANDR;
    switch (COMANDR) {
      case 'r':
        girar_derecha();
        Serial.println("AVANZA GIRANDO A LA DERECHA");
        break;
      case 'l':
        girar_izquierda();
        Serial.println("AVANZA GIRANDO A LA IZQUIERDA");
        break;
      case '0':
        atras();
        Serial.println("AVANZA MAS LENTO");
        break;
      case 'f':
        atras();
        Serial.println("AVANZA RAPIDO");
        break;
    }
    do {
      lecturaBT();
    } while ((COMANDL == 'F') && (COMANDR == COMAND));
    return 0;
  }
  //
  //
  if (COMANDL == 'B') {
    COMAND = COMANDR;
    switch (COMANDR) {
      case 'r':
        girar_derecha_atras();
        Serial.println("RETROCEDE GIRANDO A LA DERECHA");
        break;
      case 'l':
        girar_izquierda_atras();
        Serial.println("RETROCEDE GIRANDO A LA IZQUIERDA");
        break;
      case '0':
        atras();
        Serial.println("RETROCEDE MAS LENTO");
        break;
      case 'f':
        atras();
        Serial.println("RETROCEDE RAPIDO");
        break;
    }
    do {
      lecturaBT();
    } while ((COMANDL == 'B') && (COMANDR == COMAND));
    return 0;
  }
  //
  //
  if (COMANDL == 'L') {
    COMAND = COMANDR;
    switch (COMANDR) {
      case 'l':
        rotar_izquierda();
        Serial.println("ROTA PARA LA IZQUIERDA RAPIDO");
        break;
      case '0':
        rotar_izquierda();
        Serial.println("ROTA PARA LA IZQUIERDA MAS LENTO");
        break;
    }
    do {
      lecturaBT();
    } while ((COMANDL == 'L') && (COMANDR == COMAND));
    return 0;
  }
  //
  //
  if (COMANDL == 'R') {
    COMAND = COMANDR;
    switch (COMANDR) {
      case 'r':
        rotar_derecha();
        Serial.println("ROTA PARA LA DERECHA RAPIDO");
        break;
      case '0':
        rotar_derecha();
        Serial.println("ROTA PARA LA DERECHA MAS LENTO");
        break;
    }
    do {
      lecturaBT();
    } while ((COMANDL == 'R') && (COMANDR == COMAND));
    return 0;
  }
}
//
void lecturaBT() {
  if (SerialBT.available()) {
    READ = SerialBT.read();
    if ((READ == 'F') || (READ == 'B') || (READ == 'L') || (READ == 'R')) {
      COMANDL = READ;
    } else if ((READ == 'f') || (READ == 'b') || (READ == 'l') || (READ == 'r')) {
      COMANDR = READ;
    } else if (READ == '0') {
      if (COMANDR == '0') {
        COMANDL = '0';
      } else {
        COMANDR = '0';
      }
    }
  }
}
