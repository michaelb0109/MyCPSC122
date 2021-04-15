/*
	Name: Michael Bernard
	Class: CPSC122, Section 1
	Date Submitted: February 5, 2021
	Assignment: Project 5
	Description: Using the Caesar Cipher to encrypt a message using a key and decrypting a message using the same key.
*/

#include <iostream>
#include <fstream> 
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <string>

using namespace std;

void fileOpen(fstream&, string, char); //used to open files for reading and writing
void generateKey(string); //writes the random key to the keyFile
int keyGen(); //generates a random number between 1 and 25 that is used as the key
char encrypt(char ch, int key); //encrypts message from PlainText
char decrypt(char ch, int key); //decrypts message from CipherText
void encryptFile(string keyFile, string PlainText, string CipherText); //writes encrypted message to CipherText
void decryptFile(string keyFile, string CipherText, string decryptedFile); //writes decrypted message to decryptedFile

int main(int argc, char* argv[])
{
	fstream fout;

	fout.open(argv[1]);
	
	int mode = atoi(argv[1]);
		
	if (mode == 0)
		generateKey(argv[2]);
	if (mode == 1)
 		encryptFile(argv[2], argv[3], argv[4]);
	if (mode == 2)
 		decryptFile(argv[2], argv[3], argv[4]);
	
 	return 0;
	}

/*
Description: Calls the keyGen function to generate a random number then writes it to the keyFile
Input: the file that holds the generated key
Output: N/A
*/
void generateKey(string keyFile)
{
 	int keyNum;
 	
 	fstream fout;
 	keyNum = keyGen(); 
 	fileOpen(fout, keyFile, 'w'); 
 	
 	fout << keyNum << endl; //writing random number to keyFile
	
 	fout.close();
}

/*
Description: Randomly generates an integer in the range: [1..25]
Input: none
Output: returns a randomly generated integer in the range [1..25]
*/
int keyGen()
{
	int keyNum = 0;
	
	srand(time(0));
 	keyNum = rand() % 25 + 1;
	
 	return keyNum;
}
	
/*
	Description: function opens a file 
	Input: file stream object reference, name of the file, mode of open
	Output: void function, but at exit, file stream object is tied to 
	the input file name. 
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
	Description: Encrypts an upper case alphabetic character using the Caesar cipher
	Input: upper case alphabetic character, valid key
	Returns: encrypted version of ch
*/
char encrypt(char ch, int key)
{
	int position = 0;
	//encrypting every character by the randomly generated key
	position = ch - 'A';
	position = (position + key) % 26; 
	ch = position + 'A';
	
	return ch;
}

/*
	Description: Decrypts an upper case alphabetic character using the Caesar cipher
	Input: upper case alphabetic character, valid key
	Returns: decrypted version of input
*/
char decrypt(char ch, int key)
{
	int position = 0;
	//decrypting every character by the randomly generated key
	position = ch - 'A';
	position = (position - key + 26) % 26;
	ch = position + 65;
	
	return ch;
}

/* 
	Description: calls the encrypt function to write the encrypted characters to the CipherText file
	Input: the keyFile, the file containing the message, and the file containing the encrypted message
	Returns: N/A
*/
void encryptFile(string keyFile, string PlainText, string CipherText)
{
	int key = 0;
	char ch;
	char ch2;
	fstream fin;
	fstream fout;
	fileOpen(fin, keyFile, 'r');
	fin >> key;
	fin.close();
	fileOpen(fin, PlainText, 'r');
	fileOpen(fout, CipherText, 'w');
	
	while (fin.peek() != EOF)
	{
		ch = fin.get();
		if(isalpha(ch))
		{
			ch = toupper(ch);
			ch2 = encrypt(ch, key);
		}
		else
		{
			ch2 = ch;
		}
		fout << ch2; //wrting the encrypted message to the CipherText file
	}
	fin.close();
	fout.close();
}

/* 
	Description: calls the decrypt function to write the decrypted characters to the decrypt file
	Input: the keyFile, the file containing the encrypted message, and the file containing the decrypted message (same as the PlainText file)
	Returns: N/A
*/
void decryptFile(string keyFile, string CipherText, string decryptedFile)
{
	int key = 0;
	char ch;
	char ch2;
	fstream fin;
	fstream fout;
	fileOpen(fin, keyFile, 'r');
	fin >> key;
	fin.close();
	fileOpen(fin, CipherText, 'r');
	fileOpen(fout, decryptedFile, 'w');
	
	while (fin.peek() != EOF)
	{
		ch = fin.get();
		if(isalpha(ch))
		{
			ch = toupper(ch);
			ch2 = decrypt(ch, key);
		}
		else
		{
			ch2 = ch;
		}
		fout << ch2; //wrting the decrypted message to the decryptedFile file
	}
	fin.close();
	fout.close();
}

