#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
	stk = new Stack;
	inFix = new char (strlen(argvIn) + 1);
	strcpy(inFix, argvIn);
	if (!CheckTokens())
	{
		cout << "Invalid Character\n";
		exit(EXIT_FAILURE);
	}
	MakeValueTbl();
	if(!CheckParens())
	{
		cout << "Unbalanced Parenthesis\n";
		exit(EXIT_FAILURE);
	}
	Parse();
	InFixToPostFix();
}

Calc::~Calc()
{
	delete inFix;
	delete postFix;
	delete stk;
	delete valueTbl;
}

bool Calc::CheckTokens()
{
	char ch = inFix[0];
	bool validity = true;
	
	for (int i = 0; i < strlen(inFix); i++)
	{
		ch = inFix[i];
		
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')	
			validity = true;
		else if (isdigit(inFix[i]))
			validity = true;
		else if (ch == '(' || ch == ')')
			validity = true;
		else if (ch >= 65 && ch <= 90)
			validity = true;
		else
			validity = false;
		if (validity == false)
				break;
	}
	return validity;
}

void Calc::MakeValueTbl()
{
	valueTbl = new int[26];
	
	valueIdx = 0;
	
	for(valueIdx; valueIdx < 26; valueIdx++)
		valueTbl[valueIdx] = 0;
	valueIdx = 0;
}

void Calc::Parse()
{
	int lastIdx = 0, tmpLength = 0, pos = 0, z = 0, i = 0, parsedIdx = 0;
	int cur, parsed, curIdx;
	valueIdx = 0;
	
	char* parsedEquation = new char[strlen(inFix)];
	
	
	
	while (i < strlen(inFix))
	{
		if (inFix[i] >= '0' && inFix[i] <= '9')
		{
			curIdx = i;
			lastIdx = FindLast(i);
			lastIdx--;
			tmpLength = (lastIdx - curIdx) + 1;
			char tmp[tmpLength + 1];
			
			for (int j = curIdx; j <= lastIdx; j++)
			{
				tmp[pos] = inFix[j];
				pos++;
			}
			parsed = atoi(tmp);
			valueTbl[valueIdx] = parsed;
			i += tmpLength - 1;
			parsedEquation[parsedIdx] = valueIdx + 65;
			valueIdx++;
		}
		else
		{
			parsedEquation[parsedIdx] = inFix[i];
		}
		parsedIdx++;
		i++;
		pos = 0;
	}
		parsedEquation[parsedIdx] = '\0';
		inFix = parsedEquation;
}

int Calc::FindLast(int cur)
{

	char ch = inFix[cur];
	
	while (ch >= '0' && ch <= '9')
	{
		cur++;
		ch = inFix[cur];
	}
	return cur;
}
bool Calc::CheckParens()
{
	for (int i = 0; i < strlen(inFix); i++)
	{
		if (inFix[i] == '(')
			stk->Push(inFix[i]);
		if (inFix[i] == ')')
			stk->Pop();
	}	
	if (stk->IsEmpty())
		return true;
		
	return false;
}

void Calc::DisplayInFix()
{
	for (int i = 0; i < strlen(inFix) + 1; i++)
		cout << inFix[i];
	cout << endl;
}

void Calc::InFixToPostFix()
{
	int i = 0, postFixIdx = 0, postFixCount = 0;
	
	postFix = new char [postFixCount + 1];
	char ch = postFix[0];
	
	while (inFix[i] != '\0')
	{
		ch = inFix[i];
		
		if (ch >= 65 && ch <= 90)
		{
			postFix[postFixIdx] = inFix[i];
			postFixIdx++;
		}
		else if (ch == '(')
		{
			stk->Push(ch);
		}
	
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			stk->Push(ch);
		}
		else if (ch == ')')
		{
			while (stk->Peek() != '(')
			{
				postFix[postFixIdx] = stk->Peek();
				stk->Pop();
				postFixIdx++;
			}
			stk->Pop();
		}
		i++;	
	}
}

void Calc::DisplayPostFix()
{
	int i = 0;
	
	while (postFix[i] != '\0')
	{
		cout << postFix[i];
		i++;
	}
	cout << endl;
}

int Calc::Evaluate()
{
	/*
	char ch = postFix[0];
	char op2;
	char op1;
	char result;
	
	for (int i = 0; i < strlen(postFix) + 1; i++)
	{
		ch = postFix[i];
		
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			stk->Push(ch);
		else if (isdigit(postFix[i]))
		{
			op2 = stk->Pop();
			op1 = stk->Pop();
			//result = op1 ch op2
			stk->Push(result);
		}
	}
	return stk->Pop();
	*/
	return 0;
}
