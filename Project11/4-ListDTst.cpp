#include <iostream>
using namespace std;

#include "4-ListD.h"
#include "4-ListD.cpp"

//void ListD<T>::TestInsert();

int main()
{
	ListD<int>* lst = new ListD<int>;
	
	lst->Insert(1,1);
	lst->Insert(2,2);
	lst->Insert(3,3);
	lst->Insert(8,4);
	lst->Insert(5,5);
	lst->Insert(11,6);
	lst->PrintForward();
	
	cout << endl;
	
	ListD<int>* lst1 = new ListD<int>(lst);
	lst1-> PrintForward();
	cout << endl;
	
	cout << "Print backward test 1\n";
	lst-> PrintBackward();
	cout << endl;
	cout << "Print backward test 2\n";
	lst1-> PrintBackward();
	cout << endl;
	
	cout << "Delete test 1\n";
	lst-> Delete(1);
	lst -> PrintForward();
	cout << endl;
	cout << "Delete test 2\n";
	lst1-> Delete(1);
	lst1-> PrintForward();
	cout << endl;
	
	cout << "Delete all test 1\n";
	cout<< "NODES DELETED: " << lst-> DeleteAll(1);
	lst -> PrintForward();
	cout << endl;
	cout << "Delete all test 2\n";
	cout << "NODES DELETED: " << lst1-> DeleteAll(1);
	lst1-> PrintForward();
	cout << endl;
	
	cout << "Unsorted LIST test 1\n";
	lst-> PrintForward();
	lst->Sort();
	cout << "SORTED LIST TEST 1\n";
	lst -> PrintForward();
	cout << endl;
	
	cout << "Unsorted LIST test 2\n";
	lst-> PrintForward();
	lst->Sort();
	cout << "SORTED LIST TEST 2\n";
	lst -> PrintForward();
	cout << endl;
	
	delete lst;
	delete lst1;
	return 0;
/*

 for (int i = 1; i <= 6; i++)
  lst->Insert(i,i);
	
 //test general case insert
 cout << "Passed Insert Test 1 if 1 through 6 appear on subsequent lines" << endl;
 lst->PrintForward();
 cout << endl;

 //test insert at the head
 lst->Insert(0,1);
 cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
 lst->PrintForward();
 cout << endl;

 //test insert at the tail 
 lst->Insert(100,8);
 cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
 lst->PrintForward();
 cout << endl;
 
 //test insert in middle 
 lst->Insert(50,5);
 cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
 lst->PrintForward();
 cout << endl;
 //TestDeleteAll();
 //TestInsert();
 */
}

/*
void ListD<T>::TestInsert()
{

 ListD<int>* lst = new ListD<int>;
 for (int i = 1; i <= 6; i++)
  lst->Insert(i,i);
	
 //test general case insert
 cout << "Passed Insert Test 1 if 1 through 6 appear on subsequent lines" << endl;
 lst->PrintForward();
 cout << endl;

 //test insert at the head
 lst->Insert(0,1);
 cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
 lst->PrintForward();
 cout << endl;

 //test insert at the tail 
 lst->Insert(100,8);
 cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
 lst->PrintForward();
 cout << endl;
 
 //test insert in middle 
 lst->Insert(50,5);
 cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
 lst->PrintForward();
 cout << endl;
 
 delete lst;
}

*/
