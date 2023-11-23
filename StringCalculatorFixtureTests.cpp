#include <gtest/gtest.h>
#include "StringCalculator.h"
class StringCalculatorTestsFixture :public testing::Test{
        protected:
        StringCalculator objUnderTest;
        //BeforeEach TestCase Execution
        void SetUp() override{
            cout<<"SetupCalled Before"<<endl;
        }
        //AfterEach TestCase Execution
        void TearDown() override{
            cout<<"TearDown After"<<endl;
        }
        //Before All TestCases
        static void SetUpTestSuite(){ cout<<"SetupTestSuiteCalled"<<endl;}
        //After All TestCases
        static void TearDownTestSuite() {cout<<"SetupTestSuiteCalled"<<endl;}
};
TEST_F(StringCalculatorTestsFixture,ForEmptyStringZeroIsExpected){
    string input="";
    int expectedValue=0;
    int actualValue=objUnderTest.Add(input);
    ASSERT_EQ(expectedValue,actualValue);
    
}
TEST_F(StringCalculatorTestsFixture,For0IsZeroExpected){
    string input="0";
    int expectedValue=0;
    int actualValue=objUnderTest.Add(input);
    ASSERT_EQ(expectedValue,actualValue);
    
}
TEST_F(StringCalculatorTestsFixture,For1Is1Expected){
    string input="1";
    int expectedValue=1;
    int actualValue=objUnderTest.Add(input);
    ASSERT_EQ(expectedValue,actualValue);
    
}
TEST_F(StringCalculatorTestsFixture,ForMultiedelimeterInputValidValueIsExpected){
    string input="1,2";
    int expectedValue=3;
    int actualValue=objUnderTest.Add(input);
    ASSERT_EQ(expectedValue,actualValue);
    
}

//Tuple<string,int>
struct Data{
    string input;
    int expectedValue;
};
//std:make_tuple()
Data prepare_data(string _input,int _expectedValue){
    Data dataObj;
    dataObj.input=_input;
    dataObj.expectedValue=_expectedValue;
    return dataObj;
    
}
class StringCalculatorDataDrivenTests:
public StringCalculatorTestsFixture,
public testing::WithParamInterface<Data>{

};
INSTANTIATE_TEST_SUITE_P(StringCalculatorDataDriveTest1,
                         StringCalculatorDataDrivenTests,
                         testing::Values(
                            prepare_data("",0),
                            prepare_data("0",0),
                            prepare_data("1",1),
                            prepare_data("1,2",3)
                         ));

TEST_P(StringCalculatorDataDrivenTests,AddDataDrivenTest){

    string input=GetParam().input;
    int expectedValue=GetParam().expectedValue;
   int actualValue= objUnderTest.Add(input);
    ASSERT_EQ(actualValue,expectedValue);

}