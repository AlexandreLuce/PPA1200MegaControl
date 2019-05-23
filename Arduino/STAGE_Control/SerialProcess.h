
/*******************************************************
* 
* 
* Serial Processing Fonction
* 
* 
*******************************************************/
void ProcessSerial(){
  
if (Serial3.available() != 0){
   switch (Serial3.read())
   {
     case 'l':                                   //Ground Lift Input Ch.1
   
     break;
     case 'L':                                   //Ground Lift Input Ch.2
  
     break;
     case 'p':                                   //Power On/Off Ch.1

     break;  
     case 'P':                                   //Power On/Off Ch.2
   
     break; 
     
     case 'c':                                   //Ground Lift Chassis
       
     break;    
     case 'f':                                   //Filter Ch.1
      
     break;
     case 'F':                                   //Filter Ch.2
      
     break;
     case 'w':                                   //Volume down Ch.1
      
     break;     
     case 'x':                                    //Volume up Ch.1
       
     break;
     case 'W':                                    //Volume down Ch.2
      
     break;     
     case 'X':                                    //Volume up Ch.2
       
     break;
   }
}
}
