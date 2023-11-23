#include <stdio.h>
 
using namespace std;
 
 //GOD Class Design -
class SpeedGovern
{
public:
  void SpeedMonitor(void);
 private:
    int getCurrentspeed(void);
    int SpeedRegulator(int Current_speed);
};