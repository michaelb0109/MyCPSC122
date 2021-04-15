/*
	Name: Michael Bernard
	Class: CPSC122, Section 1
	Date Submitted: January 29, 2021
	Assignment: Project 4
	Description: Writes desired number of primes to an output file in desired number of columns given by the user.
	Bonus: I believe the most efficient way to determine a number is prime is to divide it by 2 and test the factors up to that point. No factors of a number will ever be greater than the number divided by 2. This cuts out a lot of numbers in the primality test, therefore making it much more efficient to determine prime numbers.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


bool isPrime(int, int&); //function used to determine if a number is prime

int main (int argc,char * argv[])
{
	int primeNums = 0, cols = 0, primeCounter = 0, x = 2;
	bool prime; //used to return value of the isPrime function
	
	if (argc != 2) //exits program if incorrect number of arguments is entered to the command line
	{
		cout << "Incorrect number of arguments entered.\n";
		exit (EXIT_FAILURE);
	}

	ofstream fout;
	
	fout.open(argv[1]);
	
	cout << "Hello. Welcome to the prime number generator. Please enter how many prime numbers you wish to generate.\n";
	cin >> primeNums;
	cout << "How many columns would you like to display these prime numbers in?\n";
	cin >> cols;
	cout << "Generating prime numbers...\n";
	
	while (primeCounter < primeNums) //loops until the primeCounter reaches desired number of primes entered by the user
	{
		prime = isPrime(x, primeCounter);
			
		if (prime == true)
		{
			fout << x << '\t'; //tab to next col 
			if ((primeCounter - 1) % cols == cols - 1) //creates a newline so that column number does not exceed desired number of columns
				fout << endl;
			}
		x++;
	}

	fout.close();
	
	return 0;
}

/*             	                 
	Description: This function determines if a number is prime or not.
	Input: The number x being incremented and the primeCounter.
	Returns: True or false primality.          	 
*/
bool isPrime(int x, int& primeCounter)
{
	bool prime = true;
	
	for (int y = 2; y <= x / 2; y++) //x is divided by 2 because no factors of a product are greater than
	{
		if (x % y == 0) //if there is no remainer than the number is composite
			prime = false;
	}
	if (prime == true) 
		primeCounter++;
	
	return prime;
}

