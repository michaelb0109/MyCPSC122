#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{

//----------------------------------------------------------------------------
/*
	//TEST FOR PutItemH
	
	//Use of a static list 
	
	List lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
 	
	//Use of a dynamic list
	
	List* lst1 = new List;
	for (int i = 0; i < 5; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	delete lst1; //necessary to invoke destructor on dynamic list
*/
//----------------------------------------------------------------------------
	//TEST FOR GetLength
/*
	//Static Test
	
	List lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	int lstLength = lst.GetLength();
	cout << "Length of List: " << lstLength -1;
	cout << endl;
	
	//Dynamic Test
	
	List* lst1 = new List;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	lstLength = lst1->GetLength();
	cout << "Length of List: " << lstLength -1;
	delete lst1; //necessary to invoke destructor on dynamic list
	
*/
//----------------------------------------------------------------------------
/*
	//TEST FOR IsEmpty
	
	//Static Test
	
	List lst;
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
	
	List* lst1 = new List;
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
	
	List lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	itemType tmpHead = lst.GetItemH();
	cout << "The header of the list currently holds the value: " << tmpHead << endl;
	
	//Dynamic Test
	
	List* lst1 = new List;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	tmpHead = lst1 ->GetItemH();
	cout << "The header of the list currently holds the value: " << tmpHead << endl;
	delete lst1; //necessary to invoke destructor on dynamic list
*/
//----------------------------------------------------------------------------
	//TEST FOR DeleteItemH
/*
	//Static Test
	
	List lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	lst.DeleteItemH();
	cout << "The item in the header has been deleted from the list.\n";
	
	//Dynamic Test
	
	List* lst1 = new List;
	for (int i = 0; i < 4; i++)
	lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	lst1 ->DeleteItemH();
	cout << "The item in the header has been deleted from the list.\n";
	delete lst1; //necessary to invoke destructor on dynamic list
*/
//----------------------------------------------------------------------------
	// TEST FOR Find
/*
	//Static Test
	
	List lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	int idx = lst.Find(10);
	if(idx == -1)
	cout << "Element was not found in the list" << endl;
	
	else
	{
		cout << "The element was found at index: " << idx << endl;
	}
	
	//Dynamic Test
 	
	List* lst1 = new List;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	idx = lst1->Find(23);
	if(idx == -1)
		cout << "Element was not found in the list" << endl;
	
	else
	{
		cout << "The element was found at index: " << idx << endl;
	}
  	delete lst1; //necessary to invoke destructor on dynamic list
*/

//----------------------------------------------------------------------------
	//TEST FOR DeleteItem

/*
	//Static Test
 	
	List lst;
	for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
	lst.Print();
	cout << endl;
	lst.DeleteItem(3);
	lst.Print();
	cout << endl;
	
	//Dynamic Test
	
	List* lst1 = new List;
	for (int i = 0; i < 4; i++)
		lst1->PutItemH(10*i);
	lst1->Print();
	cout << endl;
	lst1->DeleteItem(1);
	lst1->Print();
	delete lst1; //necessary to invoke destructor on dynamic list
*/
	

	cout << endl;
	return 0;
}
