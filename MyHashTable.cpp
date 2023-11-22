#include "MyHashTable.h"

using namespace std;

int MyHashTable::getPos(string key)
{
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % sizeA;
}

MyHashTable::MyHashTable()
{
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new MyLinkedList[this->sizeA];
}

MyHashTable::~MyHashTable()
{
    delete[] this->tabla;
}

bool MyHashTable::isEmpty()
{
    return this->size == 0;
}

void MyHashTable::put(string key, int value)
{
    int pos = getPos(key);
    this->tabla[pos].insertLast(key, value);
    this->size++;
}

int MyHashTable::get(string key)
{
    int pos = getPos(key);

    // Check if the key exists in the hash table at the specified position
    if(this->tabla[pos].isEmpty()){
        return -1; // Key not found, return -1
    }
    // Iterate through the linked list and return the value if the key matches
    MyNodoLL *current = this->tabla[pos].head;
    while (current != nullptr){
        if (key == current->key){
            return this->tabla[pos].last();
        }
        current = current->next;
    }

    // Key not found in the linked list
    return -1;
}

void MyHashTable::remove(string key)
{
    int pos = getPos(key);
    MyNodoLL *current = this->tabla[pos].head;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            break;
        }
        current = current->next;
    }
    // Check if the key exists in the hash table at the specified position
    if (this->tabla[pos].isEmpty())
    {
        return; // Key not found, do nothing
    }

    this->tabla[pos].removeLast();
    this->size--;
}

void MyHashTable::rehashing()
{
    MyLinkedList *aux = this->tabla;
    this->sizeA = this->sizeA * 2 + 1;
    this->tabla = new MyLinkedList[this->sizeA];
    for (int i = 0; i < this->sizeA / 2; i++)
    {
        while (!aux[i].isEmpty())
        {
            this->put("a", aux[i].last());
            aux[i].removeLast();
        }
    }
    delete[] aux;
}