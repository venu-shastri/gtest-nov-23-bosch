#include "SpeedGoverning.h"
 
int readSensor(int input)
{
   int speedValue = 0;
    switch(input)
    {
      case 0:
             speedValue = 30;
             break;
      case 1:
             speedValue = 60;
             break;
       case 2:
             speedValue = 90;
             break;
       case 3:
             speedValue = 120;
             break;
      default:
             speedValue = 20;
             break;
    }
    return speedValue;
}
 
int SpeedGovern::getCurrentspeed()
{
   static int setValue = 0;
   int speedValue = readSensor(setValue);
   setValue++;
    return speedValue;
}
 
int  SpeedGovern::SpeedRegulator(int CurrentSpeed)
{
   int setSpeed;
   if (CurrentSpeed < 20)
   {
      setSpeed = 40;
      cout << "Set the New Speed value to 40 "<< endl;
   }
   else if (CurrentSpeed > 120 )
   {
      setSpeed = 80;
      cout << "Set the New Speed value to 80 "<< endl;
   }
   else{
      setSpeed = 20;
      cout << "Set the New Speed value to 20 "<< endl;
   }
}
 
void SpeedGovern::SpeedMonitor()
{
    int readCurrentSpeed = getCurrentspeed();
    SpeedRegulator(readCurrentSpeed);
}
