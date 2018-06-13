// data structure 
// single linked list
// SingleList.cpp

#include"SingleList.h"
#include<iostream>

Node* sList::create(int a[], int len)
{
	head = tail = nullptr;
	if (len <= 0) { return nullptr; }

	head = new Node(0);
	tail = new Node(a[0]);
	head->next = tail;

	
	for (int i = 1; i < len; ++i)
	{
		Node* p = new Node(a[i]);
		tail->next = p;
		tail = p;
	}

	head = head->next;

	return head;
}

void sList::print()
{
	if (head == nullptr) { return; }
	Node* p = head;
	while (p != tail->next)
	{
		std::cout << p->data << '\t';
		p = p -> next;
	}
	std::cout<<std::endl;
}

void sList::insert(int pos_data, int new_data)//在pos_data节点后面插入节点new_data
{
	if (head == nullptr) { return; }
	Node* p = head;

	while (p->data != pos_data)
		p = p -> next;

	Node* pNew = new Node(new_data);
	pNew->next = p->next;
	p->next = pNew;
}
void sList::add(int new_data)//链表尾部增加节点new_data
{
	if (tail == nullptr) { return; }
	Node* pNew = new Node(new_data);
	tail->next = pNew;
	tail = pNew;
}
void sList::destroy()
{
	if (head == nullptr) { return; }
	Node* p = nullptr;
	while (head)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

void sList::clear()
{
	if (head == nullptr) { return; }
	Node* p = head->next;
	Node* q = nullptr;

	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
}

void sList::deletePos(int pos_data)
{
	Node* pAhead = nullptr;
	Node* p = head;

	//删除的头部节点
	if (p->data == pos_data)
	{
		head = head->next;
		return;
	}

	for (;;)
	{
		pAhead = head;
		if (head->next->data == pos_data)
		{
			//删除尾部节点
			if (tail->data == pos_data)
			{
				delete tail;
				tail = head;
				head = p;
				return;
			}
			pAhead->next = head->next;
			head = p;
			return;
		}
		head = head->next;
	}
}