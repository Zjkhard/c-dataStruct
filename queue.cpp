// queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<list>
using namespace std;


//���е�����ʵ��  �Ƚ��ȳ�
template<class T,int size=100>
class ArrayQueue{
public:
	ArrayQueue(){
		first = last = -1;
	}
	bool isFull()   //�����Ƿ�Ϊ��
	{
		return first == 0 && last == size - 1 || first == last + 1;
	}
	bool isEmpty()  //�����Ƿ�Ϊ��
	{
		return first == -1;
	}
	void enqueue(T); //�����
	T dequeue();    //������
public:
	int first, last;
	T storage[size];
};

template<class T,int size>
void ArrayQueue<T, size>::enqueue(T el)
{
	if (!isFull())
	{
		if (last==size-1||last==-1)
		{
			storage[0] = el;
			last = 0;
			if (first==-1)
			{
				first = 0;
			}
		}
		else
		{
			storage[++last] = el;
		}
	}
	else
	{
		cout << "Full queue.\n";
	}
}


template<class T, int size>
T ArrayQueue<T, size>::dequeue()
{
	T tmp;
	tmp = storage[first];
	if (first==last)
	{
		last = first = -1;
	}
	else if (first==size-1)
	{
		first = 0;
	}
	else
	{
		first++;
	}
	return tmp;
}



//���е�����ʵ��
template<class T> class Queue{
public:
	Queue(){}
	void clear(){
		lst.clear();
	}
	bool isEmpty() const
	{
		return lst.empty();
	}
	T& front()
	{
		return lst.front();
	}
	T dequeue()
	{
		T el = lst.front();
		lst.pop_front();
		return el;
	}

	void enqueue(const T& el)
	{
		lst.push_back(el);
	}
private:
	list<T> lst;
};








int _tmain(int argc, _TCHAR* argv[])
{
	ArrayQueue<int, 20> arr;
	arr.enqueue(10);
	arr.enqueue(20);

	cout << "first=" << arr.first <<"last=" <<arr.last<<endl;
	cout << arr.dequeue() << endl;
	cout << arr.dequeue() << endl;

	Queue<int> Q;
	Q.enqueue(0);
	Q.enqueue(1);
	Q.enqueue(2);
	cout << Q.dequeue() << endl;
	cout << Q.front() << endl;
	cout << Q.isEmpty() << endl;


	system("pause");
	return 0;
}

