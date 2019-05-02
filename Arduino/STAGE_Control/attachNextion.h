/*******************************************************
*
*
* Register the pop event callback function of button component.
* 
* 
******************************************************** 
 buttonComponent.attachPush(buttonPushCallback, &buttonComponent);
 buttonComponent.attachPop(buttonPopCallback, &buttonComponent);
*******************************************************/

void attachNextion(){
/*******************************************************************
 * Nextion Callback for page 2 : Home
 * 
 *******************************************************************/

Vmin1.attachPop(Vmin1PopCallback, &Vmin1);
Vmin2.attachPop(Vmin2PopCallback, &Vmin2);

Vplus1.attachPop(Vplus1PopCallback, &Vplus1);
Vplus2.attachPop(Vplus2PopCallback, &Vplus2);

Pch1.attachPop(Pch1PopCallback, &Pch1);
Pch2.attachPop(Pch2PopCallback, &Pch2);

goInfoPage.attachPop(goInfoPagePopCallback, &goInfoPage);

goSettings.attachPop(goSettingsPopCallback, &goSettings);

/*******************************************************************
 * Nextion Callback for page 3 : Home Bridge
 * 
 *******************************************************************/

Power.attachPop(PowerPopCallback, &Power);

gotoSettings.attachPop(goSettingsPopCallback, &gotoSettings);

Vmin.attachPop(VminPopCallback, &Vmin);
Vplus.attachPop(VplusPopCallback, &Vplus);

/*******************************************************************
 * Nextion Callback for page 5 : Common Settings
 * 
 *******************************************************************/

SAutostart1.attachPop(SAutostart1PopCallback, &SAutostart1);
SAutostart2.attachPop(SAutostart2PopCallback, &SAutostart2);

SelectClift.attachPop(SelectCliftPopCallback, &SelectClift);

SelectVolSync.attachPop(SelectVolSyncPopCallback, &SelectVolSync);

Selectbridge.attachPop(SelectbridgePopCallback, &Selectbridge);

FTmin.attachPop(FTminPopCallback, &FTmin);
FTplus.attachPop(FTplusPopCallback, &FTplus);

saveset.attachPop(savesetPopCallback, &saveset);

/*******************************************************************
 * Nextion Callback for page 6 : Channel 1 Settings
 * 
 *******************************************************************/

Selectfilter1.attachPop(Selectfilter1PopCallback, &Selectfilter1);

Selectlift1.attachPop(Selectlift1PopCallback, &Selectlift1);

SvolUp1.attachPop(SvolUp1PopCallback, &SvolUp1);
SvolDw1.attachPop(SvolDw1PopCallback, &SvolDw1);

MvolUp1.attachPop(MvolUp1PopCallback, &MvolUp1);
MvolDw1.attachPop(MvolDw1PopCallback, &MvolDw1);

VolStepUp1.attachPop(VolStepUp1PopCallback, &VolStepUp1);
VolStepDw1.attachPop(VolStepDw1PopCallback, &VolStepDw1);

save1.attachPop(save1PopCallback, &save1);

/*******************************************************************
 * Nextion Callback for page 6 : Channel 2 Settings
 * 
 *******************************************************************/

Selectfilter2.attachPop(Selectfilter2PopCallback, &Selectfilter2);

Selectlift2.attachPop(Selectlift2PopCallback, &Selectlift2);

SvolUp2.attachPop(SvolUp2PopCallback, &SvolUp2);
SvolDw2.attachPop(SvolDw2PopCallback, &SvolDw2);

MvolUp2.attachPop(MvolUp2PopCallback, &MvolUp2);
MvolDw2.attachPop(MvolDw2PopCallback, &MvolDw2);

VolStepUp2.attachPop(VolStepUp2PopCallback, &VolStepUp2);
VolStepDw2.attachPop(VolStepDw2PopCallback, &VolStepDw2);

save2.attachPop(save2PopCallback, &save2);

/*******************************************************************
 * Nextion Callback for page 4 : Settings
 * 
 *******************************************************************/

backSet.attachPop(backHomePopCallback, &backSet);

/*******************************************************************
 * Nextion Callback for page 9 : Info Page
 * 
 *******************************************************************/

backInfo.attachPop(backHomePopCallback, &backInfo);

}
