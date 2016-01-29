// ScientificCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>

#include "..\ScientificCalculatorLib\ScientificCalculator.h"

using std::getline;
using std::string;

int _tmain(int argc, _TCHAR* argv[])
{
	string inputString;
	ScientificCalculator calculator;

	while (getline(std::cin, inputString))
		std::cout << calculator.driver(inputString) << std::endl;

	return 0;
}

