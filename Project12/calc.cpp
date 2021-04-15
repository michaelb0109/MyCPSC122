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
	DisplayInFix();
}

Calc::~Calc()
{
	delete inFix;
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
	int lastIdx = 0;
	int cur;
	int parsed;
	valueIdx = 0;
	int tmpLength = 0;
	int pos = 0;
	int z = 0;
	int curIdx;
	int i = 0;
	char* parsedEquation = new char[strlen(inFix)];
	int parsedIdx = 0;
	
	
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
