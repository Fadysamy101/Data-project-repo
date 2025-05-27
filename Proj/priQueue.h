#pragma once
#include "priNode.h"


//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
    priNode<T>* head;
    int count=0;
public:
    priQueue() : head(nullptr) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp,p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {

        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {
            count++;
            newNode->setNext(head);
            head = newNode;
            return;
        }
       
        priNode<T>* current = head;        
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext( current->getNext());
        current->setNext( newNode);        
        count++;
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem();
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
    int getLength() {
        if (isEmpty())
            return 0;

        int count = 0;
        priNode<T>* current = head;
        while (current) {
            count++;
            current = current->getNext();
        }
        return count;
    }
   
    void printQueue() {
        if (isEmpty())
            return;
        priNode<T>* ptr = head;
        cout << "[";
        while (ptr)
        {
            int x = ptr->getPri();
            cout << ptr->getItem(x);
            if (ptr->getNext() == nullptr)
            {
                cout << "]";
                return;
            }
            cout << ",";
            ptr = ptr->getNext();
        }
        cout << "]";
    }
    int getCount()
    {
        return count;
    }

};
