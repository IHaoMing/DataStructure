#include"DoubleList.h"
#include<iostream>

int main()
{
	dList d;
	int arr[5] = { 1, 2, 3, 4, 5 };
	d.create(arr, 5);
	d.print();
	
	d.deletePos(5);
	d.print();

	d.insert(4, 0);
	d.print();

	std::getchar();
	return 0;
}