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
	void Print() const;
};

