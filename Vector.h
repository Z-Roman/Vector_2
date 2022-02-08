#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

class Vector
{
	int size = 0; // количество действительно присутствующих элементов в контейнере
	int capacity = 10; // ёмкость (вместительность, запас памяти)
	int* data; // указатель на динамический массив данных

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

	Vector& operator = (const Vector& other); //перегрузка оператора =

	bool operator==(const Vector& other); // перегрузка оператора ==

	int& operator[](int index);// перегрузка оператора []

	friend istream& operator>>(istream& is, Vector& original);// перегрузка оператора >>

	friend ostream& operator<<(ostream& os, Vector& original); // перегрузка оператора <<

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
	void PushBack(int value); //добавление элемента в конец массива
	void PushFront(int value); //добавление элемента в начало массива
	void Clear(); //обнуление массива
	void Insert(int index, int value); //вставка элемента по указанному индексу
	void RemoveAt(int index); //удаление элемента по указанному индексу
	void Remove(int value); //удаление одного или всех элементов, значение которых совпадает со значением переданного параметра
	void PopFront(); // удаление первого элемента из массива
	void PopBack(); // удаление последнего элемента из массива
	bool IsEmpty() const;
	void TrimToSize(); //метод подгоняет значение capacity под size
	int IndexOf(int value); // линейный поиск слева направо первого вхождения в массив указанного значения.В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть - 1
	int LastIndexOf(int value); //линейный поиск справа налево вхождения в массив указанного значения. В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть - 1
	void Reverse(); // изменение порядка следования элементов в массиве на противоположный
	void SortAsc(); // быстрая сортировка значений элементов массива по возрастанию
	void SortDesc(); // быстрая сортировка значений элементов массива по убыванию
	void Shuffle(); // случайное перемешивание элементов массива
	void RandomFill(); // заполнение массива случайными значениями
	bool Equals(const Vector& other); // в качестве параметра передаётся указатель на другой вектор.Метод сравнивает массивы не только по количеству элементов, но и по их содержимому
	int GetElementAt(int index);  //возврат копии элемента массива по указанному индексу, с проверкой на выход за пределы массива
	void Clone(const Vector& array_to_copy); // метод создаёт точную копию вектора
	void Print() const;
};

