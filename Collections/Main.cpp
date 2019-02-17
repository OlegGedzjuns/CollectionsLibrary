#include "Collections.h"
#include <iostream>

using namespace LinkedList;
using namespace std;

int main()
{
	LinkedList_class<int>* myList = new LinkedList_class<int>;
	for (int i = 0; i < 10; i++)
	{
		myList->PushBack(i);
	}
	myList->PopAt(0);
	myList->PopAt(5);
	myList->PopAt(10);
	for (auto it = myList->Head(); it != nullptr; it = it->Next())
	{
		cout << it->Data() << " ";
	}
	cout << endl << myList->GetSize();
	cin.get();
	return 0;
}