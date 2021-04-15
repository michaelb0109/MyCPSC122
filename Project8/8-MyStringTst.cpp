/*
	Name: Michael Bernard
	Class: CPSC122, Section 1
	Date Submitted: March 5, 2021
	Assignment: Project 8
	Description: Creating my own string class
*/

#include "8-MyString.h"
#include <iostream> 

using namespace std;


int main(int argc, char* argv[])
{
	char* test = new char[2];
	test[0] = 'z';
	test[1] = 'z';
	
	MyString str1("hello");
	MyString* str2 = new MyString("hello");
	
	//Test of myDisplay
	cout << "***************************************" << endl;
	cout << "*****Test 1 myDisplay*****" << endl;
	cout << "static test" << endl;
	cout << "output should be the command line input" << endl;
	str1.myDisplay();
	cout << endl;
	cout << "*****Test 2  myDisplay*****" << endl;
	cout << "dynamic test" << endl;
	cout << "output should be the command line input" << endl;
	str2->myDisplay();
	cout << endl;
	cout << "***************************************" << endl;
	//End Test of myDisplay
 	
	
	
 	
	//Test of myStrlen
	cout << "***************************************" << endl;
	cout << "*****Test 1 myStrlen*****" << endl;
	cout << "static test" << endl;
	cout << "output should be the length of the string" << endl;
	int length = str1.myStrlen();
	cout << length << endl;
	cout << endl;
	cout << "*****Test 2  myStrlen*****" << endl;
	cout << "dynamic test" << endl;
	cout << "output should be the length of the string" << endl;
	length = str2->myStrlen();
	cout << length << endl;
	cout << endl;
	cout << "***************************************" << endl;
	//End Test of myStrlen
	
	
	
	//Test of isEqual
	cout << "***************************************" << endl;
	cout << "*****Test 1 isEqual*****" << endl;
	cout << "static test" << endl;
	cout << "output should show if strings are equal" << endl;
	bool equality = str1.isEqual(test);
	if(equality)
		cout << "Equal";
	else
		cout << "Not equal";
	cout << endl;
	cout << "*****Test 2  isEqual*****" << endl;
	cout << "dynamic test" << endl;
	cout << "output should show if strings are equal" << endl;
	equality = str2->isEqual(test);
	if(equality)
		cout << "Equal";
	else
		cout << "Not equal";
	cout << endl;
	cout << "***************************************" << endl;
	//End Test of isEqual
 	
 	
	//Test of find
	cout << "***************************************" << endl;
	cout << "*****Test 1 find*****" << endl;
	cout << "static test" << endl;
	cout << "output should be the index of the starting positon of the substring" << endl;
	int i = str1.find("ll");
	cout << i << endl;
	cout << endl;
	cout << "*****Test 2  find*****" << endl;
	cout << "dynamic test" << endl;
	cout << "output should be the index of the starting position of the substring" << endl;
	i = str2->find("lll");
	cout << i << endl;
	cout << endl;
	cout << "***************************************" << endl;
	//End Test of find
	
	
	//Test of concat
	cout << "***************************************" << endl;
	cout << "*****Test 1  concat*****" << endl;
	cout << "static test" << endl;
	cout << "output should be the command line input in one whole string" << endl;
	str1.concat(test);
	str1.myDisplay();
	cout << endl;
	cout << "*****Test 2  concat*****" << endl;
	cout << "dynamic test" << endl;
	cout << "output should be the command line input in one whole string" << endl;
	str2->concat(test);
	str2->myDisplay();
	cout << endl;
	cout << "***************************************" << endl;
	//End Test of concat
	
	//Test of myStrCopy
	cout << "***************************************" << endl;
	cout << "*****Test 1 myStrCopy*****" << endl;
	cout << "static test" << endl;
	cout << "output should be a copy of the command line input" << endl;
	str1.myStrcpy(test);
	str1.myDisplay();
	cout << endl;
	cout << "*****Test 2  myStrCopy*****" << endl;
	cout << "dynamic test" << endl;
	cout << "output should be a copy of the command line input" << endl;
	str2->myStrcpy(test);
	str2->myDisplay();
	cout << endl;
	cout << "***************************************" << endl;
	//End Test of myStrCopy
	
	//delete []str2;
	return 0;  
}
