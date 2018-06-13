// data structure 
// single linked list
// SingleList.h

#ifndef _SINGLELIST_H_

#define _SINGLELIST_H_

struct Node
{
	int data;
	Node* next;

	Node(int da) : data(da), next(nullptr){ }
};


class sList
{
	Node* head;
	Node* tail;

public:
	Node* create(int a[] = {}, int len = 0);
	void print();
	void insert(int pos_data = 0, int new_data = 0);//在pos_data节点后面插入节点new_data
	void add(int new_data = 0);//链表尾部增加节点new_data
	void destroy();
	void clear();
	void deletePos(int pos_data);//删除节点

};

#endif
