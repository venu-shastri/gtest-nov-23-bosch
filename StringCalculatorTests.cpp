#include <gtest/gtest.h>
#include "StringCalculator.h"
 
 

TEST(StringCalculatorTests,GivenEmptyStringZeroIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "";
    int expected = 0;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
TEST(StringCalculatorTests,GivenZeroAsInputZeroIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "0";
    int expected = 0;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
TEST(StringCalculatorTests,GivenOneAsInputOneIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "1";
    int expected = 1;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
TEST(StringCalculatorTests,GivenMultiple_comma_delimited_numbersSumIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "1,2,3";
    int expected = 6;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
TEST(StringCalculatorTests,Givendelimited_with_newline_and_commaSumIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "//;\n1;2";
    int expected = 3;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
TEST(StringCalculatorTests,Givennegative_numbers_and_commaExceptionexpected){
    //Arrange
    StringCalculator obj;
    string input = "1,-2,-4,5";
    //Assert
    EXPECT_THROW(obj.Add(input),std::invalid_argument);
 
}
 
TEST(StringCalculatorTests,Givenpassed_numbers_over_1000SumIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "42,1001,3";
    int expected = 45;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
 
TEST(StringCalculatorTests,Givenmulticharacter_delimiterSumIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "//[***]\n8***2***3";
    int expected = 13;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
 
TEST(StringCalculatorTests,Givenmultiple_delimitersSumIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "//[*][%]\n4*2%3";
    int expected = 9;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
 
TEST(StringCalculatorTests,Givenmultiple_multicharacter_delimiterSumIsExpected){
    //Arrange
    StringCalculator obj;
    string input = "//[**][%^]\n4**1%^9";
    int expected = 14;
    //Act
    int actual = obj.Add(input);
    //Assert
    ASSERT_EQ(expected,actual);
 
}
