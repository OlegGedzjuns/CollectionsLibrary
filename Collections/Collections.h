#pragma once
namespace LinkedList
{
template <class T>
	class ListElement_class
	{
	private:
		T _data;
		ListElement_class<T>* _next = nullptr;
	public:
		T& Data() { return _data; }
		ListElement_class<T>*& Next() { return _next; }

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
				if (_lastPos >= 0)
				{
					_lastPos++;
				}
			}
		}
		ListElement_class<T>* PushAt(int index, T data)
		{
			if (index <= 0)
			{
				PushFront(data);
			}
			else if (index >= _size)
			{
				PushBack(data);
			}
			else
			{
				if (_lastPos <= index - 1 && _lastPos != -1)
				{
					while (_lastPos < index - 1)
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
					return PushAt(index, data);
				}
			}
		}
		bool PopBack()
		{
			if (_size > 1)
			{
				while (_lastPos < _size - 2)
				{
					if (_lastPos < 0)
					{
						_lastPos = 0;
						_lastPtr = Head();
					}
					_lastPtr = _lastPtr->Next();
					_lastPos++;
				}
				delete _lastPtr->Next();
				_lastPtr->Next() = nullptr;
				_size--;
				return true;
			}
			else if (_size == 1)
			{
				return PopFront();
			} 
			else
			{
				return false;
			}
		}
		bool PopFront()
		{
			if (_size > 0)
			{
				ListElement_class<T>* item = Head();
				Head() = Head()->Next();
				_size--;
				_lastPos--;
				delete item;
				return true;
			}
			else
			{
				return false;
			}
		}
		bool PopAt(int index)
		{
			if (_size > 0)
			{
				if (index >= _size - 1)
				{
					return PopBack();
				}
				else if (index <= 0)
				{
					return PopFront();
				}
				else
				{
					if (_lastPos <= index - 1 && _lastPos >= 0)
					{
						while (_lastPos < index - 1)
						{
							_lastPtr = _lastPtr->Next();
							_lastPos++;
						}
						ListElement_class<T>* item = _lastPtr->Next();
						_lastPtr->Next() = _lastPtr->Next()->Next();
						delete item;
						_size--;
						return true;
					}
					else
					{
						_lastPos = 0;
						_lastPtr = Head();
						return PopAt(index);
					}
				}
			}
			else
			{
				return false;
			}
		}
		int GetSize()
		{
			return _size;
		}
	};
}
	