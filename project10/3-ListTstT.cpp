#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{

//----------------------------------------------------------------------------
/*
	//TEST FOR PutItemH
	
	//Use of a static list 
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
 	
	//Use of a dynamic list
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 5; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	delete lst1; //necessary to invoke destructor on dynamic list
*/

//----------------------------------------------------------------------------
/*
	//TEST FOR PutItemT
	
	//Use of a static list 
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemT(i);
	lst.Print();
	cout << endl;
 	
	//Use of a dynamic list
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 5; i++)
		lst1->PutItemT(10*i);
	lst1->Print();
	cout << endl;
	delete lst1; //necessary to invoke destructor on dynamic list
*/
//----------------------------------------------------------------------------
	//TEST FOR GetLength
/*
	//Static Test
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	int lstLength = lst.GetLength();
	cout << "Length of List: " << lstLength -1;
	cout << endl;
	
	//Dynamic Test
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	lstLength = lst1->GetLength();
	cout << "Length of List: " << lstLength -1;
	cout << endl;
	delete lst1; //necessary to invoke destructor on dynamic list
	
*/
//----------------------------------------------------------------------------
/*
	//TEST FOR IsEmpty
	
	//Static Test
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	bool boolTmp = false;
	boolTmp = lst.IsEmpty();
	if(!boolTmp)
		cout << "Empty \n";
	else
	{
		cout << "Not Empty \n";
	}
	
	//Dynamic Test
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	boolTmp = lst1->IsEmpty();
	if(!boolTmp)
		cout << "Empty \n";
	else
	{
		cout << "Not Empty \n";
	}
	delete lst1; //necessary to invoke destructor on dynamic list
*/	
//----------------------------------------------------------------------------
	//TEST FOR GetItemH
/*
	//Static Test
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	itemType tmpHead = lst.GetItemH();
	cout << "The header of the list currently holds the value: " << tmpHead << endl;
	
	//Dynamic Test
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	tmpHead = lst1 ->GetItemH();
	cout << "The header of the list currently holds the value: " << tmpHead << endl;
	delete lst1; //necessary to invoke destructor on dynamic list
*/
//----------------------------------------------------------------------------

//TEST FOR GetItemT
/*
	//Static Test
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemT(i);
	lst.Print();
	cout << endl;
	itemType tmpTail = lst.GetItemT();
	cout << "The tail of the list currently holds the value: " << tmpTail << endl;
	
	//Dynamic Test
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 4; i++)
		lst1->PutItemT(10*i);
	lst1->Print();
	cout << endl;
	tmpTail = lst1 ->GetItemT();
	cout << "The tail of the list currently holds the value: " << tmpTail << endl;
	delete lst1; //necessary to invoke destructor on dynamic list
*/
//----------------------------------------------------------------------------
	//TEST FOR DeleteItemH
/*
	//Static Test
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	lst.DeleteItemH();
	cout << "The item in the header has been deleted from the list.\n";
	
	//Dynamic Test
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 4; i++)
	lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	lst1 ->DeleteItemH();
	cout << "The item in the header has been deleted from the list.\n";
	delete lst1; //necessary to invoke destructor on dynamic list
*/
//----------------------------------------------------------------------------
//TEST FOR DeleteItemT
/*
	//Static Test
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	cout << "The item in the tail has been deleted from the list.\n"; //the tail is deleted in the next 		line, but for clarity in the console I have put this line above the call to DeleteItemT
	lst.DeleteItemT();
	cout << endl;
	//Dynamic Test
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	cout << "The item in the tail has been deleted from the list.\n";
	lst1 ->DeleteItemT();
	delete lst1; //necessary to invoke destructor on dynamic list
*/
//----------------------------------------------------------------------------
	// TEST FOR FindItem
/*
	//Static Test
	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	int counter = lst.FindItem(3);
	cout << "The target was found at " << counter << " place(s) in the list\n";
	
	//Dynamic Test
 	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	counter = lst1->FindItem(21);
	cout << "The target was found at " << counter << " place(s) in the list\n";
  	delete lst1; //necessary to invoke destructor on dynamic list
*/

//----------------------------------------------------------------------------
	//TEST FOR DeleteItem

/*
	//Static Test
 	
	ListT lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	lst.DeleteItem(7);
	cout << "The new list is seen below.\n";
	lst.Print();
	cout << endl;
	
	//Dynamic Test
	
	ListT* lst1 = new ListT;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	lst1->DeleteItem(20);
	cout << "The new list is seen below.\n";
	lst1->Print();
	delete lst1; //necessary to invoke destructor on dynamic list
*/

	cout << endl;
	return 0;
}
