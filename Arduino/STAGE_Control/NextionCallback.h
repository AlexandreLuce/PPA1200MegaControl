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
    if(supply[0] < 800 && PowerState[0] == 0 && dc[0] == 1 && millis() - LastPwr1Millis > timer8_ChPwr)
    {
    sendHC(2,0);  //Power
    delay(400);
    sendHC(3,0);  // Out
    Ch1Pwr.setValue(1);
    PowerState[0] = 1;
    msg.setText("Ch1 ON");
    LastMillis1=millis();
    VolumeStart(0);
    Vol1.setValue(Volval[0]);
    }
    else if(supply[0] < 800 && PowerState[0] == 0 && dc[0] == 1 && millis() - LastPwr1Millis < timer8_ChPwr) 
    {
      msg.setText("Wait for Ch1 ON");
      LastMillis1=millis();
    }
    else if (supply[0]>800 && PowerState[0] == 1)
    {
    VolumeStop(0);
    Vol1.setValue(Volval[0]);
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
    VolWanted[0] = Volval[0];
    if(VolSyncState == 1){
      Volume(HIGH,1);      
      Vol2.setValue(Volval[1]);
      VolWanted[1] = Volval[1];
      }    
}

/**************************************
 * Volume Down Channel 1
 **************************************/
void Vmin1PopCallback(void *ptr)
{
    Volume(LOW,0);    
    Vol1.setValue(Volval[0]);
    VolWanted[0] = Volval[0];
    if(VolSyncState == 1){
      Volume(LOW,1);      
      Vol2.setValue(Volval[1]);
      VolWanted[1] = Volval[1];
      }   
}

/**************************************
 * Power Channel 2
 **************************************/
void Pch2PopCallback()
{
    
    if(supply[1]<800 && PowerState[1] == 0 && dc[1] == 1 && millis() - LastPwr2Millis > timer8_ChPwr) 
    {
    sendHC(2,1);  //Power
    delay(400);
    sendHC(3,1);  // Out
    Ch2Pwr.setValue(1);
    PowerState[1] = 1;
    msg.setText("Ch2 ON");
    LastMillis1=millis();
    VolumeStart(1);
    Vol2.setValue(Volval[1]);
    }
    else if(supply[1]<800 && PowerState[1] == 0 && dc[1] == 1 && millis() - LastPwr2Millis < timer8_ChPwr) 
    {
      msg.setText("Wait for Ch2 ON");
      LastMillis1=millis();
    }
    
    else if (supply[1]>800 && PowerState[1] == 1)
    {
    VolumeStop(1);
    Vol2.setValue(Volval[1]);
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
    VolWanted[1] = Volval[1];
    Vol2.setValue(Volval[1]);  
    if(VolSyncState == 1){
      Volume(HIGH,0);
      VolWanted[1] = Volval[1];      
      Vol1.setValue(Volval[0]);
      }   
}

/**************************************
 * Volume Down Channel 2
 **************************************/
void Vmin2PopCallback()
{
    Volume(LOW,1);    
    VolWanted[1] = Volval[1];
    Vol2.setValue(Volval[1]);
    if(VolSyncState == 1){
      Volume(LOW,0);
      VolWanted[1] = Volval[1];      
      Vol1.setValue(Volval[0]);
      }     
}

/**************************************
 * 
 * Page : Home Bridge
 * 
 **************************************/

/**************************************
 * Power Channels
 **************************************/
void PowerPopCallback()
{
  if(supply[0]<800 && PowerState[0] == 0 && dc[0] == 1 && millis() - LastPwr1Millis > timer8_ChPwr && supply[1]<800 && PowerState[1] == 0 && dc[1] == 1 && millis() - LastPwr2Millis > timer8_ChPwr)
    {
    sendHC(2,0);  //Power 1
    delay(400);
    sendHC(2,1);  //Power 2
    delay(400);
    sendHC(3,0);  // Out 1
    sendHC(3,1);  // Out 2
    PowerBR.setValue(1);
    LastPwr1Millis=millis();
    LastPwr2Millis=millis();
    PowerState[0] = 1;
    PowerState[1] = 1;
    msg.setText("Power ON");
    LastMillis1=millis();
    StartVol[1] = StartVol[0];
    VolumeStart(0);
    VolumeStart(1);
    Vol.setValue(Volval[0]);
    }
    else if(supply[0]<800 && PowerState[0] == 0 && dc[0] == 1 && millis() - LastPwr1Millis < timer8_ChPwr || supply[1]<800 && PowerState[1] == 0 && dc[1] == 1 && millis() - LastPwr2Millis < timer8_ChPwr) 
    {
      msg.setText("Wait for Power");
      LastMillis1=millis();
    }
    else if (supply[0]>800 && PowerState[0] == 1 && supply[1]>800 && PowerState[1] == 1)
    {
    VolumeStop(0);
    Vol.setValue(Volval[0]);
    sendHC(2,0);  // Out 1
    sendHC(2,1);  // Out 2
    delay(200);
    sendHC(3,0);  // Power 1
    sendHC(3,1);  // Power 2
    PowerBR.setValue(0);
    PowerState[0] = 0;
    PowerState[1] = 0;
    msg.setText("Power OFF");
    LastMillis1=millis();
    }
}

/**************************************
 * Volume Up
 **************************************/
void VplusPopCallback(){
Volume(HIGH,0);
Volume(HIGH,1);
Vol.setValue(Volval[0]);
}


/**************************************
 * Volume Down
 **************************************/
void VminPopCallback()
{
Volume(LOW,0);
Volume(LOW,1);
Vol.setValue(Volval[0]);
}

/************************************
 * 
 * Page : Common Settings
 * 
*************************************/

/**************************************
 * Chassis Lift activation
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
 * Bridge activation
 **************************************/
void SelectbridgePopCallback()
{
    if(bridgeState == 1) 
    {
    bridge.setValue(0);
    bridge.setText("Bridge Inactive");
    bridgeState = 0;
    VolSyncState = 0;
    VolSync.setValue(0);
    VolSync.setText("Volume Sync Inactive");
    if (PowerState[0] == 1){
      Pch1PopCallback();
    }
    if (PowerState[1] == 1){
      Pch2PopCallback();
    }
    delay(100);
    sendHC(1,0);  // Bridge
    sendHC(1,1);  // Bridge
    }
    else if (bridgeState == 0)
    {
    if (PowerState[0] == 1){
      Pch1PopCallback();
    }
    if (PowerState[1] == 1){
      Pch2PopCallback();
    }
    bridge.setValue(1);
    bridge.setText("Bridge Active");
    bridgeState = 1;
    VolSyncState = 1;
    VolSync.setValue(1);
    VolSync.setText("Volume Sync Active");
    delay(100);
    sendHC(1,0);  // Bridge
    sendHC(1,1);  // Bridge
    }
}

/**************************************
 * Volume Sync activation
 **************************************/
void SelectVolSyncPopCallback()
{
    if(VolSyncState == 1 && bridgeState == 0) 
    {
    VolSyncState = 0;
    VolSync.setValue(0);
    VolSync.setText("Volume Sync Inactive");
    }
    else if (VolSyncState == 0 && bridgeState == 0)
    {
    VolSyncState = 1;
    VolSync.setValue(1);
    VolSync.setText("Volume Sync Active");
    }
}

/**************************************
 * AutoStart 1 activation
 **************************************/
void SAutostart1PopCallback()
{
  if(AutoStartState[0] == 0) 
  {
    AutoStartState[0] = 1;
    Autostart1.setValue(1); 
  }
  else if(AutoStartState[0] == 1) 
  {
    AutoStartState[0] = 0;
    Autostart1.setValue(0); 
  }
}

/**************************************
 * AutoStart 2 activation
 **************************************/
void SAutostart2PopCallback()
{
  if(AutoStartState[1] == 0) 
  {
    AutoStartState[1] = 1;
    Autostart2.setValue(1);  
  }
  else if(AutoStartState[1] == 1) 
  {
    AutoStartState[1] = 0;
    Autostart2.setValue(0);
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
EEPROM.update(22, AutoStartState[0]);
EEPROM.update(24, AutoStartState[1]);
}

/***********************************
 * 
 * Page : Channel 1 Settings
 * 
***********************************/

/**************************************
 * Input Lift activation
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
     if (PowerState[0] == 1){
      sendHC(3,setAmp);
    }
      delay(100);
      sendHC(5,setAmp);
      delay(200);
     if (PowerState[0] == 1){
      sendHC(3,setAmp);
     }
    }
    else if(FilterState[0] == 1) 
    {
      filter1.setValue(0);
      FilterState[0]=0;
      filter1.setText("Filter Inactive");
      setAmp = 0;
      if (PowerState[0] == 1){
        sendHC(3,setAmp);
      }
      delay(100);
      sendHC(5,setAmp);
      delay(300);
      if (PowerState[0] == 1){
        sendHC(3,setAmp);
      }
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
 * Clip Limiter activation
 **************************************/
void SClipLimCh1PopCallback()
{
    if(ClipLState[0] == 0) 
    {
    ClipLimCh1.setValue(1);
    ClipLimCh1.setText("Clip Limiter Active");
    ClipLState[0] = 1;
    }
    else if(ClipLState[0] == 1) 
    {
    ClipLimCh1.setValue(0);
    ClipLimCh1.setText("Clip Limiter Inactive");
    ClipLState[0] = 0;
    }
}

/**************************************
 * Power Limiter
 **************************************/

void SPwLim1PopCallback()
{
    if(PwLimitState[0] == 0) 
    {
    PwLim1.setValue(1);
    PwLim1.setText("Power Limiter Active");
    PwLimitState[0] = 1;
    }
    else if(PwLimitState[0] == 1) 
    {
    PwLim1.setValue(0);
    PwLim1.setText("Power Limiter Inactive");
    PwLimitState[0] = 0;
    }
}

void PUpCh1PopCallback()
{   
    if (PwLimit[0] < 905){
    PwLimit[0] = PwLimit[0] + 5;
    }      
    PLimCh1.setValue(PwLimit[0]);  
}

void PDwCh1PopCallback()
{   
    if (PwLimit[0] > 0){
    PwLimit[0] = PwLimit[0] - 5;
    }      
    PLimCh1.setValue(PwLimit[0]);  
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
  EEPROM.update(26, ClipLState[0]);
  EEPROM.update(28, PwLimit[0]);
  EEPROM.update(34, PwLimitState[0]);
   
}

/*************************************
 * 
 * Channel 2 Settings
 * 
 *************************************/

/**************************************
 * Input Lift activation
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
      if (PowerState[1] == 1){
      sendHC(3,setAmp);
      }
      delay(100);
      sendHC(5,setAmp);
      delay(300);
      if (PowerState[1] == 1){
      sendHC(3,setAmp);
      }
    }
    else if(FilterState[1]==1) 
    {
      filter2.setValue(0);
      FilterState[1]=0;
      filter2.setText("Filter Inactive");
      setAmp = 1;
      if (PowerState[1] == 1){
      sendHC(3,setAmp);
      }
      delay(100);
      sendHC(5,setAmp);
      delay(200);
      if (PowerState[1] == 1){
      sendHC(3,setAmp);
    }
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
 * Clip Limiter activation
 **************************************/
void SClipLimCh2PopCallback()
{
    if(ClipLState[1] == 0) 
    {
    ClipLimCh2.setValue(1);
    ClipLimCh2.setText("Clip Limiter Active");
    ClipLState[1] = 1;
    }
    else if(ClipLState[1] == 1) 
    {
    ClipLimCh2.setValue(0);
    ClipLimCh2.setText("Clip Limiter Inactive");
    ClipLState[1] = 0;
    }
}

/**************************************
 * Power Limiter
 **************************************/

void SPwLim2PopCallback()
{
    if(PwLimitState[1] == 0) 
    {
    PwLim2.setValue(1);
    PwLim2.setText("Power Limiter Active");
    PwLimitState[1] = 1;
    }
    else if(PwLimitState[1] == 1) 
    {
    PwLim2.setValue(0);
    PwLim2.setText("Power Limiter Inactive");
    PwLimitState[1] = 0;
    }
}

void PUpCh2PopCallback()
{   
    if (PwLimit[1] < 905){
    PwLimit[1] = PwLimit[1] + 5;
    }      
    PLimCh2.setValue(PwLimit[1]);  
}

void PDwCh2PopCallback()
{   
    if (PwLimit[1] > 0){
    PwLimit[1] = PwLimit[1] - 5;
    }      
    PLimCh2.setValue(PwLimit[1]);  
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
  EEPROM.update(30, ClipLState[1]);
  EEPROM.update(32, PwLimit[1]);
  EEPROM.update(36, PwLimitState[1]); 
}

/*************************************
 * 
 * Navigation between pages
 * 
 *************************************/

void goInfoPagePopCallback()
{   
sendCommand("page 11");
CPage = 11;
ProcessTemp();
}

void backHomePopCallback()
{   
  if (bridgeState == 0){
  sendCommand("page 2");
  CPage = 2;
  ProcessTemp();
  }
  else if (bridgeState == 1){
  sendCommand("page 3");
  CPage = 3;
  ProcessTemp();
  }
}

void goSettingsPopCallback()
{   
sendCommand("page 4");
CPage = 4;
}

/*******************************************************
* End of File 
*******************************************************/

 
