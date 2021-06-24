/* 
 *  Author      : Danu andrean
 *  title       : invers for hexapod 3DOF dynamixel
 *  date        : 2021
 *  referance   : http://te.unib.ac.id/lecturer/indraagustian/2014/05/3dof-inverse-kinematic-for-armleg-of-robot-use-arduino/
 */

#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

Dynamixel Dxl(DXL_BUS_SERIAL1);

byte coxa[]= {1, 4, 7, 10, 13, 16};
byte femur[]={2, 5, 8, 11, 14, 17};
byte tibia[]={3, 6, 9, 12, 15, 18};

float   degree_1=0, //dalam sudut
        degree_2=0,
        degree_3=0; 

double RATE = 0.01;
void setup()
{
  Serial2.begin(9600); 
  Dxl.begin(3);
  Dxl.wheelMode(20); //wheelMode() is to use wheel mode
  
  for(int i = 0; i<6; i++){
    Dxl.jointMode(coxa[i]); 
    Dxl.jointMode(femur[i]); 
    Dxl.jointMode(tibia[i]); 
  }
}
void loop()
{
  
  set_traj(7,2,-3); //contoh x,y,z
  
}
void run_servo(){
 for(int i=0; i<6; i++){
  Dxl.setPosition((coxa[i]),degree_1,300);
  Dxl.setPosition((femur[i]),degree_2,300);
  Dxl.setPosition((tibia[i]),degree_3,300);
 }
}
