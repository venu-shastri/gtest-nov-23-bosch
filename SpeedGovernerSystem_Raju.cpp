#include "SpeedGovernerSystem_Raju.h"

void SpeedControlSystem::regulatespeed(){
       int currentSpeed= cal->getSpeed();
       currentSpeed=0;
        controller->regulate(currentSpeed);
    
}
