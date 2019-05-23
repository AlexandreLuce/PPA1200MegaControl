/*******************************************************
* 
* 
* Process Datas Fonction
* 
* 
*******************************************************/

void ProcessDatas(){

/*******************************************************
* Always Process
* 
*******************************************************/
if(millis() - LastMillis2 > timer2_ProcTemp){
  ProcessTemp();
  LastMillis2 = millis();
  }
if(millis() - LastMillis3 > timer3_ProcDC){
  ProcessDC();
  LastMillis3 = millis();
}
if(millis() - LastMillis6 > timer6_ProcSupply){
  ProcessSupply();
  LastMillis6 = millis();
    }
if(millis() - LastMillis9 > timer9_ProcPwr){
  ProcessPwrRMS();
  LastMillis9 = millis();
}
/*******************************************************
* Home Page Process
* 
*******************************************************/
if(CPage==2 || CPage==3){
  if(millis() - LastMillis1 > timer1_lcdmsg){
    blankmsg();
    LastMillis1 = millis();
    }
  if(millis() - LastMillis4 > timer4_ProcSignal){
    ProcessSignal();
    LastMillis4 = millis();
    }
  if(millis() - LastMillis5 > timer5_ProcClip){
    ProcessClip();
    LastMillis5 = millis();   
    }  
  }
/*******************************************************
* Info Page Process
* 
*******************************************************/
if(CPage==11){
  if(millis() - LastMillis7 > timer7_ProcInfo){
    ProcessUpTime();
    ProcessPwrPeak();
    LastMillis7 = millis();   
  } 
 }  
}

/*******************************************************
* End of File 
*******************************************************/
