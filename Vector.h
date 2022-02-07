#pragma once
#include <iostream>
#include <ctime>
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
		cout << "DESTRUCTOR! " << this << "\n";
		if (data != nullptr) delete[] data;
	}

	Vector(const Vector& other) //copy constructor
	{
		this->size = other.size;
		this->capacity = other.capacity;

		this->data = new int[other.capacity];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Copy consructor " << this << "\n";
	}

	Vector& operator = (const Vector& other); //���������� ��������� =

	bool operator==(const Vector& other); // ���������� ��������� ==

	bool operator!=(const Vector& other); // ���������� ��������� !=

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
	void PushBack(int value); //���������� �������� � ����� �������
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
	void Clone(const Vector& array_to_copy); // ����� ������ ������ ����� �������
	void Print() const;
};

