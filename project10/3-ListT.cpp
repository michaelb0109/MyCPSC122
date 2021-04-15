#include <iostream>
using namespace std;

#include "3-ListT.h"

//constructor
ListT::ListT()
{
	length = 0;
	head = NULL;
	tail = NULL;

	struct node
	{
		itemType item;
		node* next;
	};
}

//destructor
ListT::~ListT()
{
 while(length > 0)
  {
    DeleteItemH();
  }
}

//checks if the list contains any values
bool ListT::IsEmpty() const
{
	int tmpLength = GetLength();
	
	if(!(tmpLength - 1))
	{
    	return false;
	}
	return true;

}

//returns the length of the lists
int ListT::GetLength() const
{
	int length = 0;
	node* tmp = new node;
	tmp -> next = head;
	
	while(tmp != NULL)
	{
		tmp = tmp -> next;
		length++;
	}
	return length;
}

//assigns a value to the head of the list
void ListT::PutItemH(const itemType newItem)
{
	node* tmp = new node;
	tmp->item = newItem;
	tmp->next = head;
	head = tmp;
	if (length == 0)
		tail = head;
	length++;
	tmp = NULL;
}

//returns the item in the header of the list
itemType ListT::GetItemH() const
{
	return head->item;
}

//deletes the item in the list header
void ListT::DeleteItemH()
{
	node* currentItem;
	currentItem = head;
	head = currentItem -> next;
	currentItem -> next = NULL;
	delete currentItem;
	currentItem = NULL;
	length--;	
}

//assigns a value to the tail of the list
void ListT::PutItemT(const itemType itemIn)
{
	node* tmp = new node;
	
	if(length == 0)
	{
		tmp -> item = itemIn;
		tail = tmp;
		tail -> next = NULL;
		head = tmp;
		length++;
	}
	else
	{
		tmp -> item = itemIn;
		tail -> next = tmp;
		tail = tmp;
		tmp -> next = NULL;
		length++;
	}
	tmp = NULL;
}

//returns the item in the tail of the list
itemType ListT::GetItemT() const
{
	return tail->item;
}

//deletes the item currently held in the tail of the list
void ListT::DeleteItemT()
{
	int address = 0;
	
	node* tmp = head;
	while(tmp -> next -> next != NULL)
	{
		tmp = tmp -> next;
	}
	tail = PtrTo();
	delete tmp -> next;
	tmp -> next = NULL;
	length--;
}

//prints the contents of the lists
void ListT::Print() const
{
	node* currentItem;
	currentItem = head;

	while (currentItem != NULL)
	{
		cout << currentItem -> item << endl;
		currentItem = currentItem -> next;
	}
}

//finds the number of times the target appears in the list
int ListT::FindItem(const itemType target) const
{
	int targetCounter = 0;
	
	if (length > 0) 
	{
		node* tmp = head;
		while (tmp != NULL)
		{
			if (tmp->item == target)
				targetCounter++;
			tmp = tmp-> next;
		}
	} 	
	return targetCounter;              
}

//deletes a specified item from the list
int ListT::DeleteItem(const itemType target)
{
	int nodesDeleted = 0;
	
	if(target == head -> item)
	{
		DeleteItemH();
		nodesDeleted++;
	}
	
	if(target == tail -> item)
	{
		DeleteItemT();
		nodesDeleted++;
	}
	
	while(DeleteAnItem(target))
	{
		nodesDeleted++;
	}
	//cout << "The target was found and deleted in " << nodesDeleted << " instance(s).\n";
	return nodesDeleted;
}

//deletes an item from the list that is not the head or the tail and returns true, otherwise returns false and no item is deleted
bool ListT::DeleteAnItem(itemType target)
{
	
	node* tmp = head;
	
	while (tmp -> next != NULL && tmp -> next -> item != target)
	{
		tmp = tmp -> next;
	}
	
	if (tmp -> next == NULL)
	{
		return false;
	}
	node* tmp1 = tmp -> next;
	tmp -> next = tmp1 -> next;
	delete []tmp1;
	tmp = NULL;
	tmp1 = NULL;
	length--;
	return true;
}

//returns the address of the new tail node
node* ListT::PtrTo()
{
	node* address = new node;
	node* tmp = head;
	
	if (length > 0)
	{
		while(tmp -> next -> next != NULL)
		{
			tmp = tmp -> next;
		}
		address = tmp;
		cout << "The address of the new tail is " << address << endl;
	}
	return address;
}

