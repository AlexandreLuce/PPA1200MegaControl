/********************************************************************
 * 
 * 
 * Declare your Nextion objects - Example (page id = 0, component id = 1, component name = "b0") 
 * 
 * 
 *******************************************************************/
 
int Init = 0;
int InitOK = 1;
int Home = 2;
int HomeBR = 3;
int Settings = 4;
int CmonSettings = 5;
int Ch1Settings = 6;
int LimSetCh1 = 7;
int Ch2Settings = 8;
int LimSetCh2 = 9;
int ScreenSet = 10;
int InfoPage = 11;

/*******************************************************************
 * Nextion component for page 0 : Init
 * 
 *******************************************************************/

NexNumber ImVol1(Init,1,"ImVol1");
NexNumber ImVol2(Init,3,"ImVol2");
NexNumber IsVol1(Init,2,"IsVol1");
NexNumber IsVol2(Init,4,"IsVol2");
NexNumber iFTemp(Init,7,"iFTemp");
NexNumber iVolSync(Init,8,"iVolSync");
NexNumber iClift(Init,9,"iClift");
NexNumber iLift1(Init,10,"iLift1");
NexNumber iFilter1(Init,11,"iFilter1");
NexNumber iLift2(Init,12,"iLift2");
NexNumber iFilter2(Init,13,"iFilter2");
NexNumber iBridge(Init,14,"iBridge");
NexNumber iVolStep1(Init,15,"iVolStep1");
NexNumber iVolStep2(Init,16,"iVolStep2");
NexNumber iAutoStart1(Init,17,"iAutoStart1");
NexNumber iAutoStart2(Init,18,"iAutoStart2");
NexNumber iLClip1(Init,19,"iLClip1");
NexNumber iLClip2(Init,20,"iLClip2");
NexNumber iPwL1(Init,21,"iPwL1");
NexNumber iPwL2(Init,22,"iPwL2");

/*******************************************************************
 * Nextion component for page 2 : Home
 * 
 *******************************************************************/

NexButton goSettings(Home, 1, "goSettings");
NexButton goInfoPage(Home, 21, "goInfoPage");
NexText msg(Home, 16, "msg");  
NexText DC(Home, 10, "DC"); 

NexButton Vplus1(Home, 6, "Vplus1");
NexButton Vmin1(Home, 7, "Vmin1");
NexNumber Vol1(Home,4,"Vol1");
NexDSButton Signal1(Home, 17, "Signal1");
NexText Clip1(Home, 11, "Clip1");
NexText tTemp1(Home, 22, "tTemp1");
NexText tTempC1(Home, 24, "tTempC1");
NexNumber Temp1(Home,13,"Temp1");
NexNumber rw1(Home,17,"rw1");
NexNumber pw1(Home,20,"pw1");
NexDSButton Ch1Pwr(Home, 3, "Ch1Pwr");
NexHotspot Pch1(Home, 19, "Pch1");

NexButton Vplus2(Home, 8, "Vplus2");
NexButton Vmin2(Home, 9, "Vmin2");
NexNumber Vol2(Home,5,"Vol2");
NexDSButton Signal2(Home, 18, "Signal2");
NexText Clip2(Home, 12, "Clip2");
NexNumber Temp2(Home,14,"Temp2");
NexText tTempC2(Home, 25, "tTempC2");
NexText tTemp2(Home, 23, "tTemp2");
NexNumber rw2(Home,18,"rw2");
NexNumber pw2(Home,21,"pw2");
NexDSButton Ch2Pwr(Home, 2, "Ch2Pwr");
NexHotspot Pch2(Home, 20, "Pch2");

/*******************************************************************
 * Nextion component for page 3 : HomeBR
 * 
 *******************************************************************/

NexText msgBR(HomeBR, 16, "msgBR"); 
NexButton Vplus(HomeBR, 4, "Vplus");
NexButton gotoSettings(HomeBR, 1, "GotoSettings");
NexButton Vmin(HomeBR, 5, "Vmin");
NexNumber Vol(HomeBR,3,"Vol");
NexText tTemp(HomeBR, 8, "tTemp");
NexNumber rw(HomeBR, 14,"rw");
NexNumber pw(HomeBR, 12,"pw");
NexDSButton Signal(HomeBR, 17, "Signal");
NexText Clip(HomeBR, 7, "Clip");
NexHotspot Power(HomeBR, 18, "Power");
NexDSButton PowerBR(HomeBR, 2, "PowerBR");


/*******************************************************************
 * Nextion component for page 4 : Settings
 * 
 *******************************************************************/

NexButton backSet(Settings, 2, "backSet");

/*******************************************************************
 * Nextion component for page 5 : CmonSettings
 * 
 *******************************************************************/

NexDSButton Clift(CmonSettings, 1, "Clift");
NexHotspot SelectClift(CmonSettings, 11, "SelectClift");
NexDSButton bridge (CmonSettings, 2, "bridge");
NexHotspot Selectbridge(CmonSettings, 12, "Selectbridge");
NexDSButton VolSync(CmonSettings, 3, "VolSync");
NexHotspot SelectVolSync(CmonSettings, 13, "SelectVolSync");
NexNumber FTemp(CmonSettings,9,"FTemp");
NexButton FTplus(CmonSettings, 8, "FTplus");
NexButton FTmin(CmonSettings, 7, "FTmin");
NexButton saveset(CmonSettings, 5, "saveset");
NexDSButton Autostart1(CmonSettings, 14, "Autostart1");
NexHotspot SAutostart1(CmonSettings, 16, "SAutostart1");
NexDSButton Autostart2(CmonSettings, 15, "Autostart2");
NexHotspot SAutostart2(CmonSettings, 17, "SAutostart2");


/*******************************************************************
 * Nextion component for page 6 : Ch1Settings
 * 
 *******************************************************************/

NexDSButton lift1(Ch1Settings, 2, "lift1");
NexHotspot Selectlift1(Ch1Settings, 18, "Selectlift1");
NexDSButton filter1(Ch1Settings, 3, "filter1");
NexHotspot Selectfilter1(Ch1Settings, 19, "Selectfilter1");
NexButton VolStepDw1(Ch1Settings, 14, "VolStepDw1");
NexButton VolStepUp1(Ch1Settings, 15, "VolStepUp1");
NexNumber VolStep1(Ch1Settings, 16,"VolStep1");
NexNumber sVol1(Ch1Settings, 5,"sVol1");
NexNumber mVol1(Ch1Settings, 13,"mVol1");
NexButton SvolUp1(Ch1Settings, 8, "SvolUp1");
NexButton SvolDw1(Ch1Settings, 9, "SvolDw1");
NexButton MvolUp1(Ch1Settings, 12, "MvolUp1");
NexButton MvolDw1(Ch1Settings, 11, "MvolDw1");  
NexButton save1(Ch1Settings, 7, "save1");

/*******************************************************************
 * Nextion component for page 7 : Ch1 Limiter Settings
 * 
 *******************************************************************/

NexDSButton ClipLimCh1(LimSetCh1, 3, "ClipLimCh1");
NexHotspot SClipLimCh1(LimSetCh1, 8, "SClipLimCh1");
NexNumber PLimCh1(LimSetCh1, 5,"PLimCh1");
NexButton PDwCh1(LimSetCh1, 6, "PDwCh1");
NexButton PUpCh1(LimSetCh1, 7, "PUpCh1");

/*******************************************************************
 * Nextion component for page 8: Ch2Settings
 * 
 *******************************************************************/

NexDSButton lift2(Ch2Settings, 2, "lift2");
NexHotspot Selectlift2(Ch2Settings, 18, "Selectlift2");
NexDSButton filter2(Ch2Settings, 3, "filter2");
NexHotspot Selectfilter2(Ch2Settings, 19, "Selectfilter2");
NexButton VolStepDw2(Ch2Settings, 14, "VolStepDw2");
NexButton VolStepUp2(Ch2Settings, 15, "VolStepUp2");
NexNumber VolStep2(Ch2Settings, 16,"VolStep2");
NexNumber sVol2(Ch2Settings, 5,"sVol2");
NexNumber mVol2(Ch2Settings, 12,"mVol2");
NexButton SvolUp2(Ch2Settings, 8, "SvolUp2");
NexButton SvolDw2(Ch2Settings, 9, "SvolDw2");
NexButton MvolUp2(Ch2Settings, 13, "MvolUp2");
NexButton MvolDw2(Ch2Settings, 11, "MvolDw2");  
NexButton save2(Ch2Settings, 7, "save2");


/*******************************************************************
 * Nextion component for page 9 : Ch2 Limiter Settings
 * 
 *******************************************************************/

NexDSButton ClipLimCh2(LimSetCh2, 3, "ClipLimCh2");
NexHotspot SClipLimCh2(LimSetCh2, 8, "SClipLimCh2");
NexNumber PLimCh2(LimSetCh2, 5,"PLimCh2");
NexButton PDwCh2(LimSetCh2, 6, "PDwCh2");
NexButton PUpCh2(LimSetCh2, 7, "PUpCh2");


/*******************************************************************
 * Nextion component for page 11: InfoPage
 * 
 *******************************************************************/

NexButton backInfo(InfoPage, 1, "backInfo");

NexNumber supplyCh1(InfoPage, 4,"supplyCh1");
NexNumber supplyCh2(InfoPage, 7,"supplyCh2");

NexNumber TempCh1(InfoPage, 8,"TempCh1");
NexNumber TempCh2(InfoPage, 9,"TempCh2");

NexNumber rmsWCh1(InfoPage, 10,"rmsWCh1");
NexNumber rmsWCh2(InfoPage, 13,"rmsWCh2");

NexNumber peakWCh1(InfoPage, 14,"peakWCh1");
NexNumber peakWCh2(InfoPage, 26,"peakWCh2");

NexNumber timeUp(InfoPage, 17,"timeUp");

/*******************************************************************
 * 
 * 
 * Register a button object to the touch event list. 
 * 
 * 
 *******************************************************************/
 
NexTouch *nex_listen_list[] = {
  &Vplus,
  &Vmin,
  &Power,
  &Vplus1,
  &Vmin1,
  &Pch1,
  &Vplus2,
  &Vmin2,
  &Pch2,
  &SelectClift,
  &Selectbridge,
  &SelectVolSync,
  &FTplus,
  &FTmin,
  &saveset,
  &Selectlift1,
  &Selectfilter1,
  &SvolUp1,
  &SvolDw1,
  &MvolUp1,
  &MvolDw1,
  &save1,
  &Selectlift2,
  &Selectfilter2,
  &SvolUp2,
  &SvolDw2,
  &MvolUp2,
  &MvolDw2,
  &save2,
  &backInfo,
  &goInfoPage,
  &goSettings,
  &gotoSettings,
  &backSet,
  &VolStepUp1,
  &VolStepDw1,
  &VolStepUp2,
  &VolStepDw2,
  &SAutostart1,
  &SAutostart2,
  &PUpCh1,
  &PDwCh1,
  &SClipLimCh1,
  &PUpCh2,
  &PDwCh2,
  &SClipLimCh2,
  NULL
};

/*******************************************************
* End of File 
*******************************************************/
