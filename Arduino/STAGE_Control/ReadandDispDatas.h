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
      if(CPage==2 || CPage == 3){
      DC.Set_font_color_pco(63521);
      msg.setText("Ch1 DC Fail");
      LastMillis1=millis();
    }   
    }
    if(dc[1] == 0 && PowerState[1] == 1){
      Pch2PopCallback();
      if(CPage==2 || CPage == 3){
      DC.Set_font_color_pco(63521);
      msg.setText("Ch2 DC Fail");
      LastMillis1=millis();
     }   
    }
  }
  else if((CPage==2 || CPage == 3) && (millis() - disp_LastMillis1 > disp_timer1_DC)){
    DC.Set_font_color_pco(34784); 
    disp_LastMillis1 = millis();  
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
  for(int i=0; i<2; i=i+1){
    if(ClipLState[i] == 1 && PowerState[i] == 1){
      if (clip[i] < 100 || clip[i] > 550) {        
        Volume(LOW, i);
          if(i == 0){          
            Vol1.setValue(Volval[0]);
            msg.setText("CLIP Ch1 Vol Down");
          }
          else if(i == 1){          
            Vol2.setValue(Volval[1]);
            msg.setText("CLIP Ch2 Vol Down");
          }  
      }
    }
  } 
  if(CPage == 2){
    if (clip[0] > 100 || clip[0] < 550) {
      Clip1.Set_font_color_pco(34784);     
    }
    else { 
      Clip1.Set_font_color_pco(63521);
      msg.setText("CLIP CH1");
      LastMillis1=millis(); 
    }
    
    if (clip[1] > 100 || clip[1] < 550) {
      Clip2.Set_font_color_pco(34784);       
    }
    else { 
      Clip2.Set_font_color_pco(63521); 
      msg.setText("CLIP CH2"); 
      LastMillis1=millis();
   }
  }
  else if(CPage == 3){
    if (clip[0] > 100 || clip[0] < 550 || clip[1] > 100 || clip[1] < 550) 
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
  for (int i=0; i<2; i=i+1){
   if(supply[i]<800 && PowerState[i] == 1) 
   {
    VolumeStop(i);
    sendHC(3,i);  // Out
    delay(100);
    sendHC(2,i);  // Power
    PowerState[i] = 0;
    if(i == 0) 
   {          
    msg.setText("Ch1 Supply Fail");
    LastMillis1=millis();
   }
   else if(i == 1) 
   {          
    msg.setText("Ch2 Supply Fail");
    LastMillis1=millis();
   }
  }
 }
  if(supply[0] > 800) 
  {
  LastPwr1Millis=millis();
  } 
  if(supply[1] > 800) 
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
  else if (CPage==11){
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

void ProcessPwr(){
  for (int i=0; i<2; i=i+1){    
   rmsV[i] = analogRead(ibuspins[i][5]);
   rmsV[i] = map(rmsV[i], 0, 1023, 0, 1000);
   
   rmsI[i] = analogRead(ibuspins[i][6]);
   rmsI[i] = map(rmsI[i], 0, 1023, 0, 250);
   
   rmsW[i] = (rmsI[i] * rmsV[i]) / 100; 

   peakV[i] = analogRead(ibuspins[i][7]);
   peakV[i] = map(peakV[i], 0, 1023, 0, 1000);
   
   peakI[i] = analogRead(ibuspins[i][4]);
   peakI[i] = map(peakI[i], 0, 1023, 0, 250);
   
   peakW[i] = (peakI[i] * peakV[i]) / 100;

   int unsigned MaxPower = PwLimit[i] * 2;
       
      if(PwLimitState[i] == 1 && PowerState[i] == 1){
        if(rmsW[i] > PwLimit[i]|| peakW[i] > MaxPower){ 
         UnderPwr[i] = 0; 
         OverPwr[i] = OverPwr[i] + 1;
        }
        else if(peakW[i] < MaxPower && rmsW[i] < PwLimit[i] && Volval[i] < VolWanted[i]){ 
           OverPwr[i] = 0;
           UnderPwr[i] = UnderPwr[i] + 1;
        }           
        if(OverPwr[i] > 2){
          Volume(LOW, i);
          OverPwr[i] = 0;
            if(i == 0){          
              Vol1.setValue(Volval[0]);
              msg.setText("OverPwr 1 Vol Dw");
            }
            else if(i == 1){          
              Vol2.setValue(Volval[1]);
              msg.setText("OverPwr 2 Vol Dw");
            }          
        }
        else if(UnderPwr[i] > 20){
          Volume(HIGH, i);
          UnderPwr[i] = 0;
          if(i == 0){          
            Vol1.setValue(Volval[0]);
            msg.setText("UnderPwr 1 Vol Up");
          }
          else if(i == 1){          
            Vol2.setValue(Volval[1]);
            msg.setText("UnderPwr 2 Vol Up");
          }   
        }  
      }
    }
 }

/**************************************
 * Peak Power
 * 
 **************************************/

void DisplayPwr(){  
   peakWCh1.setValue(peakW[0]);
   peakWCh2.setValue(peakW[1]);
   rmsWCh1.setValue(rmsW[0]);
   rmsWCh2.setValue(rmsW[1]);
}

/**************************************
 * Up Time
 * 
 **************************************/

void ProcessUpTime(){
long unsigned int Cmillis = millis();
Cmillis = Cmillis / 60000;
 if (CPage==11){
  timeUp.setValue(Cmillis);
 }
}

/*******************************************************
* End of File 
*******************************************************/
