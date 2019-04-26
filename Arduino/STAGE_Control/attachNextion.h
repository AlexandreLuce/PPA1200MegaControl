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
Pch1.attachPop(Pch1PopCallback, &Pch1);
Pch2.attachPop(Pch2PopCallback, &Pch2);

Vmin1.attachPop(Vmin1PopCallback, &Vmin1);
Vmin2.attachPop(Vmin2PopCallback, &Vmin2);

Vplus1.attachPop(Vplus1PopCallback, &Vplus1);
Vplus2.attachPop(Vplus2PopCallback, &Vplus2);

lift1.attachPop(lift1PopCallback, &lift1);
lift2.attachPop(lift2PopCallback, &lift2);

filter1.attachPop(filter1PopCallback, &filter1);
filter2.attachPop(filter2PopCallback, &filter2);

SvolUp1.attachPop(SvolUp1PopCallback, &SvolUp1);
SvolUp2.attachPop(SvolUp2PopCallback, &SvolUp2);

MvolUp1.attachPop(MvolUp1PopCallback, &MvolUp1);
MvolUp2.attachPop(MvolUp2PopCallback, &MvolUp2);

SvolDw1.attachPop(SvolDw1PopCallback, &SvolDw1);
SvolDw2.attachPop(SvolDw2PopCallback, &SvolDw2);

MvolDw1.attachPop(MvolDw1PopCallback, &MvolDw1);
MvolDw2.attachPop(MvolDw2PopCallback, &MvolDw2);

Clift.attachPop(CliftPopCallback, &Clift);
VolSync.attachPop(VolSyncPopCallback, &VolSync);
FTmin.attachPop(FTminPopCallback, &FTmin);
FTplus.attachPop(FTplusPopCallback, &FTplus);

saveset.attachPop(savesetPopCallback, &saveset);
save1.attachPop(save1PopCallback, &save1);
save2.attachPop(save2PopCallback, &save2);

goInfoPage.attachPop(goInfoPagePopCallback, &goInfoPage);
backInfo.attachPop(backInfoPopCallback, &backInfo);
goSettings.attachPop(goSettingsPopCallback, &goSettings);
backSet.attachPop(backSetPopCallback, &backSet);

VolStepDw1.attachPop(VolStepDw1PopCallback, &VolStepDw1);
VolStepDw2.attachPop(VolStepDw2PopCallback, &VolStepDw2);

VolStepUp1.attachPop(VolStepUp1PopCallback, &VolStepUp1);
VolStepUp2.attachPop(VolStepUp2PopCallback, &VolStepUp2);
}
