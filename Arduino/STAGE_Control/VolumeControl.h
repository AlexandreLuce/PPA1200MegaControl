/*******************************************************
*
*
* Volume control fonction
* 
* 
*******************************************************/

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
  for(int i=0; i<12; i=i+1) {
    bitval = ADVol[Volval[setCH]][ADpin];
    if (bitval == 0) {
       digitalWrite(buspins[i], LOW);
       //Serial1.print("0");
       
       }
     else if (bitval == 1) {
       digitalWrite(buspins[i], HIGH);
       //Serial1.print("1");
       }
     ADpin = ADpin - 1;  
  } 
  ADpin = ADbus;  
  digitalWrite(CS_HC[setCH], LOW);           
  digitalWrite(CS_AD[setCH], LOW);
  delayMicroseconds(50);
  digitalWrite(CS_AD[setCH], HIGH); 
  //Serial.println();    
  //Serial.print("Volume Value 0:");
  //Serial.println(Volval[0]);
  //Serial.print("Volume Value 1:");
  //Serial.println(Volval[1]); 
}
