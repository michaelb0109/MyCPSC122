/*
	Name: Michael Bernard
	Class: CPSC122, Section 1
	Date Submitted: March 5, 2021
	Assignment: Project 8
	Description: Creating my own string class
*/


#include <iostream>

using namespace std;

#include "8-MyString.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
	int i = 0;
	while (strIn[i] != '\0')
		i++;
	length = i;
	str = new char [length + 1];
	i = 0;
	while (i < length + 1)
	{
		str[i] = strIn[i];
		i++;	
	}
}

//Deconstructor function
MyString::~MyString()
{
	delete []str; 
}

//displays the user input
void MyString::myDisplay()
{
	cout << str << endl;
}

//copies the user input and assings it to strIn
void MyString::myStrcpy(char const* strIn)
{
	int i = 0;
	
	while (strIn[i] != '\0')
	{
		i++;	
	}
	length = i;
	char* strNew = new char (length + 1);
	i = 0;
	while (i < length + 1)
	{
		strNew[i] = strIn[i];
		i++;
	}
	delete []str;
	str = strNew;
	strNew = NULL;
}

//obtains the str length
int MyString::myStrlen()
{
	return length;
}

//gets the length of the user input
int MyString::myStrlen(char const* strIn)
{
	return length;
}

//determines if the user input is the same as the original string
bool MyString::isEqual(char const* strIn)
{
	int i = 0;
	
	if (length != strlen(strIn))
		return false;
	
	while (strIn[i] != '\0')
	{
    	if (str[i] != strIn[i])
    		return false;
    	i++;
    }
    return true;
}

//searches for a substring within the string 
int MyString::find(char const* strIn)
{
	for (int i = 0; i < (length - strlen(strIn) + 1); i++)
	{
		if (isSub(strIn, i))
			return i;
	}
	return -1;
}

//takes both strings and creates one combined string
void MyString::concat(char const* strIn)
{
	char* combStr = strcat(str, strIn);
}

//finds the index of the beginning of the substring
bool MyString::isSub(char const* strIn, int idx)
{
	for (int i = 0; i < strlen(strIn); i++)
	{
		if (str[idx + i] != strIn[i])
			return false;
	}
	return true;
}
