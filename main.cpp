#include "MyHashTable.h"
#include <iostream>
using namespace std;

int main()
{

    MyHashTable *tabla = new MyHashTable();
    tabla->put("b", 1);
    tabla->put("a", 2);
    tabla->put("c", 3);
    tabla->put("d", 4);
    tabla->put("e", 5);
    tabla->put("f", 32);

    cout
        << tabla->get("h") << endl;
    // remove
    tabla->remove("e");

    cout << tabla->get("a") << endl;

    return 0;
}
