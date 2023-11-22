#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include <list>

using namespace std;

class MyHashTable{
    public:
        list<int> *tabla;
        int size; // Cantidad de valores que hay almacenados en la tabla
        int sizeA; //Cantidad del arreglo
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