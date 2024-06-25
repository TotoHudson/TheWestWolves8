// /*////////////////////////////////////
// //      HEADERFILE ROBOT DESPEJA    //
// //         AREA DE OBSTACULOS       //
// ////////////////////////////////////*/
// //
// #define MAXRANGE 150  //Fondo virtual o maxima deteccion en cm del HC-Sr04
// #define MARGEN 5      //Margen de error o tolerancia en la medicion de los sensores
// #define GRAD180 0     //Tiempo en que el robot tarda en girar 180 grados
// #define DISSEC 1500   //Tiempo de avance o retroceso del robot para despegarce del borde
// //
// long t = 0;
// //
// bool centrado();
// //
// //
// /*FUNCION PRINCIPAL CON EL FUNCIONAMIENTO DEL DESPEJA AREA*/
// int DespejaArea() {
  
//   /*CONDICION 1*/
//   /*EL SENSOR DE LA DERECHA MIDE MAS QUE EL DE LA IZQUIERDA*/
//   if (HCSR_D.Distance() <= HCSR_I.Distance()) {
//     rotar_derecha();
//     do {
//     } while (!centrado());

//     /*CONDICION 2*/
//     /*EL SENSOR DE LA IZQUIERDA MIDE MAS QUE EL DE LA DERECHA*/
//   } else if (HCSR_D.Distance() > HCSR_I.Distance()) {
//     rotar_izquierda();
//     do {
//     } while (!centrado());

//     /*CONDICION 3*/
//     /*EL OBJETO SE ENCUENTRA CENTRADO Y FRENTE AL ROBOR*/
//   } else if (centrado()) {
//     adelante();
//     do {
//     } while (regleta() <= 0B00000000);
//     detener();
//     delay(5);
//     atras();
//     t = millis();
//     do {
//       if ((HCSR_D.Distance() < MAXRANGE) || (HCSR_I.Distance() < MAXRANGE) || digitalRead(TCRT_T_1) || digitalRead(TCRT_T_2)) {
//         return 0;
//       }
//     } while ((millis() - t) < DISSEC);

//     /*CONDICION 4*/
//     /*HAY UN OBJETO DELANTE DEL ROBOT PERO NO ESTA SENTRAS*/
//     /* Y SE ENCUENTRA MAS A LA DERECHA*/
//   } else if (HCSR_F_D.Distance() < HCSR_F_I.Distance()) {
//     rotar_derecha();
//     do {
//     } while (!centrado());

//     /*CONDICION 5*/
//     /*HAY UN OBJETO DELANTE DEL ROBOT PERO NO ESTA SENTRAS*/
//     /* Y SE ENCUENTRA MAS A LA IZQUIERDA*/

//   } else if (HCSR_F_D.Distance() > HCSR_F_I.Distance()) {
//     rotar_izquierda();
//     do {
//     } while (!centrado());

//   /*CONDICION 6*/
//   /*NADA ES DETECTADO POR LOS SENSORES*/
//   } else {
//     rotar_derecha();
//     t = millis();
//     do {
//       if ((HCSR_D.Distance() < MAXRANGE) || (HCSR_I.Distance() < MAXRANGE) || centrado()) {
//         return 0;
//       }
//     } while ((millis() - t) < GRAD180);
//     detener();
//     delay(5);
//     adelante();
//     t = millis();
//     do {
//       if ((HCSR_D.Distance() < MAXRANGE) || (HCSR_I.Distance() < MAXRANGE) || centrado() || (regleta() > 0B00000000)) {
//         return 0;
//       }
//     } while ((millis() - t) < DISSEC);
//     return 0;
//   }


//   /*CONDICIONES EXTRAS POR SEGURIDAD*/

//   /*ALGUNO DE LOS DOS SENSORES SE ENCUENTRAN SOBRE LA LINEA NEGRA*/
//   if (digitalRead(TCRT_T_1) || digitalRead(TCRT_T_2)) {
//     adelante();
//     t = millis();
//     do {
//       if ((HCSR_D.Distance() < MAXRANGE) || (HCSR_I.Distance() < MAXRANGE) || centrado() || (regleta() > 0B00000000)) {
//         return 0;
//       }
//     } while ((millis() - t) < DISSEC);
//   }
//   /*ALGUNO DE LOS SENSORES DE LA REGLETA SE ENCUENTRA SOBRE LA LINEA NEGRA*/
//   if (regleta() > 0B00000000) {
//     detener();
//     delay(5);
//     atras();
//     t = millis();
//     do {
//       if ((HCSR_D.Distance() < MAXRANGE) || (HCSR_I.Distance() < MAXRANGE) || digitalRead(TCRT_T_1) || digitalRead(TCRT_T_2)) {
//         return 0;
//       }
//     } while ((millis() - t) < DISSEC);
//   }
// }
// //
// //
// /*DEVUELVE TRUE SI EL OBJETO ESTA CENTRADO DELANTE DEL ROBOR*/
// /*DE LO CONTRARIO DEVOLVERA FALSE*/
// bool centrado() {
//   if (((HCSR_F_D.Distance() <= (HCSR_F_I.Distance() + MARGEN)) && (HCSR_F_D.Distance() >= (HCSR_F_I.Distance() - MARGEN))) || ((HCSR_F_I.Distance() <= (HCSR_F_D.Distance() + MARGEN)) && (HCSR_F_I.Distance() >= (HCSR_F_D.Distance() - MARGEN)))) {
//     return true;
//   } else {
//     return false;
//   }
// }
