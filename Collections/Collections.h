#pragma once
namespace LinkedList
{
template <class T>
	class ListElement_class
	{
	private:
		T _data;
		ListElement_class* _next = nullptr;
	public:
		T& Data() { return _data; }
		ListElement_class*& Next() { return _next; }

		ListElement_class(T data)
		{
			Data() = data;
		}
		ListElement_class(T data, ListElement_class* next)
		{
			Data() = data;
			Next() = next;
		}
	};

template<class T>
	class LinkedList_class
	{
	private:

		ListElement_class<T>* _lastPtr = nullptr;
		int _lastPos = -1;
		ListElement_class<T>* _tail = nullptr;
		ListElement_class<T>* _head = nullptr;
		int _size = 0;
	public:
		ListElement_class<T>*& Tail() { return _tail; }
		ListElement_class<T>*& Head() { return _head; }

		ListElement_class<T>* PushBack(T data)
		{
			if (_size == 0)
			{
				ListElement_class<T>* item = new ListElement_class<T>(data);
				_size++;
				Head() = item;
				Tail() = item;
				return item;
			}
			else
			{
				Tail()->Next() = new ListElement_class<T>(data);
				Tail() = Tail()->Next();
				_size++;
				return Tail();
			}
			
		}
		ListElement_class<T>* PushFront(T data)
		{
			if (_size == 0)
			{
				return PushBack(data);
			}
			else
			{
				ListElement_class<T>* item = new ListElement_class<T>(data);
				item->Next() = Head();
				Head() = item;
				_size++;
			}
		}
		ListElement_class<T>* PushAt(int pos, T data)
		{
			if (pos <= 0)
			{
				PushFront(data);
			}
			else if (pos >= _size)
			{
				PushBack(data);
			}
			else
			{
				if (_lastPos <= pos - 1 && _lastPos != -1)
				{
					while (_lastPos < pos - 1)
					{
						_lastPtr = _lastPtr->Next();
						_lastPos++;
					}
					ListElement_class<T>* item = new ListElement_class<T>(data, _lastPtr->Next());
					_lastPtr->Next() = item;
					_size++;
					return item;
				}
				else
				{
					_lastPtr = Head();
					_lastPos = 0;
					return PushAt(pos, data);
				}
			}
		}
		int GetSize()
		{
			return _size;
		}
	};
}
	