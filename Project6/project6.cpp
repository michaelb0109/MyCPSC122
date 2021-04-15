/*
	Name: Michael Bernard
	Class: CPSC122, Section 1
	Date Submitted: February 13, 2021
	Assignment: Project 6
	Description: Using the Affine Cipher to encrypt a message using an alpha and beta key and decrypting a message using the same keys.
*/

#include <iostream>
#include <fstream> 
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <string>

using namespace std;

void fileOpen(fstream&, string, char); //used to open files for reading and writing
void fileControl (string keyFile, string fileIn, string fileOut, int mode); //reads and writes to files
void keyGen(string keyFile); //generates the alpha and beta keys
char encrypt(char ch, int alpha, int beta); //encrypts the message from the inFile and writes to the outFile
char decrypt(char ch, int alpha, int beta, int MI[]); //decrypts the message in the outFile and writes to the decrypt file

int main(int argc, char* argv[])
{
	fstream fout;

	fout.open(argv[1]);
	
	int mode = atoi(argv[1]);
		
	if (mode == 0)
		keyGen(argv[2]);
	if (mode == 1)
 		fileControl(argv[2],argv[3],argv[4], 1);
	if (mode == 2)
 		fileControl(argv[2], argv[3], argv[4], 2);
	
 	return 0;
}

/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/

void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
	int alpha, beta, randAlpha;
	char ch;
	int MI[] = {0,1,0,9,0,21,0,15,0,0,0,19,0,0,0,0,0,23,0,11,0,0,0,0,0,25};
	
	fstream fin;
	fileOpen(fin, keyFile, 'r');
	fin >> alpha;
	fin >> beta;
	fin.close();
	fstream fout;
	
	fileOpen(fin, fileIn, 'r');
	fileOpen(fout, fileOut, 'w');
	
	while(fin.peek() != EOF)
	{
		ch = fin.get();
		
		if(isalpha(ch))
		{
			ch = toupper(ch); //makes characters upper case
			if(mode == 1)
				ch = encrypt(ch, alpha, beta);
			if(mode == 2)
				ch = decrypt(ch, alpha, beta, MI);
		}
		
		fout.put(ch); //writing characters to the output files
	}
	
	fin.close();
	fout.close();
}

/*
Description: Randomly generates and stores alpha and beta values.
The alpha value is randomly drawn from the the set: 
{1,3,5,7,9,11,15,17,19,21, 23,25}
The beta value is randomly drawn from the range: [1..25]  
Input: name of file that stores the keys
Output: alpha and beta values on subsequent lines of keyFile
*/

void keyGen(string keyFile)
{
	int alpha = 0, beta = 0, randAlpha = 0;
	char ch;
	int alphaValues[] = {1,3,5,7,11,17,19,25};
	
	srand(time(0));
	randAlpha = rand() % 8; 
	alpha = alphaValues[randAlpha]; //pulls value from the alphaValues array to get alpha key
 	beta = rand() % 25 + 1; //generates beta key
 	
 	fstream fout; 
 	fileOpen(fout, keyFile, 'w'); 
 	
 	//wrting keys to the keyFile
 	fout << alpha << endl; 
 	fout << beta << endl; 
	
 	fout.close();
}

/*
Description: function opens a file
Input: file stream object reference, name of the file, mode of open
Output: input file name is opened. 
*/

void fileOpen(fstream& file, string name, char mode)
{
 	string fileType;
	
	if (mode == 'r')
 		fileType = "input";
	if (mode == 'w')
 		fileType = "output";
 	
	if (mode == 'r')
 		file.open(name, ios::in);  //available thorugh fstream
	if (mode == 'w')
 		file.open(name, ios::out);  //available through fstream;
	
	if (file.fail()) //error condition 
	{
		cout << "Error opening " << fileType << " file" << endl; 
		exit(EXIT_FAILURE);
	}
}

/*
Description: Encrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values
Returns: encrypted version of ch
*/

char encrypt(char ch, int alpha, int beta)
{
	int position = 0;
	
	position = ch - 'A';
	position = ((alpha*position) + beta) % 26;
	ch = position + 'A';
	
	return ch;
}

/*
Description: Decrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values. Dictionary of multiplicative inverse values mod 26
Returns: decrypted version of input character
*/

char decrypt(char ch, int alpha, int beta, int MI[])
{
	int position = 0;
	
	position = ch - 'A';
	position = ((MI[alpha]*position) - (MI[alpha]*beta) + 650) % 26;
	ch = position + 65;
	
	return ch;
}
