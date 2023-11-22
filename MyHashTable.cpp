#include "MyHashTable.h"
#include <functional>
#include <cmath>
#include <string>
#include <list>
#include <iostream>


using namespace std;

int MyHashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
    cout << "hashcode: " << hashCode << endl;
}

MyHashTable::MyHashTable(){
    this-> size= 0;
    this-> sizeA= 11;
    this->tabla = new list<int>[this->sizeA];
}

MyHashTable::~MyHashTable(){
    delete[] this->tabla;
}

bool MyHashTable::isEmpty(){
    return this->size==0;
}

void MyHashTable::rehashing(){
    int sizeA2=this->sizeA*2;
    list<int> *tabla2 = new list<int>[sizeA2];
    for(int i=0;i<this->sizeA;i++){
        for(int j=0;j<this->tabla[i].size();j++){
            int pos=getPos(to_string(this->tabla[i].front()));
            tabla2[pos].push_back(this->tabla[i].front());
            this->tabla[i].pop_front();
        }
    }
    this->sizeA=sizeA2;
    delete[] this->tabla;
    this->tabla=tabla2;
}

void MyHashTable::put(string key, int value){
    if(this->size/this->sizeA<=0.75){
        rehashing();
    }
    cout << this->sizeA << endl;
    int pos=getPos(key);
    cout << "pos: " << pos << endl;
    this->tabla[pos].push_back(value);
    this->size++;
    cout << "size: " << this->size << endl;
}

int MyHashTable::get(string key){
    int pos = getPos(key);
    for(int i = 0; i < this->tabla[pos].size(); i++){
        cout << this->tabla[pos].front() << endl;
        try {
            int value = this->tabla[pos].front();
            if (value == stoi(key)) {
                return value;
            }
        } catch (const std::invalid_argument& e) {
            // Handle the invalid argument exception here
            // You can log an error message or perform any necessary error handling
        }
        this->tabla[pos].pop_front();
    }
    return -1;
}

