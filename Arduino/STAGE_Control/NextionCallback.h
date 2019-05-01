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
void Pch1PopCallback(void *ptr)
{
    if(supply[0]<800) 
    {
    sendHC(2,0);  //Power
    delay(400);
    sendHC(3,0);  // Out
    Ch1Pwr.setValue(1);
    msg.setText("Ch1 ON");
    LastMillis1=millis();
    }
    else if (supply[0]>800)
    {
    sendHC(3,0);  // Out
    delay(100);
    sendHC(2,0);  // Power
    Ch1Pwr.setValue(0);
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
void Pch2PopCallback(void *ptr)
{
    
    if(supply[1]<800) 
    {
    sendHC(2,1);  //Power
    delay(400);
    sendHC(3,1);  // Out
    Ch2Pwr.setValue(1);
    msg.setText("Ch2 ON");
    LastMillis1=millis();
    }
    else if (supply[1]>800)
    {
    sendHC(3,1);  // Out
    delay(100);
    sendHC(2,1);  // Power
    Ch2Pwr.setValue(0);
    msg.setText("Ch2 OFF");
    LastMillis1=millis();
    }
}

/**************************************
 * Volume Up Channel 2
 **************************************/
void Vplus2PopCallback(void *ptr)
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
void Vmin2PopCallback(void *ptr)
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
void CliftPopCallback(void *ptr)
{
    uint32_t dual_state;
    NexDSButton *btn = (NexDSButton *)ptr;
    memset(buffer, 0, sizeof(buffer));

    /* Get the state value of dual state button component . */
    Clift.getValue(&dual_state);
    if(dual_state==1) 
    {
    sendHC(4,0);
    }
    else
    {
    sendHC(4,0);
    }
}

/**************************************
 * Volume Sync
 **************************************/
void VolSyncPopCallback(void *ptr)
{
    uint32_t dual_state;
    NexDSButton *btn = (NexDSButton *)ptr;
    memset(buffer, 0, sizeof(buffer));

    /* Get the state value of dual state button component . */
    VolSync.getValue(&dual_state);
    if(dual_state==1) 
    {
    VolSyncState = 1;
    }
    else
    {
    VolSyncState = 0;
    }
}

/**************************************
 * Fan activation temperature
 **************************************/
void FTplusPopCallback(void *ptr)
{   
    FanTemp = FanTemp + 1;      
    FTemp.setValue(FanTemp);  
}

void FTminPopCallback(void *ptr)
{   
    FanTemp = FanTemp - 1;        
    FTemp.setValue(FanTemp);  
}

/**************************************
 * Save preset
 **************************************/
void savesetPopCallback(void *ptr)
{  
  uint32_t liftc_state; 
Clift.getValue(&liftc_state);
EEPROM.update(3, liftc_state);
uint32_t sync_state;
VolSync.getValue(&sync_state);
EEPROM.update(1, sync_state);
uint32_t bridge_state;
bridge.getValue(&bridge_state);
EEPROM.update(20, bridge_state);

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
void lift1PopCallback(void *ptr)
{
    uint32_t dual_state;
    NexDSButton *btn = (NexDSButton *)ptr;
    memset(buffer, 0, sizeof(buffer));

    /* Get the state value of dual state button component . */
    lift1.getValue(&dual_state);
    if(dual_state) 
    {
    sendHC(0,0);
    }
    else
    {
    sendHC(0,0);
    }
}
/**************************************
 * Filter activation
 **************************************/
void filter1PopCallback(void *ptr)
{
    if(FilterState[0]==0) 
    {
      filter1.setValue(1);
      FilterState[0]=1;
      setAmp = 0;
      sendHC(3,setAmp);
      delay(100);
      sendHC(5,setAmp);
      delay(300);
      sendHC(3,setAmp);
    }
    else if(FilterState[0]==1) 
    {
      filter1.setValue(0);
      FilterState[0]=0;
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
void VolStepUp1PopCallback(void *ptr) {
  if(VolumeStep[0] < 5){
    VolumeStep[0] = VolumeStep[0] + 1;  
  }
  VolStep1.setValue(VolumeStep[0]); 
}

void VolStepDw1PopCallback(void *ptr) {
  if(VolumeStep[0] > 1){
    VolumeStep[0] = VolumeStep[0] - 1;  
  }
  VolStep1.setValue(VolumeStep[0]);
}


/**************************************
 * Start volume
 **************************************/
void SvolUp1PopCallback(void *ptr)
{   
    if (StartVol[0] < MaxVol[0]){
    StartVol[0] = StartVol[0] + 1;
    }      
    sVol1.setValue(StartVol[0]);  
}

void SvolDw1PopCallback(void *ptr)
{   
    if (StartVol[0] > 0){
    StartVol[0] = StartVol[0] - 1;
    }      
    sVol1.setValue(StartVol[0]);  
}

/**************************************
 * Max volume
 **************************************/
void MvolUp1PopCallback(void *ptr)
{   
    if (MaxVol[0] < 80){
    MaxVol[0] = MaxVol[0] + 1;
    }      
    mVol1.setValue(MaxVol[0]);  
}

void MvolDw1PopCallback(void *ptr)
{   
    if (MaxVol[0] > 0){
    MaxVol[0] = MaxVol[0] - 1;
    }      
    mVol1.setValue(MaxVol[0]);  
}

/**************************************
 * Save
 **************************************/
void save1PopCallback(void *ptr)
{   
  EEPROM.update(5, FilterState[0]);
  uint32_t lift1_state;
  lift1.getValue(&lift1_state);
  EEPROM.update(4, lift1_state);
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
void lift2PopCallback(void *ptr)
{
    uint32_t dual_state;
    NexDSButton *btn = (NexDSButton *)ptr;
    memset(buffer, 0, sizeof(buffer));

    /* Get the state value of dual state button component . */
    lift2.getValue(&dual_state);
    if(dual_state) 
    {
    sendHC(0,1);
    }
    else
    {
    sendHC(0,1);
    }
}

/**************************************
 * Filter activation
 **************************************/
void filter2PopCallback(void *ptr)
{
    uint32_t dual_state;
    NexDSButton *btn = (NexDSButton *)ptr;
    memset(buffer, 0, sizeof(buffer));

    /* Get the state value of dual state button component . */
    filter2.getValue(&dual_state);
    if(dual_state) 
    {
      setAmp = 1;
      sendHC(3,setAmp);
      delay(100);
      sendHC(5,setAmp);
      delay(300);
      sendHC(3,setAmp);
    }
    else
    {
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
void VolStepUp2PopCallback(void *ptr) {
  if(VolumeStep[1] < 5){
    VolumeStep[1] = VolumeStep[1] + 1;
  } 
  VolStep2.setValue(VolumeStep[1]);
}

void VolStepDw2PopCallback(void *ptr) {
  if(VolumeStep[1] > 1){
    VolumeStep[1] = VolumeStep[1] - 1;  
  }
  VolStep2.setValue(VolumeStep[1]);
}

/**************************************
 * Start volume
 **************************************/
void SvolUp2PopCallback(void *ptr) {   
  if (StartVol[1] < MaxVol[1]){
    StartVol[1] = StartVol[1] + 1;
  }      
sVol2.setValue(StartVol[1]);  
}

void SvolDw2PopCallback(void *ptr)
{   
    if (StartVol[1] > 0){
    StartVol[1] = StartVol[1] - 1;
    }      
    sVol2.setValue(StartVol[1]);  
}

/**************************************
 * Max volume
 **************************************/
void MvolUp2PopCallback(void *ptr)
{   
    if (MaxVol[1] < 80){
    MaxVol[1] = MaxVol[1] + 1;
    }      
    mVol2.setValue(MaxVol[1]);  
}

void MvolDw2PopCallback(void *ptr)
{   
    if (MaxVol[1] > 0){
    MaxVol[1] = MaxVol[1] - 1;
    }      
    mVol2.setValue(MaxVol[1]);  
}

/**************************************
 * Save
 **************************************/
void save2PopCallback(void *ptr)
{   
  uint32_t filter2_state;
  filter2.getValue(&filter2_state);
  EEPROM.update(9, filter2_state);
  uint32_t lift2_state;
  lift2.getValue(&lift2_state);
  EEPROM.update(8, lift2_state);
  EEPROM.update(11, MaxVol[1]);
  EEPROM.update(15, StartVol[1]);
  EEPROM.update(16, VolumeStep[1]);
}

/*************************************
 * 
 * Navigation between pages
 * 
 *************************************/

void goInfoPagePopCallback(void *ptr)
{   
sendCommand("page 9");
CPage = 9;
}

void backInfoPopCallback(void *ptr)
{   
sendCommand("page 2");
CPage = 2;
}

void goSettingsPopCallback(void *ptr)
{   
sendCommand("page 4");
CPage = 4;
}

void backSetPopCallback(void *ptr)
{   
sendCommand("page 2");
CPage = 2;
}



 
