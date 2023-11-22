#include "MyHashTable.h"
#include <iostream>
using namespace std;

int main(){

    MyHashTable *tabla = new MyHashTable();
    tabla->put("b", 18);

    cout << *tabla.get("b") << endl;

    return 0;
}
