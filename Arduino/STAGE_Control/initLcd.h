/*******************************************************
* Initialise Nextion LCD touchscreen 
* 
*******************************************************/

void InitLcd(){

// Initialisation de la librairie ITEAD pour Nextion.
nexInit();
attachNextion();
delay(1000);
//Init LCD
ImVol1.setValue(MaxVol[0]);
ImVol2.setValue(MaxVol[1]);
IsVol1.setValue(StartVol[0]);
IsVol2.setValue(StartVol[1]);
iFTemp.setValue(FanTemp);
iVolSync.setValue(VolSyncState);
iClift.setValue(CliftState);
iLift1.setValue(LiftState[0]);
iFilter1.setValue(FilterState[0]);
iLift2.setValue(LiftState[1]);
iFilter2.setValue(FilterState[1]);
iBridge.setValue(bridgeState);
iVolStep1.setValue(VolumeStep[0]);
iVolStep2.setValue(VolumeStep[1]);
iAutoStart1.setValue(AutoStartState[0]);
iAutoStart2.setValue(AutoStartState[1]);
iLClip1.setValue(ClipLState[0]);
iLClip2.setValue(ClipLState[1]);
iPwL1.setValue(PwLimit[0]);
iPwL2.setValue(PwLimit[1]);
iPwL1State.setValue(PwLimitState[0]);
iPwL2State.setValue(PwLimitState[1]);
sendCommand("page 1");
delay (500);
ProcessDC();
ProcessSignal();
ProcessClip();
ProcessPwr();
DisplayPwr();
ProcessSupply();
  if (bridgeState == 0){
    sendCommand("page 2");
    CPage = 2;
  }
  else if (bridgeState == 1){
    sendCommand("page 3");
    CPage = 3;
  }
}

/*******************************************************
* Initialise Nextion LCD message area
* 
*******************************************************/

void blankmsg(){
  if (CPage == 2 || CPage == 3){
  msg.setText("                 ");
  }
}

/*******************************************************
* Wait Message for start
* 
*******************************************************/

void waitmsg(){
  supply[0] = analogRead(ibuspins[0][0]);
  supply[1] = analogRead(ibuspins[1][0]);
  if(supply[0] > 35 || supply[1] > 35) 
  {
  int msgdelay = 10000;
  msg.setText("Wait 60 seconds");  
  delay(msgdelay);
  msg.setText("Wait 50 seconds");  
  delay(msgdelay);
  msg.setText("Wait 40 seconds");  
  delay(msgdelay);
  msg.setText("Wait 30 seconds");
  delay(msgdelay); 
  msg.setText("Wait 20 seconds");
  delay(msgdelay);
  msg.setText("Wait 10 seconds");
  delay(5000);
  msg.setText("Wait 5 seconds");
  delay(1000);
  msg.setText("Wait 4 seconds");
  delay(1000);
  msg.setText("Wait 3 seconds");
  delay(1000);
  msg.setText("Wait 2 seconds");
  delay(1000);
  msg.setText("Wait 1 seconds");
  } 
}

/*******************************************************
* End of File 
*******************************************************/
