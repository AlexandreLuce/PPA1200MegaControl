/**************************************
 * Temperature and fan control
 * 
 **************************************/
 
void ProcessTemp(){
  //Temperature  
  float TempA0 = analogRead(ibuspins[0][2]);
  Temp[0] = TempA0 * 100 / 1023;
  float TempA1 = analogRead(ibuspins[1][2]);
  Temp[1] = TempA1 * 100 / 1023;
  //Serial.print("Temp CH1 :");
  //Serial.println(Temp[0]);
  //Serial.print("Temp CH2 :");
  //Serial.println(Temp[1]);
  if((Temp[0] >= FanTemp || Temp[1] >= FanTemp) && FanState == 0){
    sendHC(4,1);
    LastMillis1=millis();
    FanState = 1;
    msg.setText("Fan ON"); 
  }
  else if((Temp[0] < FanTemp-2 && Temp[1] < FanTemp-1) && FanState == 1){
   sendHC(4,1);
   LastMillis1=millis();
   FanState = 0; 
   msg.setText("Fan OFF"); 
  }
 if(CPage == 2 || CPage == 3 || CPage == 9){ 
  Temp1.setValue(Temp[0]);
  Temp2.setValue(Temp[1]);
  if(Temp[0] >= FanTemp){
   tTemp1.Set_font_color_pco(63521);
   Temp1.Set_font_color_pco(63521);
   tTempC1.Set_font_color_pco(63521);
  }
  if(Temp[1] >= FanTemp){
   tTemp2.Set_font_color_pco(63521);
   Temp2.Set_font_color_pco(63521);
   tTempC2.Set_font_color_pco(63521);
  }
  if(Temp[0] < FanTemp-1){
   tTemp1.Set_font_color_pco(26239);
   Temp1.Set_font_color_pco(26239);
   tTempC1.Set_font_color_pco(26239);
  }
  if(Temp[1] < FanTemp-1){
   tTemp2.Set_font_color_pco(26239);
   Temp2.Set_font_color_pco(26239);
   tTempC2.Set_font_color_pco(26239);
  }
 }
}
