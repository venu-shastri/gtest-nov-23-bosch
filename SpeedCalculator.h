#include "ISpeedCalculator.h"
#include "ISensor.h"
class SpeedCalculator{
    public:
    int getSpeed();
    private:
    ISensor *sObj;
};