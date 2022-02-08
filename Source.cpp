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
	ar.PushBack(4);
	ar.PushBack(5);
	ar.PushBack(4);
	ar.PushBack(3);
	ar.PushBack(6);
	ar2.PushBack(1);
	ar2.PushBack(2);
	ar2.PushBack(3);
	ar2.PushBack(4);
	ar2.PushBack(5);
	ar2.PushBack(4);
	ar2.PushBack(3);
	ar2.PushBack(6);
	ar.Print();
	ar2.Print();
	ar.Equals(ar2);
	cout << ar.Equals(ar2) <<"\n";
	ar.Remove(4);
	ar.Print();
	ar.PushFront(4);
	ar.Print();
	ar.Insert(2, 10);
	ar.Print();
	ar.RemoveAt(1);
	ar.Print();
	ar.RemoveAt(22);
	ar.Print();
	ar.PushBack(1);
	ar.PushBack(2);
	ar.PushBack(3);
	ar.PushBack(4);
	ar.Print();
	ar.PopFront();
	ar.Print();
	ar.PopBack();
	ar.Print();
	ar.TrimToSize();
	ar.Print();
	cout << "IndexOf 1 - " << ar.IndexOf(1) << "\n";
	cout << "LastIndexOf 3 - " << ar.LastIndexOf(3) << "\n";
	ar.Reverse();
	ar.Print();
	ar.SortAsc();
	ar.Print();
	ar.SortDesc();
	ar.Print();
	ar.Shuffle();
	ar.Print();
	ar.Shuffle();
	ar.Print();
	ar.Shuffle();
	ar.Print();
	ar.RandomFill();
	ar.Print();
	cout << "GetElementAt(2): " << ar.GetElementAt(2) << "\n";
	ar.Clone(ar2);
	ar.Print();
	Vector ar3(ar);
	ar3.Print();
	Vector ar4;
	cout << "���������� ��������� =:\n";
	ar4 = ar3;
	ar4.Print();

	bool result = ar == ar2;
	cout << "���������� ��������� ==: " << result << "\n";  //false
	result = ar3 == ar4;
	cout << "���������� ��������� ==: " << result << "\n";  //true

	ar.Print();
	cout << "���������� ��������� []: ar[2] = " << ar[2] << "\n";

	cout << "���������� ��������� <<: ar \n";
	cout << ar;

	ar.Clear();
	ar.Print();
}