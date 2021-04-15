#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

template <typename T>
ListD<T>::ListD()
{
	NodeConstruction();
}

template <typename T>
ListD<T>::ListD(ListD* lst)
{
	NodeConstruction();

	//returns pointer to the first node, which is what we want here
	doubleNode<T>* cur = lst->FindPosition(2);
	for (int i = 1; i <= lst->length; i++)
	{
		Insert(cur->item,i);
		cur = cur->next;
	}
}

template <typename T>
ListD<T>::~ListD()
{
	doubleNode<T>* tmp = head;
	
	while (tmp != NULL)
	{
		doubleNode<T>* nxt = tmp -> next;
		delete tmp;
		tmp = nxt;
	}
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
	//Inserting at the tail is a special case.  It can be made much more efficient than
	//this.
	doubleNode<T>* cur = head;
	int i = 0;  //begin at the dummy node
	while (i < pos - 1)
	{
		cur = cur->next;
		i++;
	}
	return cur;
} 

template <typename T>
void ListD<T>::Insert(T item, int pos)
{
	//new node goes between these two nodes
	doubleNode<T>* insertPtA = FindPosition(pos);  
	doubleNode<T>* insertPtB = insertPtA->next; 
	
	//create new node and set its values
	doubleNode<T>* tmp = new doubleNode<T>; 
	tmp->prev = insertPtA;
	tmp->item = item;
	tmp->next = insertPtB;
	
	//set pointers for nodes before and after the insertion point
	insertPtA->next = tmp;
	insertPtB->prev = tmp;
	
	length++;
}

template <typename T>
void ListD<T>::PrintForward()
{
	doubleNode<T>*  cur = head->next;
	
	int i = 0;
	while (i < length)
	{
		cout << cur->item << endl;
		cur = cur->next;
		i++;
	}
}

template <typename T>
void ListD<T>::Delete(int pos)
{

	if (head == NULL || pos <= 0)
		return;
	
	doubleNode<T>* cur = head;
	
	for (int i = 0; i < pos; i++)
        cur = cur -> next;
 
	if (head == cur)
		head = cur -> next;
		
	if (cur -> next != NULL)
		cur -> next -> prev = cur -> prev;
		
	if (cur -> prev != NULL)
		cur -> prev -> next = cur -> next;
	
	delete cur;
	cur = NULL;
	length--;
}

template <typename T>
int ListD<T>::DeleteAll(T item)
{
	int deletedNodes = 0;
	int index = 1;
	
	doubleNode<T>* search = head -> next;
	
	while (search != tail)
	{
		if (item == search -> item)
		{
			Delete(index);
			deletedNodes++;
		}
		else
			index++;
		
		search = search -> next;
	}
	
	return deletedNodes;
}

template <typename T>
void ListD<T>::PrintBackward()
{
	doubleNode<T>* cur = head->next;

	int i = 0;
	
	while (cur-> next != NULL)
		cur = cur-> next;
	
	cur = cur-> prev;
	
	while (i < length)
	{
		cout << cur-> item << endl;
		cur = cur-> prev;
		i++;
	}
}

template <typename T>
void ListD<T>::Sort()
{
	doubleNode<T>* changeNode = head -> next;
	doubleNode<T>* cur = head -> next;
	doubleNode<T>* smallest = head -> next;
	
	T item1;
	T item2;
	T tmp;
	
	while (changeNode != tail)
	{
		cur = changeNode -> next;
		smallest = changeNode;
		
		while (cur != tail)
		{
			if (cur -> item < smallest -> item)
				smallest = cur;
				
			cur = cur -> next;
		}
		if (smallest != changeNode)
		{
			tmp = changeNode -> item;
			changeNode -> item = smallest -> item;
			smallest -> item = tmp;
		}
		changeNode = changeNode -> next;
	}
}

template <typename T>
void ListD<T>::NodeConstruction()
{
	length = 0;
 
	//create dummy nodes;
	head = new doubleNode<T>;
	tail = new doubleNode<T>;
	
	//set values for head dummy node;
	head->prev = NULL;
	head->item = INT_MIN;
	head->next = tail;
	
	//set values for tail dummy node;
	tail->prev = head; 
	tail->item = INT_MAX;
	tail->next = NULL;
}
