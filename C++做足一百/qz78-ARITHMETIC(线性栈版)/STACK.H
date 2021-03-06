#ifndef _STACK_H_

#define _STACK_H_

#include <string>

const int STACK_INIT_SIZE = 20;

const int STACK_INCREMENT = 30;

template <typename T>
class STACK
{
public:
	STACK();
	~STACK();
	STACK(const STACK<T>& x);
	const STACK<T>& operator =(const STACK<T>& x);
	void Clear();
	bool IsEmpty()const;
	int Length()const;
	T& Top();
	void Push(const T& x);
	const T& Pop();
	STACK<T> Traverse(T (*Visit)(const T& x))const;
	T operator[](int i)const;
	bool IsExist(const T& x)const;
	void Display()const;
	
private:
	T *base, *top;
	int stacksize, length;
};

template <typename T>
STACK<T>::STACK()
{
	stacksize = STACK_INIT_SIZE;
	length = 0;
	base = new T[stacksize];
	top = base;
}

template <typename T>
STACK<T>::~STACK()
{
	delete [] base;
}

template <typename T>
STACK<T>::STACK(const STACK<T>& x)
{
	int i;
	stacksize = x.stacksize;
	length = x.length;
	base = new T[stacksize];
	for(i = 0; i < length; i ++)
	{
		base[i] = x.base[i];
	}
	top = base + length;
}

template <typename T>
const STACK<T>& STACK<T>::operator =(const STACK<T>& x)
{
	int i;
	if(this != &x)
	{
		delete [] base;
		stacksize = x.stacksize;
		length = x.length;
		base = new T [stacksize];
		for(i = 0; i < length; i ++)
		{
			base[i] = x.base[i];
		}
		top = base + length;
	}
	return *this;
}

template <typename T>
void STACK<T>::Clear()
{
	length = 0;
	top = base;
}


template <typename T>
bool STACK<T>::IsEmpty()const
{
	return length == 0;
}

template <typename T>
int STACK<T>::Length()const
{
	return length;
}

template <typename T>
T& STACK<T>::Top()
{
	if(length > 0)
	{
		return *(top - 1);
	}
	else
	{
		throw string("此栈为空!");
	}
}

template <typename T>
void STACK<T>::Push(const T& x)
{
	T *p, *q = base;
	int i;
	if(length >= stacksize)
	{
		p = new T[length];
		for(i = 0; i < length; i ++)
		{
			p[i] = base[i];
		}
		delete [] base;
		stacksize += STACK_INCREMENT;
		base = new T[stacksize];
		for(i = 0; i < length; i ++)
		{
			base[i] = p[i];
		}
		delete [] p;
		top = base + length;
	}
	*top = x;
	length ++;
	top ++;
}

template <typename T>
const T& STACK<T>::Pop()
{
	if(length > 0)
	{
		length --;
		return *(--top);
	}
	else
	{
		throw string("此栈为空，不能推出数据!");
	}
} 

template <typename T>
STACK<T> STACK<T>::Traverse(T (*Visit)(const T& x))const
{
	STACK<T> other(*this);
	T* p = other.base;
	for(; p != other.top; p ++)
	{
		*p = Visit(*p);
	}
	return other;
}

template <typename T>
T STACK<T>::operator[](int n)const
{
	if(n >= 1 && n <= length)
	{
		return base[n - 1];
	}
	else
	{
		throw string("引用的参数错误!");
	}
}

template <typename T>
bool STACK<T>::IsExist(const T& x)const
{
	int i;
	for(i = 0; i < length; i ++)
	{
		if(x == base[i])
		{
			return true;
		}
	}
	return false;
}
		
template <typename T>
void STACK<T>::Display()const
{
	T* p = base;
	for(; p != top; p ++)
	{
		cout << *p;
	}
}


#endif