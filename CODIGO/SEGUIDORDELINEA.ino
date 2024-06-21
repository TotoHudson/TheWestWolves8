#define GPIO0 0
#define GPIO1 1
#define GPIO2 2
#define GPIO3 3
#define GPIO4 4
#define GPIO5 5
#define GPIO6 6
#define GPIO7 7
#define GPIO8 8
#define GPIO9 9
#define GPIO10  10
#define GPIO12  12
#define GPIO13  13
#define GPIO14  14
#define GPIO15  15
#define GPIO16  16
#define GPIO17  17
#define GPIO18  18
#define GPIO19  19
#define GPIO21  21
#define GPIO22  22
#define GPIO23  23
#define GPIO25  25
#define GPIO26  26
#define GPIO27  27
#define GPIO32  32
#define GPIO33  33
#define GPIO34  34
#define GPIO35  35
#define GPIO36  36
#define GPIO39  39
#define M_D_1 GPIO15
#define M_D_2 GPIO16
#define M_D_E GPIO22
#define M_I_1 GPIO17
#define M_I_2 GPIO18
#define M_I_E GPIO19
#define TCRT_F_0 GPIO2
#define TCRT_F_1 GPIO3
#define TCRT_F_2 GPIO4
#define TCRT_F_3 GPIO5
#define TCRT_F_4 GPIO6
#define TCRT_T_1 GPIO7
#define TCRT_T_2 GPIO8
const int temp = 0;
int a = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
   a = mapfloat(digitalRead(TCRT_F_0), digitalRead(TCRT_F_1), digitalRead(TCRT_F_2), digitalRead(TCRT_F_3), digitalRead(TCRT_F_4), digitalRead(TCRT_T_1), digitalRead(TCRT_T_2));
  arranque();
  while(a == 12){
   digitalWrite(M_D_1, 1);
   digitalWrite(M_D_2, 0);
   analogWrite(M_I_E, 255);
   digitalWrite(M_I_1, 1);
   digitalWrite(M_I_2, 0);
   analogWrite(M_D_E, 255);
   a = mapfloat(digitalRead(TCRT_F_0), digitalRead(TCRT_F_1), digitalRead(TCRT_F_2), digitalRead(TCRT_F_3), digitalRead(TCRT_F_4), digitalRead(TCRT_T_1), digitalRead(TCRT_T_2));
  }
  while(a == 13 || a == 14){
   digitalWrite(M_D_1, 1);
   digitalWrite(M_D_2, 0);
   analogWrite(M_I_E, 128);
   digitalWrite(M_I_1, 1);
   digitalWrite(M_I_2, 0);
   analogWrite(M_D_E, 255);
   a = mapfloat(digitalRead(TCRT_F_0), digitalRead(TCRT_F_1), digitalRead(TCRT_F_2), digitalRead(TCRT_F_3), digitalRead(TCRT_F_4), digitalRead(TCRT_T_1), digitalRead(TCRT_T_2));
  }
  while(a == 11){
   digitalWrite(M_D_1, 1);
   digitalWrite(M_D_2, 0);
   analogWrite(M_I_E, 255);
   digitalWrite(M_I_1, 1);
   digitalWrite(M_I_2, 0);
   analogWrite(M_D_E, 128);
   a = mapfloat(digitalRead(TCRT_F_0), digitalRead(TCRT_F_1), digitalRead(TCRT_F_2), digitalRead(TCRT_F_3), digitalRead(TCRT_F_4), digitalRead(TCRT_T_1), digitalRead(TCRT_T_2));
  }
  while(a == 10){
   digitalWrite(M_D_1, 1);
   digitalWrite(M_D_2, 0);
   analogWrite(M_D_E, 0);
   digitalWrite(M_I_1, 1);
   digitalWrite(M_I_2, 0);
   analogWrite(M_I_E, 255);
   a = mapfloat(digitalRead(TCRT_F_0), digitalRead(TCRT_F_1), digitalRead(TCRT_F_2), digitalRead(TCRT_F_3), digitalRead(TCRT_F_4), digitalRead(TCRT_T_1), digitalRead(TCRT_T_2));
  }
  while(a == 15){
   digitalWrite(M_D_1, 1);
   digitalWrite(M_D_2, 0);
   analogWrite(M_I_E, 0);
   digitalWrite(M_I_1, 1);
   digitalWrite(M_I_2, 0);
   analogWrite(M_D_E, 255);
   a = mapfloat(digitalRead(TCRT_F_0), digitalRead(TCRT_F_1), digitalRead(TCRT_F_2), digitalRead(TCRT_F_3), digitalRead(TCRT_F_4), digitalRead(TCRT_T_1), digitalRead(TCRT_T_2));
  }
}


int mapfloat(int x, int y, int a,int b, int c, int d, int e)
{
  return 10*x + 10*y + a + b + c + d + e;
}

void arranque(){
  digitalWrite(M_D_1, 1);
   digitalWrite(M_D_2, 0);
   analogWrite(M_D_E, 255);
   digitalWrite(M_I_1, 0);
   digitalWrite(M_I_2, 1);
   analogWrite(M_I_E, 255);
   delay(temp);
   while (a > 20){
   digitalWrite(M_D_1, 1);
   digitalWrite(M_D_2, 0);
   analogWrite(M_D_E, 255);
   digitalWrite(M_I_1, 1);
   digitalWrite(M_I_2, 0);
   analogWrite(M_I_E, 255);
   }
   do{
   digitalWrite(M_D_1, 1);
   digitalWrite(M_D_2, 0);
   analogWrite(M_D_E, 1);
   digitalWrite(M_I_1, 1);
   digitalWrite(M_I_2, 0);
   analogWrite(M_I_E, 255);
   }while(a != 12);
}
