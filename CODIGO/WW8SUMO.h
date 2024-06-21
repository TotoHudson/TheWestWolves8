/*////////////////////////////////////
//    PROGRAMA ROBOT SUMA CONTROL   //
//      REMOTO POR BLUETOOTH        //
//     THE WEST WOLVES 8 2024       //
////////////////////////////////////*/
//
/*Comandos*/
char COMANDL = '0';
char COMANDR = '0';
//
/*Dato recibido por bluetooth*/
char READ = '0';
//
void lecturaBT() {
  if (SerialBT.available()) {
    READ = SerialBT.read();
    if ((READ == 'F') || (READ == 'B') || (READ == 'L') || (READ == 'R')) {
      COMANDL = READ;
    } else if ((READ == 'f') || (READ == 'b') || (READ == 'l') || (READ == 'r')) {
      COMANDR = READ;
    } else if (READ == '0') {
      if(COMANDR == '0'){
        COMANDL = '0';
      }else{
        COMANDR = '0';
      }
    }
  }
}
//
void sumo() {
  //NADA PRESIONADO
  /*SE DETIENE EL ROBOT*/
  if ((COMANDL == '0') && (COMANDR == '0')) {
    detener();
    Serial.println("SE DETIENE EL ROBOT");
  }
  //ADELANTE SOLO
  /*AVANZA MAS LENTO*/
  if ((COMANDL == 'F') && (COMANDR == '0')) {
    MOTOR_D.setSpeed(VEL_RED - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_RED - CORRECCION_MI);
    adelante();
    Serial.println("AVANZA MAS LENTO");
  }
  //ATRAS SOLO
  /*RETROCEDE MAS LENTO*/
  if ((COMANDL == 'B') && (COMANDR == '0')) {
    MOTOR_D.setSpeed(VEL_RED - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_RED - CORRECCION_MI);
    atras();
    Serial.println("RETROCEDE MAS LENTO");
  }
  //ATRAS SOLO
  /*ROTA PARA LA IZQUIERDA MAS LENTO*/
  if ((COMANDL == 'L') && (COMANDR == '0')) {
    MOTOR_D.setSpeed(VEL_RED - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_RED - CORRECCION_MI);
    rotar_izquierda();
    Serial.println("ROTA PARA LA IZQUIERDA MAS LENTO");
  }
  //ATRAS SOLO
  /*ROTA PARA LA DERECHA MAS LENTO*/
  if ((COMANDL == 'R') && (COMANDR == '0')) {
    MOTOR_D.setSpeed(VEL_RED - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_RED - CORRECCION_MI);
    rotar_derecha();
    Serial.println("ROTA PARA LA DERECHA MAS LENTO");
  }
  //AMBOS ADELANTE
  /*AVANZA RAPIDO*/
  if ((COMANDL == 'F') && (COMANDR == 'f')) {
    MOTOR_D.setSpeed(VEL_MAX - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_MAX - CORRECCION_MI);
    adelante();
    Serial.println("AVANZA RAPIDO");
  }
  //AMBOS ATRAS
  /*RETROCEDE RAPIDO*/
  if ((COMANDL == 'B') && (COMANDR == 'b')) {
    MOTOR_D.setSpeed(VEL_MAX - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_MAX - CORRECCION_MI);
    atras();
    Serial.println("RETROCEDE RAPIDO");
  }
  //AMBOS IZQUIERDA
  /*ROTA PARA LA IZQUIERDA RAPIDO*/
  if ((COMANDL == 'L') && (COMANDR == 'l')) {
    MOTOR_D.setSpeed(VEL_MAX - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_MAX - CORRECCION_MI);
    rotar_izquierda();
    Serial.println("ROTA PARA LA IZQUIERDA RAPIDO");
  }
  //AMBOS DERECHA
  /*ROTA PARA LA DERECHA RAPIDO*/
  if ((COMANDL == 'R') && (COMANDR == 'r')) {
    MOTOR_D.setSpeed(VEL_MAX - CORRECCION_MD);
    MOTOR_I.setSpeed(VEL_MAX - CORRECCION_MI);
    rotar_derecha();
    Serial.println("ROTA PARA LA DERECHA RAPIDO");
  }
  //ADELANTE Y DERECHA
  /*AVANZA GIRANDO A LA DERECHA*/
  if ((COMANDL == 'F') && (COMANDR == 'r')) {
    girar_derecha();
    Serial.println("AVANZA GIRANDO A LA DERECHA");
  }
  //ADELANTE E IZQUIERDA
  /*AVANZA GIRANDO A LA IZQUIERDA*/
  if ((COMANDL == 'F') && (COMANDR == 'l')) {
    girar_izquierda();
    Serial.println("AVANZA GIRANDO A LA IZQUIERDA");
  }
  //ATRAS Y DERECHA
  /*RETROCEDE GIRANDO A LA DERECHA*/
  if ((COMANDL == 'B') && (COMANDR == 'r')) {
    girar_derecha_atras();
    Serial.println("RETROCEDE GIRANDO A LA DERECHA");
  }
  //ATRAS E IZQUIERDA
  /*RETROCEDE GIRANDO A LA IZQUIERDA*/
  if ((COMANDL == 'B') && (COMANDR == 'l')) {
    girar_izquierda_atras();
    Serial.println("RETROCEDE GIRANDO A LA IZQUIERDA");
  }
}
