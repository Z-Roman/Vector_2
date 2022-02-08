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
	cout << "��������� 3 �������� � ����� �������\n";
	ar.Print();

	ar.PushBack(4);
	ar.PushBack(5);
	ar.PushBack(4);
	ar.PushBack(3);
	ar.PushBack(6);
	cout << "��������� ��� 5 ��������� � ����� �������\n";
	ar.Print();

	ar2.PushBack(1);
	ar2.PushBack(2);
	ar2.PushBack(3);
	ar2.PushBack(4);
	ar2.PushBack(5);
	ar2.PushBack(4);
	ar2.PushBack(3);
	ar2.PushBack(6);
	cout << "��������� 8 ��������� � ������ ar2\n";
	ar2.Print();

	cout << "\n��������� �������� ar.Equals(ar2): " << ar.Equals(ar2) << "\n"; //1
	
	cout << "\n�������� ���������, �������� ������� ��������� �� ��������� ����������� ��������� ar.Remove(4): \n";
	ar.Remove(4);
	ar.Print();

	cout << "\nPushFront(int value) ���������� �������� 4 � ������ �������: \n";
	ar.PushFront(4);
	ar.Print();

	cout << "\nInsert(int index, int value) ������� �������� 10 �� ���������� ������� 2: \n";
	ar.Insert(2, 10);
	ar.Print();

	cout << "\nRemoveAt(int index)�������� �������� �� ���������� ������� 1: \n";
	ar.RemoveAt(1);
	ar.Print();

	cout << "\nRemoveAt(int index); //�������� �������� �� ���������� ������� 22: \n";
	ar.RemoveAt(22);
	ar.Print();

	ar.PushBack(1);
	ar.PushBack(2);
	ar.PushBack(3);
	ar.PushBack(4);
	ar.Print();

	cout << "\nPopFront() �������� ������� �������� �� �������: \n";
	ar.PopFront();
	ar.Print();

	cout << "\nPopBack() �������� ���������� �������� �� �������: \n";
	ar.PopBack();
	ar.Print();

	cout << "\nTrimToSize() ����� ��������� �������� capacity ��� size: \n";
	ar.TrimToSize();
	ar.Print();

	cout << "\n����� �������� � ���� �� �����: \n";
	cout << "IndexOf 1 - " << ar.IndexOf(1) << "\n";

	cout << "\n����� �������� � �����: \n";
	cout << "LastIndexOf 3 - " << ar.LastIndexOf(3) << "\n";

	cout << "\nReverse() ����������� ������: \n";
	ar.Print();
	ar.Reverse();
	ar.Print();

	cout << "\nSortAsc() ������� ���������� �������� ��������� ������� �� �����������: \n";
	ar.SortAsc();
	ar.Print();

	cout << "\nSortDesc() ������� ���������� �������� ��������� ������� �� ��������: \n";
	ar.SortDesc();
	ar.Print();

	cout << "\nShuffle() ��������� ������������� ��������� �������: \n";
	ar.Shuffle();
	ar.Print();

	cout << "��� ���: \n";
	ar.Shuffle();
	ar.Print();

	cout << "� ��� ���: \n";
	ar.Shuffle();
	ar.Print();

	cout << "\nRandomFill() ���������� ������� ���������� ����������: \n";
	ar.RandomFill();
	ar.Print();

	cout << "\nGetElementAt(int index) ������� ����� �������� ������� �� ���������� �������, � ��������� �� ����� �� ������� �������: \n";
	cout << "GetElementAt(2): " << ar.GetElementAt(2) << "\n";
	cout << "GetElementAt(50): " << ar.GetElementAt(50) << "\n";

	cout << "\nar.Clone(ar2) ������������ �������: \n";
	ar.Clone(ar2);
	ar.Print();

	cout << "\nVector ar3(ar) ����������� �������: \n";
	Vector ar3(ar);
	ar3.Print();

	cout << "\n������������� ������� ar4: \n";
	Vector ar4;
	cout << "���������� ��������� = (ar4 = ar3):\n";
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
	cout << "���������� ��������� ==: " << result << "\n";  //false

	cout << "\nbool result = ar3 == ar4;: \n";
	result = ar3 == ar4;
	cout << "���������� ��������� ==: " << result << "\n";  //true
	ar.Print();

	cout << "\n���������� ��������� []: ar[2] = " << ar[2] << "\n";

	cout << "\n���������� ��������� <<: cout << ar; \n";
	cout << ar;

	cout << "\nar.Clear(); ��������� ������� \n";
	ar.Clear();
	ar.Print();
	cout << "\n";
}