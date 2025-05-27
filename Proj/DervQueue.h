
/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The Node: item of type T and a "next" pointer
					-------------
					| item| next | --->
					-------------
General Queue case:

				 frontPtr																backPtr
					\											   						/
					 \											  					   /
					------------- 	  ------------- 	  ------------- 	  -------------
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

				 frontptr	 backptr
						\	 /
						 \	/
					---- NULL ------


Single Node Case:
				 frontPtr	 backPtr
					\		/
					 \	   /
					-----------
					|item| next| -->NULL
					-----------

*/

#ifndef DERV_QUEUE_
#define DERV_QUEUE_



#include "QueueADT.h"

#include <iostream>
using namespace std;


template <typename T>
class DervQueue :public QueueADT<T>
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	DervQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	bool dequeue_back(T& bckEntry);
	bool enqueue_front(const T& newEntry);
	int count=0;
	bool peekback(T& bckEntry)  const;
	void printQueue();

	int dummy_count_indicator = 0;
	bool Total_enqueue(T& entry);
	bool dequeue_Pair(T& frnt, T& bck);
	int getCount() const
	{
		return count;
	}

	~DervQueue();

	//copy constructor
	DervQueue(const DervQueue<T>& DQ);
	int getLength() {
		if (!frontPtr)
			return 0;
		if (backPtr == frontPtr)
			return 1;
		 count = 1;
		Node<T>* ptr = frontPtr;
		Node<T>* curptr = frontPtr;
		while(!(curptr==backPtr))
		{
		
			count++;
			curptr = curptr->getNext();
		}
		return count;
	}
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
DervQueue<T>::DervQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool DervQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DervQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	count++;
	return true;
	
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DervQueue<T>::dequeue(T& frntEntry)
{

	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;
	count--;
	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/
template <typename T>
bool DervQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////
/*
Function: destructor
removes all nodes from the queue by dequeuing them
*/
template <typename T>
DervQueue<T>::~DervQueue()
{
	//Free all nodes in the queue
	T temp;
	while (dequeue(temp));
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Copy constructor
To avoid shallow copy,
copy constructor is provided

Input: LinkedQueue<T>: The Queue to be copied
Output: none
*/

template <typename T>
DervQueue<T>::DervQueue(const DervQueue<T>& DQ)
{
	frontPtr = backPtr = nullptr;
	Node<T>* NodePtr = DQ.frontPtr;	//start at the front node in LQ
	while (NodePtr)
	{
		enqueue(NodePtr->getItem());	//get data of each node and enqueue it in this queue 
		NodePtr = NodePtr->getNext();
	}
}

template<typename T>
bool DervQueue<T>::enqueue_front(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	if (isEmpty())
		backPtr = newNodePtr;
	else
		newNodePtr->setNext(frontPtr);

	frontPtr = newNodePtr;
	return true;
}


template <typename T>
bool DervQueue<T>::dequeue_back(T& bckEntry)
{
	if (isEmpty())
		return false;

	bckEntry = backPtr->getItem();
	if (frontPtr == backPtr)
	{
		delete backPtr;
		frontPtr = backPtr = nullptr;
		return true;
	}
	

	Node<T>* ptr = frontPtr;

	while (ptr->getNext() != backPtr)
	{
		ptr = ptr->getNext();
	}
	
	delete backPtr;
	backPtr = ptr;
	backPtr->setNext(nullptr);
	return true;

}

template <typename T>
bool DervQueue<T>::peekback(T& bckEntry) const
{
	if (isEmpty())
		return false;

	bckEntry = backPtr->getItem();
	return true;

}

template <typename T>
void DervQueue<T>::printQueue() {
	if (isEmpty())
		return;
	Node<T>* ptr = frontPtr;
	cout << "[";
	while (ptr)
	{
		cout << ptr->getItem();
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

template <typename T>
bool DervQueue<T>::Total_enqueue(T &entry)
{
	if (dummy_count_indicator % 2 == 1)
	return enqueue_front(entry);

	if(dummy_count_indicator%2==0)
	return enqueue(entry);

}

template<typename T>
bool DervQueue<T>::dequeue_Pair(T& frnt,T& bck)
{
	
	 
	if (backPtr == frontPtr)
		return false;

	if (!isEmpty()) {
		dequeue(frnt);
		dequeue_back(bck);
	}
	else {
		return false;
	}

	return true;
}

#endif