#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock-actions.h>

#include "SpeedGovernerSystem_Raju.h"
using testing::Eq;
using testing::Return;

class SpeedCalculatorTestDouble :public ISpeedCalculator{
    public:
    int getSpeedCallCount=0;
    int getSpeed(){ this->getSpeedCallCount+=1; return 100;}
};
class SpeedRegulatorTestDouble:public ISpeedRegulator{
    public:
    int regulateCallCount=0;
    int speedArgument=0;
     void regulate(int speed){
        this->regulateCallCount+=1;
        this->speedArgument=speed;
     }
};

TEST(SpeedGovernerSystemTests,SGSTest){
    SpeedCalculatorTestDouble calcMock;
    SpeedRegulatorTestDouble regulatorMock;
    SpeedControlSystem objUnderTest(&calcMock,&regulatorMock);
    objUnderTest.regulatespeed();
    EXPECT_EQ(calcMock.getSpeedCallCount,1);
    EXPECT_EQ(regulatorMock.regulateCallCount,1);
    EXPECT_EQ(regulatorMock.speedArgument,100);

}

class SpeedCalculatorMock :public ISpeedCalculator{
    public:
   MOCK_METHOD( int, getSpeed,());
};
class SpeedRegulatorMock:public ISpeedRegulator{
    public:
    MOCK_METHOD( void, regulate,(int speed));
};

TEST(SGSTests,InteractionTestingUsingGmock){
    SpeedCalculatorMock calcMock;
    SpeedRegulatorMock regMock;
    SpeedControlSystem objUnderTest(&calcMock,&regMock);
    //set expectation before interaction
    EXPECT_CALL(calcMock,getSpeed()).Times(1).WillRepeatedly(Return(100)) ;
    EXPECT_CALL(regMock,regulate(Eq(100))).Times(1);
    objUnderTest.regulatespeed();
    

}
