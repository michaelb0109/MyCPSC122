#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"


ListD::ListD()
{
 NodeConstruction();
}

ListD::ListD(ListD* lst)
{
 NodeConstruction();

 //returns pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

ListD::~ListD()
{
	doubleNode* tmp = head;
	
	while (tmp != NULL)
	{
		doubleNode* nxt = tmp -> next;
		delete tmp;
		tmp = nxt;
	}
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}


void ListD::Delete(int pos)
{

	if (head == NULL || pos <= 0)
		return;
	
	doubleNode* cur = head;
	
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

int ListD::DeleteAll(itemType item)
{
	int deletedNodes = 0;
	int index = 1;
	
	doubleNode* search = head -> next;
	
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

void ListD::PrintBackward()
{
	doubleNode* cur = head->next;

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

void ListD::Sort()
{
	doubleNode* cur = head;
	doubleNode* smallest = head;
	doubleNode* newHead = NULL;
    doubleNode* newTail = NULL;
    
	while(head != NULL)
	{
        cur = head;
        while(cur != NULL)
        {
            if(cur->item < smallest->item)
            {
                smallest = cur;
            }
            cur = cur->next; 
        }

        //smallest is first node
        if(smallest->prev == NULL)
        {
        	if (smallest -> next = NULL)
        		break;
			else
			{
				head = head -> next;
				head -> prev = NULL;
			}
		}
		
        //smallest is last node
        else if(smallest->next == NULL)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
		
		else
        {
            smallest->prev->next = smallest->next;
            smallest->next->prev = smallest->prev;
        }
       

        //adding smallest to a new linked list
        if(newHead == NULL)
        {
            smallest->prev = NULL;
            smallest->next = NULL;
            newHead = smallest;
            newTail = smallest;
        }
        
        else
        {
            smallest->prev = newTail;
            smallest->next = NULL;
            newTail->next = smallest;
            newTail = smallest;
        }
    }
    smallest -> prev = newTail;
    smallest -> next = NULL;
    newTail -> next = smallest;
    newTail = smallest;
    //point head to new linked list
    head = newHead;
    tail = newTail;

}

void ListD::NodeConstruction()
{
	length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}
 
