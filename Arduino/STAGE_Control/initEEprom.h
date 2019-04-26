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
Lift1State = EEPROM.read(4);
Filter1State = EEPROM.read(5);
Lift2State = EEPROM.read(8);
Filter2State = EEPROM.read(9);
//bridgeState = EEPROM.read(20);
}
