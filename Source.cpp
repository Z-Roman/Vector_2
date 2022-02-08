#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	setlocale(0, "");

	Vector ar;
	Vector ar2;

	ar.PushBack(1);
	ar.PushBack(2);
	ar.PushBack(3);
	cout << "Добавлено 3 элемента в конец массива\n";
	ar.Print();

	ar.PushBack(4);
	ar.PushBack(5);
	ar.PushBack(4);
	ar.PushBack(3);
	ar.PushBack(6);
	cout << "Добавлено еще 5 элементов в конец массива\n";
	ar.Print();

	ar2.PushBack(1);
	ar2.PushBack(2);
	ar2.PushBack(3);
	ar2.PushBack(4);
	ar2.PushBack(5);
	ar2.PushBack(4);
	ar2.PushBack(3);
	ar2.PushBack(6);
	cout << "Добавлено 8 элементов в массив ar2\n";
	ar2.Print();

	cout << "\nСравнение массивов ar.Equals(ar2): " << ar.Equals(ar2) << "\n"; //1
	
	cout << "\nУдаление элементов, значение которых совпадает со значением переданного параметра ar.Remove(4): \n";
	ar.Remove(4);
	ar.Print();

	cout << "\nPushFront(int value) добавление элемента 4 в начало массива: \n";
	ar.PushFront(4);
	ar.Print();

	cout << "\nInsert(int index, int value) вставка элемента 10 по указанному индексу 2: \n";
	ar.Insert(2, 10);
	ar.Print();

	cout << "\nRemoveAt(int index)удаление элемента по указанному индексу 1: \n";
	ar.RemoveAt(1);
	ar.Print();

	cout << "\nRemoveAt(int index); //удаление элемента по указанному индексу 22: \n";
	ar.RemoveAt(22);
	ar.Print();

	ar.PushBack(1);
	ar.PushBack(2);
	ar.PushBack(3);
	ar.PushBack(4);
	ar.Print();

	cout << "\nPopFront() удаление первого элемента из массива: \n";
	ar.PopFront();
	ar.Print();

	cout << "\nPopBack() удаление последнего элемента из массива: \n";
	ar.PopBack();
	ar.Print();

	cout << "\nTrimToSize() метод подгоняет значение capacity под size: \n";
	ar.TrimToSize();
	ar.Print();

	cout << "\nПоиск элемента с лева на право: \n";
	cout << "IndexOf 1 - " << ar.IndexOf(1) << "\n";

	cout << "\nПоиск элемента с конца: \n";
	cout << "LastIndexOf 3 - " << ar.LastIndexOf(3) << "\n";

	cout << "\nReverse() Отзеркалить массив: \n";
	ar.Print();
	ar.Reverse();
	ar.Print();

	cout << "\nSortAsc() быстрая сортировка значений элементов массива по возрастанию: \n";
	ar.SortAsc();
	ar.Print();

	cout << "\nSortDesc() быстрая сортировка значений элементов массива по убыванию: \n";
	ar.SortDesc();
	ar.Print();

	cout << "\nShuffle() случайное перемешивание элементов массива: \n";
	ar.Shuffle();
	ar.Print();

	cout << "еще раз: \n";
	ar.Shuffle();
	ar.Print();

	cout << "и еще раз: \n";
	ar.Shuffle();
	ar.Print();

	cout << "\nRandomFill() заполнение массива случайными значениями: \n";
	ar.RandomFill();
	ar.Print();

	cout << "\nGetElementAt(int index) возврат копии элемента массива по указанному индексу, с проверкой на выход за пределы массива: \n";
	cout << "GetElementAt(2): " << ar.GetElementAt(2) << "\n";
	cout << "GetElementAt(50): " << ar.GetElementAt(50) << "\n";

	cout << "\nar.Clone(ar2) клонирование массива: \n";
	ar.Clone(ar2);
	ar.Print();

	cout << "\nVector ar3(ar) копирование массива: \n";
	Vector ar3(ar);
	ar3.Print();

	cout << "\nИнициализация объекта ar4: \n";
	Vector ar4;
	cout << "Перегрузка оператора = (ar4 = ar3):\n";
	ar4 = ar3;
	cout << "ar3.Print(): \n";
	ar3.Print();
	cout << "ar4.Print(): \n";
	ar4.Print();

	cout << "\nar.Print(): \n";
	ar.Print();
	cout << "ar2.Print(): \n";
	ar2.Print();
	cout << "bool result = ar == ar2;: \n";
	bool result = ar == ar2;
	cout << "Перегрузка оператора ==: " << result << "\n";  //false

	cout << "\nbool result = ar3 == ar4;: \n";
	result = ar3 == ar4;
	cout << "Перегрузка оператора ==: " << result << "\n";  //true
	ar.Print();

	cout << "\nПерегрузка оператора []: ar[2] = " << ar[2] << "\n";

	cout << "\nПерегрузка оператора <<: cout << ar; \n";
	cout << ar;

	cout << "\nar.Clear(); обнуление массива \n";
	ar.Clear();
	ar.Print();
	cout << "\n";
}