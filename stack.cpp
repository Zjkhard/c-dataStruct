// stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;


//ջ������ʵ��  ջ�Ƚ���� 
template<class T, int capacity = 30> class Stack{
public:
	Stack(){
		pool.reserve(capacity);  //reserve������Ԥ���ռ� �ڴ˴�Ϊ30
	}
	void clear()      //���ջ
	{
		pool.clear();
	}
	bool isEmpty() const{  //const�������������޸���ʽthisָ������ͣ�������ɳ�ָ�볣�� ʹ�ÿ��Է��ʳ������ݳ�Ա
		return pool.empty();
	}
	T &topEL(){     //��ȡջ��Ԫ��
		return pool.back();
	}
	T pop(){       //��ջ
		T el = pool.back();
		pool.pop_back();
		return el;
	}

	void push(const T& el){   //ѹջ
		pool.push_back(el);
	}
private:
	vector<T> pool;   //�������� ��������
};




//ջ������ʵ��
template<class T> class LLStack{
public:
	LLStack(){}           //������
	void clear()        //���ջ �� �������
	{
		lst.clear();
	}
	bool isEmpty() const{  //�ж�ջ�Ƿ�Ϊ��
		return lst.empty();
	}
	T& topEL(){           //��ȡջ��Ԫ��
		return lst.back();
	}
	T pop(){              //��ջ
		T el = lst.back();
		lst.pop_back();
		return el;
	}
	void push(const T& el){  //ѹջ
		lst.push_back(el);
	}
private:
	list<T> lst;
};




int _tmain(int argc, _TCHAR* argv[])
{

	//Stack<int> s;
	LLStack<int> s;
	s.push(20);
	cout << s.isEmpty() << endl;

	s.push(18);
	cout << s.topEL() << endl;

	s.pop();
	cout << s.topEL() << endl;

	s.clear();
	cout << s.isEmpty() << endl;



	system("pause");
	return 0;
}

