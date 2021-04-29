//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queue3.h"

PQueue::PQueue() : Queue()
{}

PQueue::PQueue(PQueue* q) : Queue(q)
{}

void PQueue::Enqueue(itemType newItem)
{
	node* tmp = new node;
	
	
	if (length == 0)
	{
		head = tmp;
		tail = head;
		tmp -> next = NULL;
	}
	
	else
		tmp -> next = PtrTo(newItem);
	
	tmp -> item = newItem;

	if(newItem <= head -> item && length > 0)
	{
		PutItemH(newItem);
		return;
	}
		
	else if (newItem >= tail -> item && length > 0)
	{
		PutItemT(newItem);
		return;
	}
	node* pre = head;
		
	if (length > 0 && tmp -> next != head)
	{
		while (pre != tail)
		{
			if (pre -> next == tmp -> next)
			{
				pre -> next = tmp;
				break;
			}
			pre = pre -> next;
		}
	}
	tmp = NULL;
	pre = NULL;
	length++;
}

node* PQueue::PtrTo(itemType newItem)
{
	node* address = new node;
	address = head;
	
	while (address != tail -> next)
	{
	
		if (address -> item >= newItem)
			return address;
			
		address = address -> next;
	}
	
	if (newItem > tail -> item)
		return NULL;
	return NULL;
}
