/*
	Name: Michael Bernard & Mason Manca
	Class: CPSC122, Section 1
	Date Submitted: February 20, 2021
	Assignment: Project 7
	Description: Using the Transposition Cipher to encrypt a message and decrypt a message.
*/

#include <iostream>
#include <fstream> 
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <string>

using namespace std;

void fileOpen(fstream&, string, char); //used to open files for reading and writing
void fileControl (string keyFile, string fileIn, string fileOut, int mode); //reads and writes to files
void keyGen(string keyFile);
char transform(char ch, int encDec[]);
void keyRead(string keyFile, int encKey[]);
void decryption(string keyFile, int decKey[], int encKey[]);

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
Description: Processes files, invokes function to encrypt/decrypt characters
1. Reads key file. Constructs a two arrays, one for encryption, one for decryption.
2. Closes key file
2. Opens the character input file.  This could be plain text or cipher text.
3. Opens the character output file  This could be plain text or cipher text.
4. Reads the input file a character at a time.  Passes transform (see below) the character to be encrypted/decrypted and a reference to  the encrypt or decrypt array, depending on the mode.
5.  Writes a character (encrypted/decrypted/passed over) to the output file.
6. Close the input file and output file
Output: writes a character to the output file
*/

void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
	int SIZE = 26; //alphabet size
	char ch;
	int encKey[SIZE]; //holds the encrypted values
	int decKey[SIZE]; //holds the decrypted values
	
	fstream fin;
	fileOpen(fin, keyFile, 'r');
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
			{
				keyRead(keyFile, encKey);
				ch = transform(ch, encKey);
			}
			if(mode == 2)
			{	
				keyRead(keyFile, encKey);
				decryption(keyFile, decKey, encKey);
				ch = transform(ch, decKey);
			}
		}
		
		fout.put(ch); //writing characters to the output files
	}
	
	fin.close();
	fout.close();
}

/*
Description: Opens key file for writing.  Generates and stores encrypt and decrypt keys in the key file.   This can be stored any way that you like as long as two arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 
*/

void keyGen(string keyFile)
{
	int SIZE = 26;
	int k = 0;
	int pos = 0;
	bool validate[SIZE] = {false, false, false, false}; 
 	
 	fstream fin;
 	fstream fout; 
 	
	fileOpen(fout, keyFile, 'w'); 
 	fileOpen(fin, keyFile, 'r');
 	
 	srand(time(0));
 	
 	for (pos = 0; pos < SIZE; pos++)
 	{
 		
 		while (true)
 		{
 			k = rand() % SIZE;
 			if (validate[k] == false) //checks if value is not used
 			{
 				validate[k] = true; // set index/val at index to used
 				fout << k << endl;
 				break;
 			}
 		}
 	}
	
 	fin.close();
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
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/

char transform(char ch, int encDec[])
{

	int pos = ch - 'A'; //0-25
	pos = encDec[pos]; 
	ch = pos + 'A'; //back to ASCII val
	
	return ch;
}

/*
Description: Takes integers from keyFile and stores values into encKey array
Input: keyFile, encryption array
Returns: filled encKey array
*/

void keyRead(string keyFile, int encKey[])
{
	fstream fin;
	int SIZE = 26;
	
	fileOpen(fin, keyFile, 'r');
	
	for (int t = 0; t < SIZE; t++)
 	{
 		fin >> encKey[t]; //reading values into the encKey array
 	}
 	
 	fin.close();
}

/*
Description: Takes integers from the encrypted array and stores values into decrypted array
Input: keyFile, encryption array and decrypted array
Returns: filled decKey array
*/

void decryption(string keyFile, int decKey[], int encKey[])
{
	int SIZE = 26;
	
	for (int t = 0; t < SIZE; t++)
 	{
 		decKey[encKey[t]] = t; //index of the value to A,B,C to decrypt
 	}
}

