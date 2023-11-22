// Abraham Chavez Matricula: A016424666
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
using namespace std;

struct MyNodoLL
{
    int data;
    string key;
    MyNodoLL *next;

    MyNodoLL(int data, MyNodoLL *next, string key)
    {
        this->data = data;
        this->next = next;
        this->key = key;
    }
    MyNodoLL(int data, MyNodoLL *next)
    {
        this->data = data;
        this->next = next;
    }
};

class MyLinkedList
{
public:
    int size;
    MyNodoLL *tail;
    MyNodoLL *head;
    MyLinkedList();
    ~MyLinkedList();
    int length();
    bool isEmpty();
    int first();
    int last();
    int getAt(int pos);
    void setAt(int pos, int data);
    void insertFirst(int data);
    void insertLast(string key, int data);
    void insertAt(int pos, int data);
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    friend ostream &operator<<(ostream &os, const MyLinkedList &ll)
    {
        MyNodoLL *current = ll.head;
        while (current != nullptr)
        {
            os << current->data << ",";
            current = current->next;
        }
        return os;
    }
};

#endif
