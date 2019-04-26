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
iLift1.setValue(Lift1State);
iFilter1.setValue(Filter1State);
iLift2.setValue(Lift2State);
iFilter2.setValue(Filter2State);
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
sendCommand("page 2");
CPage = 2;
ProcessTemp();
msg.setText("Init OK");
}

/*******************************************************
* Initialise Nextion LCD message area
* 
*******************************************************/

void blankmsg(){
  msg.setText("            ");
  }
