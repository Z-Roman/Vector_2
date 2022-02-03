#include "Vector.h"

void Vector::EnsureCapacity(int new_size)
{
	if (capacity < new_size)
	{
		capacity = capacity * 3 / 2 + 1;
		int* copy = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			copy[i] = data[i];
			delete[] data;
			data = copy;
		}
	}
}

void Vector::PushBack(int value)
{
	EnsureCapacity(size + 1); // проверка, хватит ли места для нового элемента
	data[size++] = value;
}

void Vector::PushFront(int value)
{
	EnsureCapacity(size + 1);
	for (int i = size; i > 0; i--)
	{
		data[i] = data[i - 1];
	}
	data[0] = value;
	size++;
}

void Vector::Clear() //обнуление массива
{
	data[0] = 0;
	size = 0;
}

void Vector::Insert(int index, int value)
{
	EnsureCapacity(size + 1);
	for (int i = size; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[index] = value;
	size++;
}

bool Vector::IsEmpty() const
{
	return size == 0;
}

void Vector::Print() const
{
	if (IsEmpty())
	{
		cout << "Vector is empty.\n";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}
}

