/*******************************************************
*
*
* Retrieve EEPROM datas 
* 
* 
*******************************************************/

void initEEprom(){
VolumeStep[0] = EEPROM.read(18); 
VolumeStep[1] = EEPROM.read(16); 
MaxVol[0] = EEPROM.read(7);
MaxVol[1] = EEPROM.read(11);
StartVol[0] = EEPROM.read(6);
StartVol[1] = EEPROM.read(15);
VolSyncState = EEPROM.read(1);
FanTemp = EEPROM.read(0);
CliftState = EEPROM.read(3);
LiftState[0] = EEPROM.read(4);
FilterState[0] = EEPROM.read(5);
LiftState[1] = EEPROM.read(8);
FilterState[1] = EEPROM.read(9);
bridgeState = EEPROM.read(20);
AutoStartState[0] = EEPROM.read(22);
AutoStartState[1] = EEPROM.read(24);
}

/*******************************************************
* End of File 
*******************************************************/
