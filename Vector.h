#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>

class Vector
{
	unsigned int size = 0; // ���������� ������������� �������������� ��������� � ����������
	unsigned int capacity = 10; // ������� (���������������, ����� ������)
	T* data; // ��������� �� ������������ ������ ������

	void EnsureCapacity(unsigned int new_size);

public:
	Vector() : Vector(10){}

	Vector(int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new T[capacity];
	}

	~Vector()
	{
		cout << "DESTRUCTOR! " << this << "\n";
		if (data != nullptr) delete[] data;
	}

	Vector(const Vector& other) //copy constructor
	{
		this->size = other.size;
		this->capacity = other.capacity;

		this->data = new T[other.capacity];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Copy consructor " << this << "\n";
	}

	void SetCapacity(unsigned int capacity)
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
	void PushBack(T value); //���������� �������� � ����� �������
	void PushFront(int value); //���������� �������� � ������ �������
	void Clear(); //��������� �������
	void Insert(int index, int value); //������� �������� �� ���������� �������
	void RemoveAt(int index); //�������� �������� �� ���������� �������
	void Remove(int value); //�������� ������ ��� ���� ���������, �������� ������� ��������� �� ��������� ����������� ���������
	void PopFront(); // �������� ������� �������� �� �������
	void PopBack(); // �������� ���������� �������� �� �������
	bool IsEmpty() const;
	void TrimToSize(); //����� ��������� �������� capacity ��� size
	int IndexOf(int value); // �������� ����� ����� ������� ������� ��������� � ������ ���������� ��������.� ���������� ������ ������� ������ ���������� ��������, � e��� ������ �� �������, ������� - 1
	int LastIndexOf(int value); //�������� ����� ������ ������ ��������� � ������ ���������� ��������. � ���������� ������ ������� ������ ���������� ��������, � e��� ������ �� �������, ������� - 1
	void Reverse(); // ��������� ������� ���������� ��������� � ������� �� ���������������
	void SortAsc(); // ������� ���������� �������� ��������� ������� �� �����������
	void SortDesc(); // ������� ���������� �������� ��������� ������� �� ��������
	void Shuffle(); // ��������� ������������� ��������� �������
	void RandomFill(); // ���������� ������� ���������� ����������
	bool Equals(const Vector& other); // � �������� ��������� ��������� ��������� �� ������ ������.����� ���������� ������� �� ������ �� ���������� ���������, �� � �� �� �����������
	int GetElementAt(int index);  //������� ����� �������� ������� �� ���������� �������, � ��������� �� ����� �� ������� �������
	void Clone(const Vector& vector); // ����� ������ ������ ����� �������
	void Print() const;
};

