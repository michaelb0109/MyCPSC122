#include <iostream>
using namespace std;

#include "2-List.h"

//constructor
List::List()
{

	length = 0;
	head = NULL;

	struct node
	{
		itemType item;
		node* next;
	};
}

//destructor
List::~List()
{
 while(length > 0)
  {
    DeleteItemH();
  }
}

//checks if the list contains any values
bool List::IsEmpty() const
{
	int tmpLength = GetLength();
	
	if(!(tmpLength - 1))
	{
    	return false;
	}
	return true;

}

//returns the length of the lists
int List::GetLength() const
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
void List::PutItemH(const itemType newItem)
{
	node* tmp = new node;
	tmp->item = newItem;
	tmp->next = head;
	head = tmp;
	length++;
	tmp = NULL;
}

//returns the item in the header of the list
itemType List::GetItemH() const
{
	return head->item;
}

//deletes the item in the list header
void List::DeleteItemH()
{
	node* currentItem;
	currentItem = head;
	head = currentItem -> next;
	currentItem -> next = NULL;
	length--;

	delete currentItem;
	currentItem = NULL;
}

//prints the contents of the lists
void List::Print() const
{
	node* currentItem = head;

	for(int i = 0; i < length; i++)
	{
		cout << currentItem -> item << endl;
		currentItem = currentItem -> next;
	}

}

//finds the index at which a specific item is in the list
int List::Find(const itemType item) const
{
	int index = 0;              
	node* tmp = head;

	while(tmp!=NULL)
	{
		if(tmp->item == item){         
			return index;               
		}
		tmp = tmp->next;
		index++;
	}   
	return -1;
}

//deletes item at a specific index from the list
void List::DeleteItem(const int pos)
{
	if(length >= 1)
	{
		node* tmp = NULL;
		node* currentItem = head;
		if(length > 0)
		{
			if(pos == 0)
			{
				DeleteItemH();
			}
			else
			{
				for(int i = 0; i < pos; i++)
				{
					tmp = currentItem;
					currentItem = currentItem->next;
				}
				tmp->next = currentItem->next;
				delete currentItem;
				currentItem = NULL;
				length--;
			}
		}
	}
}

