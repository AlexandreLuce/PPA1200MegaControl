/*******************************************************
* 
* 
* Init Amplifier Fonction
* 
* 
*******************************************************/

#include "VolumeTable.h"
#include "RelayControl.h"
#include "VolumeControl.h"
#include "NextionObject.h"
#include "ProcessTemp.h"
#include "NextionCallback.h"
#include "ReadandDispDatas.h"
#include "attachNextion.h"
#include "initEEprom.h"
#include "initLcd.h"
#include "ProcessDatas.h"

void InitStates(){
      
   if (CliftState == 1){
    HCbusvalue[0][4] = 1;
    //Serial.println("Chassis Lift State ON");
   }
   else{
    HCbusvalue[0][4] = 0;
    //Serial.println("Chassis Lift State OFF");
   }
  if (LiftState[0] == 1){
    HCbusvalue[0][0] = 1;
    //Serial.println("Lift 1 State ON");
   }
   else{
    HCbusvalue[0][0] = 0;
    //Serial.println("Lift 1 State OFF");
   }
  if (FilterState[0] == 1){
    HCbusvalue[0][5] = 1;
    //Serial.println("Filter 1 State ON");
   }
   else{
    HCbusvalue[0][5] = 0;
    //Serial.println("Filter 1 State OFF");
   }
  if (LiftState[1] == 1){
    HCbusvalue[1][0] = 1;
    //Serial.println("Lift 2 State ON");
   }
   else{
    HCbusvalue[1][0] = 0;
    //Serial.println("Lift 2 State OFF");
   }
  if (FilterState[1] == 1){
    HCbusvalue[1][5] = 1;
    //Serial.println("Filter 2 State ON");
   }
   else{
    HCbusvalue[1][5] = 0;
    //Serial.println("Filter 2 State OFF");
   } 
   if (bridgeState == 1){
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
}

void AutoStart(){  
if(AutoStartState[0] == 1 || AutoStartState[1] == 1 && bridgeState == 0){
  msg.setText("AutoStart");
  delay(2000);
  if(AutoStartState[0] == 1 && AutoStartState[1] == 1){    
    msg.setText("AutoStart Ch1 Ch2");
    delay(10000);
    waitmsg();
    delay(500);
    Pch1PopCallback();
    delay(1500);
    Pch2PopCallback();
  }
  else if(AutoStartState[0] == 1 && AutoStartState[1] == 0){    
    msg.setText("AutoStart Ch1");
    delay(10000);
    waitmsg();
    delay(500);
    Pch1PopCallback();
  }
  else if(AutoStartState[0] == 0 && AutoStartState[1] == 1){    
    msg.setText("AutoStart Ch2");
    delay(10000);
    waitmsg();
    delay(500);
    Pch2PopCallback();
  }
}
else if(AutoStartState[0] == 0 && AutoStartState[1] == 0){
  waitmsg();  
}
msg.setText("Init OK");
LastMillis1=millis(); 
}

/*******************************************************
* End of File 
*******************************************************/
