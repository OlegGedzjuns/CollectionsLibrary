#pragma once
namespace LinkedList
{
	template<class T>
	class LinkedList_class
	{
	private:
		T _data;
		int _size = 0;
		LinkedList_class* _next = nullptr;
		LinkedList_class* _tail = this;
	public:
		T& Data() { return _data; }
		LinkedList_class*& Next() { return _next; }
		LinkedList_class*& Tail() { return _tail; }

		LinkedList_class()
		{

		}

		T& PushBack(T data)
		{
			if (_size == 0)
			{
				Data() = data;
				_size++;
				return Data();
			}
			else
			{
				Tail()->Next() = new LinkedList_class<T>;
				Tail() = Tail()->Next();
				Tail()->Data() = data;
				_size++;
				return Tail()->Data();
			}
			
		}
		//T& PushFront()
		int GetSize()
		{
			return _size;
		}
	};
}
	