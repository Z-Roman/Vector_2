#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Vector
{
	int size = 0; // количество действительно присутствующих элементов в контейнере
	int capacity = 10; // Ємкость (вместительность, запас пам€ти)
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

	void PushBack(int value); //добавление элемента в конец массива
	void PushFront(int value); //добавление элемента в начало массива
	void Clear(); //обнуление массива
	void Insert(int index, int value); //вставка элемента по указанному индексу
	void RemoveAt(int index); //удаление элемента по указанному индексу
	void Remove(int value); //удаление одного или всех элементов, значение которых совпадает со значением переданного параметра
	void PopFront(); // удаление первого элемента из массива
	void PopBack(); // удаление последнего элемента из массива
	bool IsEmpty() const;
	void TrimToSize(); //метод подгон€ет значение capacity под size
	int IndexOf(int value); // линейный поиск слева направо первого вхождени€ в массив указанного значени€.¬ результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть - 1
	int LastIndexOf(int value); //линейный поиск справа налево вхождени€ в массив указанного значени€. ¬ результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть - 1
	void Reverse(); // изменение пор€дка следовани€ элементов в массиве на противоположный
	void SortAsc(); // быстра€ сортировка значений элементов массива по возрастанию
	void SortDesc(); // быстра€ сортировка значений элементов массива по убыванию
	void Shuffle(); // случайное перемешивание элементов массива
	void Print() const;
};

