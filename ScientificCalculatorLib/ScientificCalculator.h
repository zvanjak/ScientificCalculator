#pragma once
#include <string>
#include <vector>
#include <list>
#include <map>

#include "Tokenizer.h"

using std::string;
using std::vector;
using std::map;

struct Operator
{
	char	_name;
	int		_priority;
	bool	_isRightAssociative;
};

enum class CalculatorStatus
{
	STATUS_OK,
	SYNTAX_ERROR,
	MISMATCHED_PARENTHESIS,
	ERROR_IN_CALCULATION,
	NO_EQUAL_SIGN_IN_EQUATION,
	NO_VAR_IN_EQUATION,
	INIFINITY_VARIABLE_VALUE
};

class ScientificCalculator
{
public:
	ScientificCalculator();
	~ScientificCalculator();

	string				driver(string inputExpression);

	vector<Token> tokenize(string inExpr);
	double				evaluateExpression(vector<Token> &vecTokens, CalculatorStatus *outStatus);
	vector<Token>	transformToRPN(vector<Token> &vecTokens, CalculatorStatus *outStatus);
	double				evaluateRPN(vector<Token> output, CalculatorStatus *outStatus);

	double				solveLinearEquation(vector<Token> &vecTokens, string &outVarName, CalculatorStatus *outStatus);
	vector<Token>	simplifyExpression(vector<Token> output, CalculatorStatus *outStatus);
	void					sumNameCoefficients(vector<Token>& expr, double *outVarCoef, double *outRemainingNumberValue);
	void					reorderVariableMultiplication(vector<Token>& expr);

	string				getErrorMessage(CalculatorStatus inStatus);

	double				evaluate(string inputExpression, CalculatorStatus *outStatus);

private:
	vector<string>		_definedFunctions;		// { "log", "sin", "cos" };
	vector<Operator>	_definedOperators;
	map<CalculatorStatus, string>		_errorMessages;

	void				initializeCalculator();

	bool				isSimpleExpression(vector<Token> &vecTokens);
	void				checkTransition(TokenType from, TokenType to, CalculatorStatus *outStatus);

	bool				isFunctionName(string s);
	char				getOperatorChar(Token t);
	Operator&		getOperator(Token t);
};

