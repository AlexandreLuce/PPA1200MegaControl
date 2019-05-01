/*******************************************************
* 
* 
* Init Amplifier Fonction
* 
* 
******************************************************** 
 74HC373 bus 0 Ground Lift Input
 74HC373 bus 1 Bridge Mode
 74HC373 bus 2 Power On/Off
 74HC373 bus 3 Out Relay
 74HC373 bus 4 Ground Lift Chassis / Fan High
 74HC373 bus 5 Filter On/Off
*******************************************************/

#include "VolumeTable.h"
#include "RelayControl.h"
#include "VolumeControl.h"
#include "NextionObject.h"
#include "NextionCallback.h"
#include "attachNextion.h"
#include "ReadandDispDatas.h"
#include "initEEprom.h"
#include "initLcd.h"
#include "ProcessDatas.h"

void InitBus(){
    //Init Pins
    //analogReference(DEFAULT);
    for(int i=0; i<12; i=i+1) pinMode(buspins[i], OUTPUT);  
    for(int i=0; i<2; i=i+1) pinMode(CS_HC[i], OUTPUT);
    for(int i=0; i<2; i=i+1) pinMode(CS_AD[i], OUTPUT);
    
   if (CliftState==1){
    HCbusvalue[0][4] = 1;
    //Serial.println("Chassis Lift State ON");
   }
   else{
    HCbusvalue[0][4] = 0;
    //Serial.println("Chassis Lift State OFF");
   }
  if (LiftState[0]==1){
    HCbusvalue[0][0] = 1;
    //Serial.println("Lift 1 State ON");
   }
   else{
    HCbusvalue[0][0] = 0;
    //Serial.println("Lift 1 State OFF");
   }
  if (FilterState[0]==1){
    HCbusvalue[0][5] = 1;
    //Serial.println("Filter 1 State ON");
   }
   else{
    HCbusvalue[0][5] = 0;
    //Serial.println("Filter 1 State OFF");
   }
  if (LiftState[1]==1){
    HCbusvalue[1][0] = 1;
    //Serial.println("Lift 2 State ON");
   }
   else{
    HCbusvalue[1][0] = 0;
    //Serial.println("Lift 2 State OFF");
   }
  if (FilterState[1]==1){
    HCbusvalue[1][5] = 1;
    //Serial.println("Filter 2 State ON");
   }
   else{
    HCbusvalue[1][5] = 0;
    //Serial.println("Filter 2 State OFF");
   } 
     if (bridgeState==1){
    HCbusvalue[0][1] = 1;
    HCbusvalue[1][1] = 1;
    //Serial.println("Bridge State ON");
   }
   else{
    HCbusvalue[0][1] = 0;
    HCbusvalue[1][1] = 0;
    //Serial.println("Bridge State OFF");
   }  
  }



void InitAmp(byte setCH) {
//Serial.print("Amp ");
//Serial.print(setCH);
//Serial.println(" Init");
// INIT AD7545 //INIT 74HC373
digitalWrite(CS_HC[setCH], LOW);
digitalWrite(CS_AD[setCH], HIGH);
digitalWrite(buspins[12], LOW);
digitalWrite(CS_HC[setCH], LOW);
digitalWrite(CS_AD[setCH], LOW);
delayMicroseconds(100);
digitalWrite(CS_AD[setCH], HIGH);
//Serial.print("Init "); 
//Serial.print(setCH);
//Serial.println(" AD Done"); 
for(int i=0; i<12; i=i+1) {
     bitval = HCbusvalue[setCH][i];
       if (bitval == 0) {
       digitalWrite(buspins[i], LOW);
       }
       else {
       digitalWrite(buspins[i], HIGH);
       }  
   }
digitalWrite(CS_HC[setCH], HIGH);
delayMicroseconds(100);  
digitalWrite(CS_HC[setCH], LOW);
//Serial.print("Init "); 
//Serial.print(setCH);
//Serial.println(" HC Done");

//Serial.print("StartVolume CH");
//Serial.print(setCH);
//Serial.print(" :");
//Serial.println(StartVol[setCH]);
for(int v=0; v < StartVol[setCH]; v=v+1) {
     Volume(HIGH,setCH);
   }
}
