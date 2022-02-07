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
		}
		delete[] data;
		data = copy;
	}
}

Vector& Vector::operator=(const Vector& other) //перегрузка оператора =
{
	this->size = other.size;
	this->capacity = other.capacity;

	if (this->data != nullptr)
	{
		delete[] this->data;
	}

	this->data = new int[other.capacity];

	for (int i = 0; i < other.size; i++)
	{
		this->data[i] = other.data[i];
	}

	return *this;
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

void Vector::RemoveAt(int index) //удаление элемента по указанному индексу
{
	if (index < size)
	{
		for (int i = index; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}
	else cout << "no such index\n";
}

void Vector::Remove(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value) RemoveAt(i);
	}
}

void Vector::PopFront()
{
	RemoveAt(0);
}

void Vector::PopBack()
{
	RemoveAt(size - 1);
}

bool Vector::IsEmpty() const
{
	return size == 0;
}

void Vector::TrimToSize()  //метод подгоняет значение capacity под size
{
	if (capacity != size)
	{
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		capacity = size;
		data = temp;
	}
}

int Vector::IndexOf(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int Vector::LastIndexOf(int value)
{
	for (int i = size - 1; i > -1; i--)
	{
		if (data[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void Vector::Reverse()
{
	int* temp = new int[size];
	int j = size - 1;
	for (int i = 0; i < size; i++)
	{
		temp[j] = data[i];
		j--;
	}
	delete[] data;
	data = temp;
}

void Vector::SortAsc()  // быстрая сортировка значений элементов массива по возрастанию
{	
	int j;
	do
	{
		j = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (data[i] > data[i + 1])
			{
				int temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
				j++;
			}
		}
	} while (j != 0);	
}

void Vector::SortDesc() // быстрая сортировка значений элементов массива по убыванию
{
	int j;
	do
	{
		j = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (data[i] < data[i + 1])
			{
				int temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
				j++;
			}
		}
	} while (j != 0);
}

void Vector::Shuffle() // случайное перемешивание элементов массива
{
	srand(time(0));
	for (int i = 0; i < size * 2; i++)
	{
		int a = rand() % size;
		int b = rand() % size;
		if (a != b)
		{
			int temp = data[a];
			data[a] = data[b];
			data[b] = temp;
		}
	}
}

void Vector::RandomFill() // заполнение массива случайными значениями
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % 101;
	}
}

bool Vector::Equals(const Vector& other) // в качестве параметра передаётся указатель на другой вектор.Метод сравнивает массивы не только по количеству элементов, но и по их содержимому
{
	if (size == other.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != other.data[i])
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}

int Vector::GetElementAt(int index)  //возврат копии элемента массива по указанному индексу, с проверкой на выход за пределы массива
{
	int copy;
	if (index >= 0 && index < size)
	{
		copy = data[index];
		return copy;
	}
	else cout << "index outside of the array\n";
	return 0;
}

void Vector::Clone(const Vector& array_to_copy) // метод создаёт точную копию вектора
{
	int* copy = new int[array_to_copy.size];

	copy = data;
	/*for (int i = 0; i <= array_to_copy.size; i++)
	{
		cout << copy[i] << " ";
	}
	cout << "\n";*/
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
		cout << "   Size = " << size << "\tCapacity = " << capacity;
		cout << "\n";
	}
}

