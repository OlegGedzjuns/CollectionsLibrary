#include "Collections.h"

using namespace SortedList;

#if _DEBUG
	#include <string>
	#include <iostream>
	using namespace std;
#endif

int main()
{
#if _DEBUG
	SortedList_class<string>* myList = new SortedList_class<string>();
	myList->Add("B");
	myList->Add("D");
	myList->Add("A");
	myList->Add("C");
	myList->Add("A");
	for (auto it = myList->Head(); it != nullptr; it = it->Next())
	{
		cout << it->Data() << " ";
	}
	cout << endl << myList->GetSize() << endl;

	cin.get();
#endif
	return 0;
}