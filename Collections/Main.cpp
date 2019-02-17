#include "Collections.h"

using namespace LinkedList;

#if _DEBUG
	#include <iostream>
	using namespace std;
#endif

int main()
{
#if _DEBUG
	LinkedList_class<int>* myList = new LinkedList_class<int>();
	for (int i = 0; i < 10; i++)
	{
		myList->PushBack(i);
	}

	LinkedList_class<int>* secondList = new LinkedList_class<int>(myList);
	myList->Clear();
	secondList->PushBack(100);
	secondList->CopyTo(myList);
	secondList->PopBack();

	for (auto it = myList->Head(); it != nullptr; it = it->Next())
	{
		cout << it->Data() << " ";
	}
	cout << endl << myList->GetSize() << endl;

	for (auto it = secondList->Head(); it != nullptr; it = it->Next())
	{
		cout << it->Data() << " ";
	}
	cout << endl << secondList->GetSize() << endl;

	cin.get();
#endif
	return 0;
}