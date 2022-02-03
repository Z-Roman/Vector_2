#include <iostream>
#include "Vector.h"
using namespace std;



int main()
{
	Vector ar;
	ar.PushBack(1);
	ar.PushBack(2);
	ar.PushBack(3);
	ar.Print();
	ar.PushFront(4);
	ar.Print();
	ar.Clear();
	ar.Print();
}