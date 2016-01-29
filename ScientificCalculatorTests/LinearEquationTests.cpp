#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\ScientificCalculatorLib\ScientificCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ScientificCalculatorTests
{
	TEST_CLASS(LinearEquationTests)
	{
	public:
		
		TEST_METHOD(Test_SimpleEquation)
		{
			string res = _calculator.driver("x + 2 = 5");

			Assert::AreEqual(std::string("x=3.000000"), res);
		}

		TEST_METHOD(Test_SimpleEquation2)
		{
			string res = _calculator.driver("4*x + 2 - 5 *2 = 2*x +2 + x");
				
			Assert::AreEqual(std::string("x=10.000000"), res);
		}

		TEST_METHOD(Test_SimpleEquation3)
		{
			string res = _calculator.driver("x * 2 = 5");			

			Assert::AreEqual(std::string("x=2.500000"), res);
		}

		TEST_METHOD(Test_SimpleEquation4)
		{
			string res = _calculator.driver("x * 2 + 3 = 5");		

			Assert::AreEqual(std::string("x=1.000000"), res);
		}

		TEST_METHOD(Test_SimpleEquation5)
		{
			string res = _calculator.driver("x + 2 + 5 * 2 - 2 + 5*x = 16");			

			Assert::AreEqual(std::string("x=1.000000"), res);
		}

		TEST_METHOD(Test_SimpleEquatio65)
		{
			string res = _calculator.driver("3*x + 5 -4*3 = 2 * x - 10");

			Assert::AreEqual(std::string("x=-3.000000"), res);
		}

	private:
		ScientificCalculator _calculator;
		CalculatorStatus outStatus;
	};
}