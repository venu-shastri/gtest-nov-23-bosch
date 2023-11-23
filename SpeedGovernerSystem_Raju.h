
 #include "ISpeedCalculator.h"
 #include "ISpeedRegulator.h"
 class SpeedControlSystem
{

    public:
    //Inject Dependency Values using constructor : Constructer Dependency Injection
SpeedControlSystem(ISpeedCalculator *ptrCalc,ISpeedRegulator *ptrReg)
:cal{ptrCalc},controller{ptrReg}{

}
        
        void regulatespeed();
    private :
    //Dependencies
        ISpeedCalculator     *cal = nullptr;
        ISpeedRegulator   *controller=nullptr;
   
};