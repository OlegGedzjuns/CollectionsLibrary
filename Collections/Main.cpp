#include "Collections.h"
#include <iostream>

using namespace LinkedList;
using namespace std;

int main()
{
	LinkedList_class<int>* myList = new LinkedList_class<int>;
	myList->PushBack(myList->PushBack(3) + 1);
	myList->PushBack(2);
	for (auto it = myList; it != nullptr; it= it->Next())
	{
		cout << it->Data() << " ";
	}
	cin.get();
	return 0;
}