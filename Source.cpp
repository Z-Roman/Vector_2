#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	Vector ar;
	ar.PushBack(1);
	ar.PushBack(2);
	ar.PushBack(3);
	ar.PushBack(4);
	ar.PushBack(5);
	ar.PushBack(4);
	ar.PushBack(3);
	ar.PushBack(6);
	ar.Print();
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
	ar.Clear();
	ar.Print();
}