//#include "pch.h"
#include "CppUnitTest.h"
#include "../Cpts_121_PA3/pa3_functions.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


//test pa3 function using microsoft test framework
namespace Cpts121PA3UnitTest
{
	TEST_CLASS(Cpts121PA3UnitTest)
	{
	public:
		
		TEST_METHOD(TestCalcMeanIsEqual)  //test calculate_mean equal
		{
			int sum = 3;
			double number = 3.0;
			double actual = 1.0;
			Assert::AreEqual(actual, calculate_mean(sum, number));
			Logger::WriteMessage("Calc_mean_test complete!");
		}

		TEST_METHOD(TestCalcSumIsEqual)  //test calculate_sum equal
		{
			double number1 = 1.0;
			double number2 = 2.0;
			double number3 = 3.0;
			double number4 = 4.0;
			double number5 = 5.0;
			double actual = 15.0;
			Assert::AreEqual(actual, calculate_sum(number1, number2, number3, number4, number5));
			Logger::WriteMessage("Calc_sum_test complete!");
		}

		TEST_METHOD(TestCalcDeviationIsEqual)  //test calculate_deviation equal
		{
			double mean = 3.0;
			double number = 3.0;
			double actual = 0.0;
			Assert::AreEqual(actual, calculate_deviation(number, mean));
			Logger::WriteMessage("Calc_dev_test complete!");
		}
		
		TEST_METHOD(TestCalcVarianceIsEqual)  //test calculate_variance equal
		{
			double deviation1 = 1;
			double deviation2 = 1;
			double deviation3 = 1;
			double deviation4 = 1;
			double deviation5 = 1;
			int number = 1;
			double actual = 5.0;
			Assert::AreEqual(actual, calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, number));
			Logger::WriteMessage("Calc_var_test complete!");
		}

		TEST_METHOD(TestCalcStdDeviationIsEqual)  //test calculate_standard_deviation equal
		{
			double variance = 4.0;
			double actual = 2.0;
			Assert::AreEqual(actual, calculate_standard_deviation(variance));
			Logger::WriteMessage("Calc_std_dev_test complete!");
		}

		TEST_METHOD(TestFindMaxIsEqual)  //test find_max equal
		{
			double number1 = 1.0;
			double number2 = 2.0;
			double number3 = 3.0;
			double number4 = 4.0;
			double number5 = 5.0;
			double actual = 5.0;
			Assert::AreEqual(actual, find_max(number1, number2, number3, number4, number5));
			Logger::WriteMessage("find_max test complete!");
		}

		TEST_METHOD(TestFindMinIsEqual)  //test calculate_standard_deviation equal
		{
			double number1 = 1.0;
			double number2 = 2.0;
			double number3 = 3.0;
			double number4 = 4.0;
			double number5 = 5.0;
			double actual = 1.0;
			Assert::AreEqual(actual, find_min(number1, number2, number3, number4, number5));
			Logger::WriteMessage("find_max test complete!");
		}
		
	};
}
