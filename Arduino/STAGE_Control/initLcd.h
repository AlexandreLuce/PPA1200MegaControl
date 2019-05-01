/*******************************************************
* Initialise Nextion LCD touchscreen 
* 
*******************************************************/

void InitLcd(){

// Initialisation de la librairie ITEAD pour Nextion.
nexInit();
attachNextion();
delay(1500);
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
delay (500);
sendCommand("page 1");
delay (1000);
ProcessDC();
ProcessSignal();
ProcessClip();
ProcessPwrRMS();
ProcessPwrPeak();
ProcessSupply();
  if (bridgeState == 0){
    sendCommand("page 2");
    CPage = 2;
  }
  else if (bridgeState == 1){
    sendCommand("page 3");
    CPage = 3;
  }
ProcessTemp();
Temp1.setValue(Temp[0]);
Temp2.setValue(Temp[1]);
msg.setText("Init OK");
LastMillis1=millis();
}

/*******************************************************
* Initialise Nextion LCD message area
* 
*******************************************************/

void blankmsg(){
  if (CPage == 2 || CPage == 3){
  msg.setText("               ");
  }
}
