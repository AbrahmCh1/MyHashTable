// Abraham Chavez Matricula: A016424666
#include "MyLinkedList.h"

// Constructor por default, tiene una complejidad de O(1)
MyLinkedList::MyLinkedList()
{
    this->size = 0;
    this->head = this->tail = nullptr;
}

// Destructor, tiene una complejidad de O(n), esto debido a que tiene que recorrer todo el arreglo para eliminar cada elemento
MyLinkedList::~MyLinkedList()
{
    MyNodoLL *current = this->head;
    while (current != nullptr)
    {
        MyNodoLL *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Regresa el tamaño de la lista, tiene una complejidad de O(1)
int MyLinkedList::length()
{
    return this->size;
}

// Regresa verdadero o falso dependiendo si la lista esta vacia o no, tiene una complejidad de O(1)
bool MyLinkedList::isEmpty()
{
    return this->size == 0;
}

// Regresa el primer elemento de la lista, tiene una complejidad de O(1)
int MyLinkedList::first()
{
    if (this->size != 0)
    {
        return this->head->data;
    }
    else
    {
        throw invalid_argument("No se puede obtener el primer valor de una lista vacía");
    }
}

// Regresa el ultimo elemento de la lista, tiene una complejidad de O(1)
int MyLinkedList::last()
{
    if (isEmpty())
    {
        throw invalid_argument("No se puede obtener el último valor de una lista vacía");
    }
    else
    {
        return this->tail->data;
    }
}

// Regresa el elemento en la posición indicada, tiene una complejidad de O(n) ya que tiene que recoorer toda la lista hasta llegar a la posición indicada
int MyLinkedList::getAt(int pos)
{
    if (!(this->length() != 0 && pos >= 0 && pos <= this->length() - 1))
    {
        throw invalid_argument("Position out of bounds");
    }
    MyNodoLL *current = this->head;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    return current->data;
}

// Inserta un elemento al inicio de la lista, tiene una complejidad de O(1)
void MyLinkedList::insertFirst(int data)
{
    if (isEmpty())
    {
        this->head = this->tail = new MyNodoLL(data, this->head);
    }
    else
    {
        this->head = new MyNodoLL(data, this->head);
    }
    this->size++;
}

// Inserta un elemento al final de la lista, tiene una complejidad de O(1)
void MyLinkedList::insertLast(int data)
{
    if (isEmpty())
    {
        insertFirst(data);
    }
    else
    {
        this->tail->next = new MyNodoLL(data, nullptr);
        this->tail = this->tail->next;
        this->size++;
    }
}

// Inserta un elemento en la posición indicada, tiene una complejidad de O(n) ya que tiene que recorrer la lista hasta llegar a la posición indicada para insertar el elemento
void MyLinkedList::insertAt(int pos, int data)
{
    if (pos == 0)
    {
        insertFirst(data);
    }
    else if (pos == this->size)
    {
        insertLast(data);
    }
    else if (pos > 0 || pos < this->size)
    {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
        current->next = new MyNodoLL(data, current->next);
        this->size++;
    }
    else
    {
        throw invalid_argument("No puedes insertar un número en una posición no existente en tu lista");
    }
}

// Elimina el ultimo elemento de la lista, tiene una complejidad de O(n) ya que tiene que recorrer toda la lista hasta llegar al ultimo elemento
void MyLinkedList::removeLast()
{
    if (isEmpty())
    {
        throw invalid_argument("No puedes eliminar el ultimo elemento de una lista vacia");
    }
    else
    {
        MyNodoLL *current = this->head;
        while (current->next != this->tail)
        {
            current = current->next;
        }
        delete (this->tail);
        this->tail = current;
        this->tail->next = nullptr;
        this->size--;
    }
}

// Elimina el primer elemento de la lista, tiene una complejidad de O(1)
void MyLinkedList::removeFirst()
{
    if (isEmpty())
    {
        throw invalid_argument("No puedes eliminar el primer elemento de una lista vacia");
    }
    else
    {
        MyNodoLL *aux = this->head;
        this->head = this->head->next;
        delete aux;
        this->size--;
    }
}

// Elimina el elemento en la posición indicada, tiene una complejidad de O(n) ya que tiene que recorrer la lista hasta llegar a la posición indicada para eliminar el elemento
void MyLinkedList::removeAt(int pos)
{
    if (pos == 0)
    {
        removeFirst();
    }
    else if (pos == size - 1)
    {
        removeLast();
    }
    else
    {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
        MyNodoLL *aux = current->next;
        current->next = aux->next;
        delete aux;
        this->size--;
    }
}

// Modifica el elemento en la posición indicada, tiene una complejidad de O(n) ya que tiene que recorrer la lista hasta llegar a la posición indicada para modificar el elemento
void MyLinkedList::setAt(int pos, int data)
{
    if (pos == 0)
    {
        this->head->data = data;
    }
    else if (pos == this->size - 1)
    {
        this->tail->data = data;
    }
    else if (pos > 0 || pos < this->size)
    {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
        current->next->data = data;
    }
}