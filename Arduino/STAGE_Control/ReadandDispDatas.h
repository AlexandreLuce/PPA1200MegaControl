/*******************************************************
* 
* 
* Read Datas Fonction
* 
* 
*******************************************************/

/**************************************
 * DC
 * 
 **************************************/

void ProcessDC(){
  dc[0] = digitalRead(ibuspins[0][8]);
  dc[1] = digitalRead(ibuspins[1][8]);
  //Serial.print("DC1 :");
  //Serial.println(DC1);
  //Serial.print("DC2 :");
  //Serial.println(DC2);
  if (dc[0] == 0 || dc[1] == 0) {
    if(dc[0] == 0 && PowerState[0] == 1){
      Pch1PopCallback();   
    }
    if(dc[1] == 0 && PowerState[1] == 1){
      Pch2PopCallback();   
    }
    if(CPage==2 || CPage == 3){
      DC.Set_font_color_pco(63521);
      msg.setText("DC Fail");
      LastMillis1=millis();
    }
  }
  else if(CPage==2 || CPage == 3){
    DC.Set_font_color_pco(34784);   
  }
  }


/**************************************
 * Signal
 * 
 **************************************/

void ProcessSignal(){
  signl[0] = analogRead(ibuspins[0][1]);
  signl[1] = analogRead(ibuspins[1][1]);
  //Serial.print("Signal 1 :");
  //Serial.println(Signal_1);
  //Serial.print("Signal 2 :");
  //Serial.println(Signal_2);
  if(CPage==2 || CPage == 3){
    if (signl[0]  > 0) {
      Signal1.setValue(1);     
    }
    else { 
      Signal1.setValue(0); 
    }
  }
  if(CPage == 2){ 
      if (signl[1] > 0) {
         Signal2.setValue(1);       
      }
      else { 
        Signal2.setValue(0);  
      }
    }
  }
/**************************************
 * Clip
 * 
 **************************************/

void ProcessClip(){
  clip[0] = analogRead(ibuspins[0][3]);
  clip[1] = analogRead(ibuspins[1][3]);
  //Serial.print("Clip 1 :");
  //Serial.println(Clip_1);
  //Serial.print("Clip 2 :");
  //Serial.println(Clip_2);
  if(CPage == 2){
    if (clip[0] > 100 && clip[0] < 550) {
      Clip1.Set_font_color_pco(34784);     
    }
    else { 
      Clip1.Set_font_color_pco(63521);
      msg.setText("CLIP CH1");
      LastMillis1=millis(); 
    }
    
    if (clip[1] > 100 && clip[1] < 550) {
      Clip2.Set_font_color_pco(34784);       
    }
    else { 
      Clip2.Set_font_color_pco(63521); 
      msg.setText("CLIP CH2"); 
      LastMillis1=millis();
   }
  }
  else if(CPage == 3){
    if (clip[0] > 100 && clip[0] < 550 && clip[1] > 100 && clip[1] < 550) 
    {
      Clip.Set_font_color_pco(34784);     
    }
    else { 
      Clip.Set_font_color_pco(63521);
      msgBR.setText("CLIP");
      LastMillis1=millis(); 
    }
   }
}


/**************************************
 * Supply
 * ************************************
 * 
 * 5 Volts = 120 Volts = 1024
 * 
 **************************************/

void ProcessSupply(){
  supply[0] = analogRead(ibuspins[0][0]);
  supply[1] = analogRead(ibuspins[1][0]);
  //Serial.print("Supply 1 :");
  //Serial.println(Supply_1);
  //Serial.print("Supply 2 :");
  //Serial.println(Supply_2);
  if(supply[0]>800) 
  {
  LastPwr1Millis=millis();
  } 
    if(supply[1]>800) 
  {
  LastPwr2Millis=millis();
  }   
  if(CPage==2){
    if(supply[0]>800) 
      {
      Ch1Pwr.setValue(1);
      }
    else if (supply[0]<800)
      {
      Ch1Pwr.setValue(0);
      }
    if(supply[1]>800) 
      {
      Ch2Pwr.setValue(1);
      }
    else if (supply[1]<800)
      {
      Ch2Pwr.setValue(0);
      }
  }
  else if(CPage==3){
    if(supply[0] > 800 && supply[1] > 800) 
      {
      PowerBR.setValue(1);
      }
    else if (supply[0] < 800 && supply[1] < 800)
      {
      PowerBR.setValue(0);
      }
  }
  else if (CPage==9){
    int supply1 = map(supply[0], 0, 1023, 0, 120);
    supplyCh1.setValue(supply1);
    
    int supply2 = map(supply[1], 0, 1023, 0, 120);
    supplyCh2.setValue(supply2);
  }
}

/**************************************
 * RMS Power RMS
 * 
 * ************************************
 * Current :
 * 
 *    1 Volt = 5 Amps = 204
 *    5 Volts = 25 Amps = 1024
 * 
 * Voltage To Confirm !! :
 * 
 *    1 Volt = 20 Volts = 204
 *    5 Volts = 100 Volts = 1024
 *    
 *    (U = root of (Watts * Ohms) ) 
 * 
 **************************************/

void ProcessPwrRMS(){
  for (int i=0; i<2; i=i+1){
   rmsV[i] = analogRead(ibuspins[i][5]);
   rmsV[i] = map(rmsV[i], 0, 1023, 0, 100);
   
   rmsI[i] = analogRead(ibuspins[i][6]);
   rmsI[i] = map(rmsI[i], 0, 1023, 0, 25);
  }
  if (CPage==9){
  rmsVCh1.setValue(rmsV[0] - 7);
  rmsVCh2.setValue(rmsV[1]);

  rmsICh1.setValue(rmsI[0]);
  rmsICh2.setValue(rmsI[1]);
  }
}

/**************************************
 * Peak Power
 * 
 **************************************/

void ProcessPwrPeak(){
  for (int i=0; i<2; i=i+1){
   peakV[i] = analogRead(ibuspins[i][7]);
   peakV[i] = map(peakV[i], 0, 1023, 0, 100);
   
   peakI[i] = analogRead(ibuspins[i][4]);
   peakI[i] = map(peakI[i], 0, 1023, 0, 25);
  }
  if (CPage==9){
  peakVCh1.setValue(peakV[0]);
  peakVCh2.setValue(peakV[1]);

  peakICh1.setValue(peakI[0]);
  peakICh2.setValue(peakI[1]);
  }
}

/**************************************
 * Up Time
 * 
 **************************************/

void ProcessUpTime(){
long unsigned int Cmillis = millis();
Cmillis = Cmillis / 60000;
if (CPage==9){
timeUp.setValue(Cmillis);
}
}
