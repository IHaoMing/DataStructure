//data structure
//double linked list

#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_

struct Node
{
    int data;
    Node* p_pre;
    Node* p_next;

    Node(int da): data(da), p_pre(nullptr), p_next(nullptr) {}
};

class dList
{
public:
    Node* create(int arr[] = {}, int len = 0);
    void print();
    void insert(int pos_data, int new_data);
    void deletePos(int pos_data);
private:
    Node* head;
    Node* tail;
};
#endif