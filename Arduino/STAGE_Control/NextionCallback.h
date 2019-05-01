/**********************************************
 * 
 * 
 * Fonction callback appelée lorsque l'on appuie sur le 
 * bouton sur la tablette Nextion.
 * 
 * 
 *********************************************/


/**************************************
 * 
 * Page : Home Stereo
 * 
 **************************************/

/**************************************
 * Power Channel 1
 **************************************/
void Pch1PopCallback()
{
    if(supply[0]<800 && PowerState[0] == 0 && dc[0] == 1) 
    {
    sendHC(2,0);  //Power
    delay(400);
    sendHC(3,0);  // Out
    Ch1Pwr.setValue(1);
    PowerState[0] = 1;
    msg.setText("Ch1 ON");
    LastMillis1=millis();
    }
    else if (supply[0]>800 && PowerState[0] == 1)
    {
    sendHC(3,0);  // Out
    delay(100);
    sendHC(2,0);  // Power
    Ch1Pwr.setValue(0);
    PowerState[0] = 0;
    msg.setText("Ch1 OFF");
    LastMillis1=millis();
    }
}

/**************************************
 * Volume Up Channel 1
 **************************************/
 void Vplus1PopCallback(void *ptr)
{   
    Volume(HIGH,0);      
    Vol1.setValue(Volval[0]);
    if(VolSyncState == 1){
      Volume(HIGH,1);      
      Vol2.setValue(Volval[1]);
      }    
}

/**************************************
 * Volume Down Channel 1
 **************************************/
void Vmin1PopCallback(void *ptr)
{
    Volume(LOW,0);    
    Vol1.setValue(Volval[0]);
    if(VolSyncState == 1){
      Volume(LOW,1);      
      Vol2.setValue(Volval[1]);
      }   
}

/**************************************
 * Power Channel 2
 **************************************/
void Pch2PopCallback()
{
    
    if(supply[1]<800 && PowerState[1] == 0 && dc[1] == 1) 
    {
    sendHC(2,1);  //Power
    delay(400);
    sendHC(3,1);  // Out
    Ch2Pwr.setValue(1);
    PowerState[1] = 1;
    msg.setText("Ch2 ON");
    LastMillis1=millis();
    }
    else if (supply[1]>800 && PowerState[1] == 1)
    {
    sendHC(3,1);  // Out
    delay(100);
    sendHC(2,1);  // Power
    Ch2Pwr.setValue(0);
    PowerState[1] = 0;
    msg.setText("Ch2 OFF");
    LastMillis1=millis();
    }
}

/**************************************
 * Volume Up Channel 2
 **************************************/
void Vplus2PopCallback()
{
    Volume(HIGH,1);      
    Vol2.setValue(Volval[1]);  
    if(VolSyncState == 1){
      Volume(HIGH,0);      
      Vol1.setValue(Volval[0]);
      }   
}

/**************************************
 * Volume Down Channel 2
 **************************************/
void Vmin2PopCallback()
{
    Volume(LOW,1);    
    Vol2.setValue(Volval[1]);
    if(VolSyncState == 1){
      Volume(LOW,0);      
      Vol1.setValue(Volval[0]);
      }     
}

/************************************
 * 
 * Page : Common Settings
 * 
*************************************/

/**************************************
 * Chassis Lift
 **************************************/
void SelectCliftPopCallback()
{

    if(CliftState == 0) 
    {
    sendHC(4,0);
    Clift.setValue(1);
    Clift.setText("Chassis Lift Active");
    CliftState = 1;
    }
    else if(CliftState == 1) 
    {
    sendHC(4,0);
    Clift.setValue(0);
    Clift.setText("Chassis Lift Inactive");
    CliftState = 0;
    }
}

/**************************************
 * Bridge
 **************************************/
void SelectbridgePopCallback()
{

}

/**************************************
 * Volume Sync
 **************************************/
void SelectVolSyncPopCallback()
{
    if(VolSyncState == 1) 
    {
    VolSyncState = 0;
    VolSync.setValue(0);
    VolSync.setText("Volume Sync Inactive");
    }
    else if (VolSyncState == 0)
    {
    VolSyncState = 1;
    VolSync.setValue(1);
    VolSync.setText("Volume Sync Active");
    }
}

/**************************************
 * Fan activation temperature
 **************************************/
void FTplusPopCallback()
{   
  if (FanTemp < 65){
    FanTemp = FanTemp + 1;    
  }  
    FTemp.setValue(FanTemp);  
}

void FTminPopCallback(void *ptr)
{   
  if (FanTemp > 20){
    FanTemp = FanTemp - 1;   
  }     
    FTemp.setValue(FanTemp);  
}

/**************************************
 * Save preset
 **************************************/
void savesetPopCallback()
{  
EEPROM.update(3, CliftState);
EEPROM.update(1, VolSyncState);
EEPROM.update(20, bridgeState);
EEPROM.update(0, FanTemp);

}

/***********************************
 * 
 * Page : Channel 1 Settings
 * 
***********************************/

/**************************************
 * Input Lift
 **************************************/
void Selectlift1PopCallback()
{
    if(LiftState[0] == 0) 
    {
    lift1.setValue(1);
    lift1.setText("Input Lift Active");
    sendHC(0,0);
    LiftState[0] = 1;
    }
    else if(LiftState[0] == 1) 
    {
    lift1.setValue(0);
    lift1.setText("Input Lift Inactive");
    sendHC(0,0);
    LiftState[0] = 0;
    }
}
/**************************************
 * Filter activation
 **************************************/
void Selectfilter1PopCallback()
{
    if(FilterState[0] == 0) 
    {
      filter1.setValue(1);
      filter1.setText("Filter Active");
      FilterState[0]=1;
      setAmp = 0;
      sendHC(3,setAmp);
      delay(100);
      sendHC(5,setAmp);
      delay(300);
      sendHC(3,setAmp);
    }
    else if(FilterState[0] == 1) 
    {
      filter1.setValue(0);
      FilterState[0]=0;
      filter1.setText("Filter Inactive");
      setAmp = 0;
      sendHC(3,setAmp);
      delay(100);
      sendHC(5,setAmp);
      delay(300);
      sendHC(3,setAmp);
    }
}

/**************************************
 * Volume step
 **************************************/
void VolStepUp1PopCallback() {
  if(VolumeStep[0] < 5){
    VolumeStep[0] = VolumeStep[0] + 1;  
  }
  VolStep1.setValue(VolumeStep[0]); 
}

void VolStepDw1PopCallback() {
  if(VolumeStep[0] > 1){
    VolumeStep[0] = VolumeStep[0] - 1;  
  }
  VolStep1.setValue(VolumeStep[0]);
}


/**************************************
 * Start volume
 **************************************/
void SvolUp1PopCallback()
{   
    if (StartVol[0] < MaxVol[0]){
    StartVol[0] = StartVol[0] + 1;
    }      
    sVol1.setValue(StartVol[0]);  
}

void SvolDw1PopCallback()
{   
    if (StartVol[0] > 0){
    StartVol[0] = StartVol[0] - 1;
    }      
    sVol1.setValue(StartVol[0]);  
}

/**************************************
 * Max volume
 **************************************/
void MvolUp1PopCallback()
{   
    if (MaxVol[0] < 80){
    MaxVol[0] = MaxVol[0] + 1;
    }      
    mVol1.setValue(MaxVol[0]);  
}

void MvolDw1PopCallback()
{   
    if (MaxVol[0] > 0){
    MaxVol[0] = MaxVol[0] - 1;
    }      
    mVol1.setValue(MaxVol[0]);  
}

/**************************************
 * Save
 **************************************/
void save1PopCallback()
{   
  EEPROM.update(5, FilterState[0]);
  EEPROM.update(4, LiftState[0]);
  EEPROM.update(7, MaxVol[0]);
  EEPROM.update(6, StartVol[0]);
  EEPROM.update(18, VolumeStep[0]);
  
}
/*************************************
 * 
 * Channel 2 Settings
 * 
 *************************************/

/**************************************
 * Input Lift
 **************************************/
void Selectlift2PopCallback()
{
    if(LiftState[1] == 0) 
    {
    lift2.setValue(1);
    lift2.setText("Input Lift Active");
    sendHC(0,1);
    LiftState[1] = 1;
    }
    else if(LiftState[1] == 1) 
    {
    lift2.setValue(0);
    lift2.setText("Input Lift Inactive");
    sendHC(0,1);
    LiftState[1] = 0;
    }
}

/**************************************
 * Filter activation
 **************************************/
void Selectfilter2PopCallback()
{
     if(FilterState[1] == 0) 
    {
      filter2.setValue(1);
      filter2.setText("Filter Active");
      FilterState[1]=1;
      setAmp = 1;
      sendHC(3,setAmp);
      delay(100);
      sendHC(5,setAmp);
      delay(300);
      sendHC(3,setAmp);
    }
    else if(FilterState[1]==1) 
    {
      filter2.setValue(0);
      FilterState[1]=0;
      filter2.setText("Filter Inactive");
      setAmp = 1;
      sendHC(3,setAmp);
      delay(100);
      sendHC(5,setAmp);
      delay(300);
      sendHC(3,setAmp);
    }
}

/**************************************
 * Volume step
 **************************************/
void VolStepUp2PopCallback() {
  if(VolumeStep[1] < 5){
    VolumeStep[1] = VolumeStep[1] + 1;
  } 
  VolStep2.setValue(VolumeStep[1]);
}

void VolStepDw2PopCallback() {
  if(VolumeStep[1] > 1){
    VolumeStep[1] = VolumeStep[1] - 1;  
  }
  VolStep2.setValue(VolumeStep[1]);
}

/**************************************
 * Start volume
 **************************************/
void SvolUp2PopCallback() {   
  if (StartVol[1] < MaxVol[1]){
    StartVol[1] = StartVol[1] + 1;
  }      
sVol2.setValue(StartVol[1]);  
}

void SvolDw2PopCallback()
{   
    if (StartVol[1] > 0){
    StartVol[1] = StartVol[1] - 1;
    }      
    sVol2.setValue(StartVol[1]);  
}

/**************************************
 * Max volume
 **************************************/
void MvolUp2PopCallback()
{   
    if (MaxVol[1] < 80){
    MaxVol[1] = MaxVol[1] + 1;
    }      
    mVol2.setValue(MaxVol[1]);  
}

void MvolDw2PopCallback()
{   
    if (MaxVol[1] > 0){
    MaxVol[1] = MaxVol[1] - 1;
    }      
    mVol2.setValue(MaxVol[1]);  
}

/**************************************
 * Save
 **************************************/
void save2PopCallback()
{   
  EEPROM.update(9, FilterState[1]);
  EEPROM.update(8, LiftState[1]);
  EEPROM.update(11, MaxVol[1]);
  EEPROM.update(15, StartVol[1]);
  EEPROM.update(16, VolumeStep[1]);
}

/*************************************
 * 
 * Navigation between pages
 * 
 *************************************/

void goInfoPagePopCallback()
{   
sendCommand("page 9");
CPage = 9;
}

void backInfoPopCallback()
{   
sendCommand("page 2");
CPage = 2;
}

void goSettingsPopCallback()
{   
sendCommand("page 4");
CPage = 4;
}

void backSetPopCallback()
{   
sendCommand("page 2");
CPage = 2;
}



 
