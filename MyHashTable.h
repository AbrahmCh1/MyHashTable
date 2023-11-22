#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "MyLinkedList.h"
#include <string>
#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

class MyHashTable
{
public:
    MyLinkedList *tabla;
    int size;  // Cantidad de valores que hay almacenados en la tabla
    int sizeA; // Cantidad del arreglo
    void rehashing();
    int getPos(string key);

    MyHashTable();
    ~MyHashTable();
    bool isEmpty();
    void put(string key, int value);
    int get(string key);
    void remove(string key);
};

#endif