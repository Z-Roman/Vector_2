#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>

class Vector
{
	unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
	unsigned int capacity = 10; // Ємкость (вместительность, запас пам€ти)
	T* data; // указатель на динамический массив данных

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
	void PushBack(T value); //добавление элемента в конец массива
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
	void RandomFill(); // заполнение массива случайными значени€ми
	bool Equals(const Vector& other); // в качестве параметра передаЄтс€ указатель на другой вектор.ћетод сравнивает массивы не только по количеству элементов, но и по их содержимому
	int GetElementAt(int index);  //возврат копии элемента массива по указанному индексу, с проверкой на выход за пределы массива
	void Clone(const Vector& vector); // метод создаЄт точную копию вектора
	void Print() const;
};

