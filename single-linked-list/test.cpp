#include"SingleList.h"
#include<iostream>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	sList s;
	s.create(arr, 5);
	s.print();
	s.add(6);
	s.print();
	s.deletePos(6);
	s.print();

	std::getchar();
	return 0;
}