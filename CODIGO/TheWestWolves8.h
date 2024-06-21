/////////////////////////////////////////
//      HEADER FILE WEST WOLVES 8      //
/////////////////////////////////////////
//
#include "GPIO.h"
/*Definicio macros pines*/
#if GPIO_DEFINED
#define M_A_E GPIO33
#define M_A_1 GPIO25
#define M_A_2 GPIO26
#define M_B_1 GPIO27
#define M_B_2 GPIO14
#define M_B_E GPIO12
#define TCRT_F_0 GPIO2
#define TCRT_F_1 GPIO3
#define TCRT_F_2 GPIO4
#define TCRT_F_3 GPIO5
#define TCRT_F_4 GPIO6
#define TCRT_T_1 GPIO7
#define TCRT_T_2 GPIO8
#endif
//
/*LIBRERIAS BLUETOOTH*/
#include <BTAddress.h>
#include <BTAdvertisedDevice.h>
#include <BTScan.h>
#include <BluetoothSerial.h>
//
/*Objeto tipo bluetooth*/
BluetoothSerial SerialBT;
//
/*Prototipo iniciacion de pines*/
void init();
//
/*HEADER FILE MOTORES*/
#include "MOTORES.h"
//
/*LIBRERIA CON PROGRAMA DEL SUMOBOT*/
#include "WW8SUMO.h"
//
/*LIBRERIA CON PROGRAMA DEL SUMOBOT*/
#include "WW8SigueLineas.h"
