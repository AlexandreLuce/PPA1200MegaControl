/*******************************************************
* 
* 
* Relays control Fonction
* 
* 
*******************************************************/

//74HC373 bus 0 Ground Lift Input
//74HC373 bus 1 Bridge Mode
//74HC373 bus 2 Power On/Off
//74HC373 bus 3 Out Relay
//74HC373 bus 4 Ground Lift Chassis / Fan High
//74HC373 bus 5 Filter On/Off

void sendHC(int buspin, byte setCH ) {
if (HCbusvalue[setCH][buspin] == 0) {
HCbusvalue[setCH][buspin] = 1;
}
else {
HCbusvalue[setCH][buspin] = 0;
}
  for(int i=0; i<12; i=i+1) {
     bitval = HCbusvalue[setCH][i];
       if (bitval == 0) {
       digitalWrite(buspins[i], LOW);
       }
       else {
       digitalWrite(buspins[i], HIGH);
       }  
   }
digitalWrite(CS_AD[setCH], HIGH);
digitalWrite(CS_HC[setCH], HIGH);
delayMicroseconds(25); 
digitalWrite(CS_HC[setCH], LOW);
//Serial.print("Send HC Amp ");
//Serial.print(setCH);
//Serial.print(", Relay ");
//Serial.print(buspin);
//Serial.println(" Done");
}

/*******************************************************
* End of File 
*******************************************************/
