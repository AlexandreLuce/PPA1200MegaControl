#include <EEPROM.h>
#include "Nextion.h"

/*******************************************************************
 * Pin configuration
 * 
 *******************************************************************/
//Declare Control Bus
const byte buspins[12] = {25, 23, 29, 27, 33, 31, 37, 35, 41, 39, 45, 43}; // bus 0,1,2,3,4,5,6,7,8,9,10,11

const byte CS_HC[2] = {51,53};    //Chip select 74HC373 Ch.1 Ch.2
const byte CS_AD[2] = {49,47};   //Chip select AD7545 Ch.1 Ch.2

//Declare Datas Bus 
const byte ibuspins[2][9] = {
                             {A8, A9, A10, A11, A12, A13, A14, A15,52},
                             {A0, A1, A2, A3, A4, A5, A6, A7,50},
                            };

/*******************************************************************
 * Timers configuration
 * 
 *******************************************************************/

int unsigned timer1_lcdmsg = 10000;
int unsigned timer2_ProcTemp = 30000;
int unsigned timer3_ProcDC = 500;
int unsigned timer4_ProcSignal = 3500;
int unsigned timer5_ProcClip = 2000;
int unsigned timer6_ProcSupply = 1000;
int unsigned timer7_ProcInfo = 3000;
int unsigned timer8_ChPwr = 20000;

/*******************************************************************
 * Default EEPROM Values
 * 
 *******************************************************************/

int unsigned MaxVol[2] = {40,40};
int unsigned StartVol[2] = {0,0};
byte unsigned VolumeStep[2] = {1,1};
byte unsigned VolSyncState = 0;
byte unsigned CliftState = 0;
byte unsigned LiftState[2] = {0,0};
byte unsigned FilterState[2] = {0,0};
byte unsigned AutoStartState[2] = {0,0};
byte unsigned bridgeState = 0;
int unsigned FanTemp = 30;

/*******************************************************************
 * Internal configuration
 * !!! NOTHING TO CONFIGURE !!! 
 *******************************************************************/
                                         
//Store AD/HC Bus
int HCbusvalue[2][12] ={ 
                       {0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0},
                       };
int ADbusvalue[2][12] ={
                       {0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0},
                       };

byte bitval;
int Volval[2] = {0,0};
byte unsigned FanState = 0;
byte unsigned PowerState[2] = {0,0};
byte unsigned setpin;
byte unsigned setAmp;
byte unsigned ADbus = 11;
byte unsigned ADpin = ADbus;
long unsigned int Cmillis;

//Store Info Bus
int unsigned supply[2] = {0,0};
byte unsigned dc[2] = {0,0};
byte unsigned signl[2] = {0,0};
byte unsigned clip[2] = {0,0};
int unsigned rmsV[2] = {0,0};
int unsigned rmsI[2] = {0,0};
int unsigned peakV[2] = {0,0};
int unsigned peakI[2] = {0,0};
int unsigned Temp[2] = {0,0};

byte unsigned  CPage = 0;

char buffer[100] = {0};

long unsigned int LastMillis1 = 0;
long unsigned int LastMillis2 = 0;
long unsigned int LastMillis3 = 0;
long unsigned int LastMillis4 = 0;
long unsigned int LastMillis5 = 0;
long unsigned int LastMillis6 = 0;
long unsigned int LastMillis7 = 0;
long unsigned int LastPwr1Millis = 0;
long unsigned int LastPwr2Millis = 0;

#include "InitAmp.h"

/*******************************************************
* 
* Setup
* 
*******************************************************/

void setup()
{
//Init Serial 1
//Serial.begin(9600);
//Init EEPROM
initEEprom();
//Init Bus
InitBus();
//Init Amp
InitAmp(0);
InitAmp(1);
//Init Lcd
InitLcd();
AutoStart();
}

/*******************************************************
* 
* Loop
* 
*******************************************************/
void loop(){
  
nexLoop(nex_listen_list);

ProcessDatas();
              
}
