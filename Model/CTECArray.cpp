/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: rbak9218
 */

#include "CTECArray.h"
#include <iostream>
#include <assert.h>
using namespace std;

/**
 * Constructor for the class. Assigns pointers and creates array.
 */
template<class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
	this->head = nullptr;

	//Defensive
	assert(size > 0);
	for (int index = 0; index <= size; index++)
	{
		if (head != nullptr)
		{
			//Regular nodes are being made
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode->setNext(head);
			this->head = nextNode;
		}
		else
		{
			//the first ArrayNode is made;
			ArrayNode<Type> * firstNode = new ArrayNode<Type>();
			this->head = firstNode;
		}
	}
}
/**
 * Returns the size pointer for the array.
 */
template<class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}

/**
 * Sets the value to a specific position. If/else tests if input is out of bounds.
 */
template<class Type>
void CTECArray<Type>::set(int position, const Type& value)
{
		//I am out of bounds and need to do something about it.
		assert(position < size && position >= 0);
		//I am in bounds so I am inclusive
		ArrayNode<Type> * current = head;
		for (int spot = 0; spot <= position; spot++)
		{
			if (spot != position)
			{
				current = current->getNext();
			}
			else
			{
				current->setValue(value);
			}
		}

}

/**
 * Gets the value at a specific position. If/else tests if position is out of bounds.
 */
template<class Type>
Type CTECArray<Type>::get(int position)
{
	/*
	 * Bnds check for size and negative
	 * The call to assert checks that the postion lies within
	 */
	assert(position < size && position >= 0);

		ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= position; spot++)
		{
			if (spot != position)
			{
				current = current->getNext();
			}
			else
			{
				return current->getValue();
			}
		}
    return current->getValue();
}

/**
 * Deconstructs all pointers.
 */
template<class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for (int index = 0; index < size; index++)
	{
		if (deleteMe->getNext() != nullptr)
		{
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);
		}
		delete deleteMe;
		deleteMe = head;
	}
	delete head;
}

