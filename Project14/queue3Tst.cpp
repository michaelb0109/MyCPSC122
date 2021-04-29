#include <iostream>
using namespace std;

#include "queue3.h"


int main()
{

 PQueue* que = new PQueue;
 int i = 0;
 for (int i = 0; i < 6; i++)
 {
  que->Enqueue(i);
 }
 que->Print();
 cout << endl;
 que->Enqueue(8);
 que->Enqueue(69);
 que->Enqueue(1738);
 que->Enqueue(666);
 que->Enqueue(1738);
 que->Enqueue(420);
 que->Print();
 delete que;
 
}
