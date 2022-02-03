#pragma once
#include <iostream>
using namespace std;

class Vector
{
	int size = 0; // ���������� ������������� �������������� ��������� � ����������
	int capacity = 10; // ������� (���������������, ����� ������)
	int* data; // ��������� �� ������������ ������ ������

	void EnsureCapacity(int new_size);

public:
	Vector() : Vector(10){}
	Vector(int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
	}
	~Vector()
	{
		cout << "DESTRUCTOR!\n";
		if (data != nullptr) delete[] data;
	}

	void SetCapacity(int capacity)
	{
		this->capacity = capacity;
	}
	int GetSize()
	{
		return size;
	}
	int GetCapacity()
	{
		return capacity;
	}

	void PushBack(int value);
	void PushFront(int value);
	void Clear(); //��������� �������

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
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
			cout << endl;
		}
	}

	// ��������� ������ ����������� �������� ����� ;)
};

