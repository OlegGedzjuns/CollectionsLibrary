#include "Collections.h"
#include <iostream>

using namespace LinkedList;
using namespace std;

int main()
{
	LinkedList_class<int>* myList = new LinkedList_class<int>;
	for (auto it = myList->Head(); it != nullptr; it = it->Next())
	{
		cout << it->Data() << " ";
	}
	cout << endl << myList->GetSize();
	cin.get();
	return 0;
}