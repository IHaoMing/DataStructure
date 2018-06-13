//data structure
//double linked list

#include"DoubleList.h"
#include<iostream>

Node* dList::create(int arr[], int len)
{
	head = new Node(arr[0]);
	head->p_pre = nullptr;
	Node* phead_bp = head;
	for (int i = 1; i < len; ++i)
	{
		Node* p_new = new Node(arr[i]);
		head->p_next = p_new;
		p_new->p_pre = head;
		p_new->p_next = nullptr;
		head = p_new;
	}
	tail = head;
	head = phead_bp;
	return head;
}

void dList::print()
{
	Node* p = head;
	while (p)
	{
		std::cout << p->data << '\t';
		p = p->p_next;
	}
	std::cout << std::endl;
}

void dList::insert(int pos_data, int new_data)
{
	//插在尾部节点
	if (tail->data == pos_data)
	{
		Node* p_new = new Node(new_data);
		tail->p_next = p_new;
		p_new->p_pre = tail;
		tail = p_new;
		tail->p_next = nullptr;
		return;
	}

	Node* p = head;
	for (;;)
	{
		if (p->data == pos_data)
		{
			Node* p_new = new Node(new_data);
			p_new->p_next = p->p_next;
			p->p_next->p_pre = p_new;

			p_new->p_pre = p;
			p->p_next = p_new;
			return;
		}
		p = p->p_next;
	}
}

void dList::deletePos(int pos_data)
{
	if (head == nullptr) { return; }

	//删除头部节点
	if (head->data == pos_data)
	{
		head = head->p_next;
		head->p_pre = nullptr;
		return;
	}

	//删除尾部节点
	if (tail->data == pos_data)
	{
		tail = tail->p_pre;
		tail->p_next = nullptr;
		return;
	}
	Node* p = head;
	for (;;)
	{
		if (p->data == pos_data)
		{
			p->p_next->p_pre = p->p_pre;
			p->p_pre->p_next = p->p_next;
			delete p;
			return;
		}
		p = p->p_next;
	}
}