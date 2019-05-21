/*******************************************************
*
*
* Volume control fonction
* 
* 
*******************************************************/

void SetVolume(byte setCH){
int VolNum = map(Volval[setCH],0,ADMaxVol,0,4095);
if (VolNum > 4095){
  VolNum = 4095;
}
int zeros = String(VolNum,BIN).length();     //This will check for the length of VolNum in binary.
String myStr;
for (int i=0; i < 12 - zeros; i++) {        //This will add zero to string as need
  myStr = myStr + "0";
}
myStr = myStr + String(VolNum,BIN);

for (int i=0; i < 12; i++){
char ADpinstate = myStr.charAt(i);
  if (ADpinstate == '0') {
     digitalWrite(buspins[i], LOW);   
     }
   else if (ADpinstate == '1') {
     digitalWrite(buspins[i], HIGH);
   }
}
  digitalWrite(CS_HC[setCH], LOW);           
  digitalWrite(CS_AD[setCH], LOW);
  delayMicroseconds(50);
  digitalWrite(CS_AD[setCH], HIGH); 
}

void Volume(bool dir, byte setCH){
  if (dir == HIGH) {
    //Serial.println("Send Vol+");
    if((Volval[setCH] + VolumeStep[setCH]) < MaxVol[setCH]){
      Volval[setCH] = Volval[setCH] + VolumeStep[setCH];
    }
    else if (Volval[setCH] < MaxVol[setCH]){
      Volval[setCH] = Volval[setCH] + 1;      
    }
  }
  else if (dir == LOW) {
    //Serial.println("Send Vol-");
    if((Volval[setCH] - VolumeStep[setCH]) >= 0){
      Volval[setCH] = Volval[setCH] - VolumeStep[setCH];
    }       
    else if (Volval[setCH] > 0){
      Volval[setCH] = Volval[setCH] - 1;
    }
  }
SetVolume(setCH);
}

void VolumeStop(byte setCH){
Volval[setCH] = 0;
SetVolume(setCH);
}

void VolumeStart(byte setCH){
Volval[setCH] = StartVol[setCH];
SetVolume(setCH);
}

/*******************************************************
* End of File 
*******************************************************/
