#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class TStack
{
private:
	T* stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int num;                          // номер текущего элемента стека
public:
	TStack(int = 25);                  // по умолчанию размер стека равен 25 элементам
	TStack(const TStack<T>&);          // конструктор копирования
	~TStack();                         // деструктор


	inline int IsEmpty(void) const; // контроль пустоты
	inline int IsFull(void) const; // контроль переполнения
	inline void put(const T&);     // поместить элемент в вершину стека
	inline T deleteElem();          // удалить элемент из вершины стека и вернуть его
	inline const T& Peek(int) const; // n-й элемент от вершины стека
	inline int getStackSize() const;  // получить размер стека
	inline T* getPtr() const;         // получить указатель на стек
	inline int getNum() const;        // получить номер текущего элемента в стеке

	//Доп задания
	inline int min_elem(); //Поиск минимального элемента
	inline int max_elem(); //Поиск максимального элемента


	friend ostream& operator<<(ostream& out, const TStack& st)
	{
		for (int ix = st.num - 1; ix >= 0; ix--)
			cout << st.stackPtr[ix] << endl;
		return out;
	}
};

// конструктор Стека
template <typename T>
TStack<T>::TStack(int maxSize) : size(maxSize) // инициализация константы
{
	if (maxSize < 0)
	{
		throw  logic_error("ERROR");
	}
	stackPtr = new T[size]; // выделить память под стек
	num = 0; // инициализируем текущий элемент нулем;
}

template <typename T> // контроль пустоты
inline int TStack<T>::IsEmpty() const
{
	return stackPtr == NULL;

	for (int i = 0; i < size; i++)
	{
		if (stackPtr[i] == 0)
		{
			continue;
		}
		else
		{
			throw  logic_error("ERROR");
		}

	}
}


template <typename T> // контроль переполнения
inline int TStack<T>::IsFull() const
{

	for (int i = 0; i < size; i++)
	{
		if (stackPtr[i] != 0)
		{
			continue;
		}
		else
		{
			throw  logic_error("ERROR");
		}
	}
}


// конструктор копирования
template <typename T>
TStack<T>::TStack(const TStack<T>& otherStack) : size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	num = otherStack.getNum();

	for (int ix = 0; ix < num; ix++)
	{
		stackPtr[ix] = otherStack.getPtr()[ix];
	}
}
//деструктор
template <typename T>
TStack<T>::~TStack()
{
	if (this->stackPtr != NULL)
	{
		delete[] stackPtr; // удаляем стек
	}
	num = 0;
}

// функция добавления элемента в стек
template <typename T>
inline void TStack<T>::put(const T& value)
{
	if (num > size - 1 || num < 0)
	{
		throw  logic_error("ERROR");
	}

	stackPtr[num++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline T TStack<T>::deleteElem()
{
	if (num < NULL)
	{
		throw  logic_error("ERROR");
	}

	stackPtr[--num]; // удаляем элемент из стека

	return stackPtr[num];
}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T& TStack<T>::Peek(int Elem) const
{
	if (Elem > num)
	{
		throw  logic_error("ERROR");
	}
	return stackPtr[num - Elem]; // вернуть n-й элемент стека
}

// вернуть размер стека
template <typename T>
inline int TStack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T* TStack<T>::getPtr() const
{
	return stackPtr;
}

// вернуть размер стека
template <typename T>
inline int TStack<T>::getNum() const
{
	return num;
}

//Поиск максимального элемента
template<typename T>
inline int TStack<T>::max_elem()
{
	int res = stackPtr[0];
	for (int i = 1; i < size; i++)
	{
		if (stackPtr[i] > res)
		{
			res = stackPtr[i];
		}
	}
	return res;
}

//Поиск минимального элемента
template<typename T>
inline int TStack<T>::min_elem()
{
	int res = stackPtr[0];
	for (int i = 1; i < size; i++)
	{
		if (stackPtr[i] < res)
		{
			res = stackPtr[i];
		}
	}
	return res;
}

#endif