#include <gtest/gtest.h>
bool isPrime(int number){
    return (number%2)!=0;
}
class DataDrivenTestFixture:public testing::TestWithParam<int>{

};

TEST_P(DataDrivenTestFixture,CheckForPrime){
    int number=GetParam();
   bool isTrue= isPrime(number);
   ASSERT_TRUE(isTrue);
}
//Value Generator
INSTANTIATE_TEST_SUITE_P(GivenPrimeNumbers,DataDrivenTestFixture,testing::Values(1,3,7,9,11));
INSTANTIATE_TEST_SUITE_P(GivenNonPrimeNumbers,DataDrivenTestFixture,testing::Values(2,4,6,8,12));
