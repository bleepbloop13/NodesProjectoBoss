/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: rbak9218
 */

#include <iostream>
#include <assert.h>
#include "CTECList.h"

template<class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

template<class Type>
CTECList<Type>::~CTECList()
{
	ArrayNode<Type> * current = head;

	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type> * temp = current;
		current = current->getNext();
		head = current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}

template<class Type>
int CTECList<Type>::getSize()
{
	return size;
}

template<class Type>
Type CTECList<Type>::getFront()
{
	return head->value;
}

template<class Type>
Type CTECList<Type>::getEnd()
{
	return end->value;
}

template<class Type>
Type CTECList<Type>::getFromIndex(int index)
{
	ArrayNode<Type> * current = head;
	for(int i = 1; i <= index; i++)
	{
		if(i == index)
		{
			return current->getValue();
		}
		current = current->getNext();
	}
    return current->getValue();
}

template<class Type>
Type CTECList<Type>::set(int index, const Type& value)
{
	assert(index < size && index >= 0);

	ArrayNode<Type> * current = head;
	Type returnValue;
	for (int spot = 0; spot <= index; spot++)
	{
		if (spot != index)
		{
			current = current->getNext();
		}
		else
		{
			returnValue = current->getValue();
			current->setValue(value);
		}
	}
	return returnValue;
}

template<class Type>
void CTECList<Type>::addToFront(const Type& value)
{
	ArrayNode<Type> * current = head;
	ArrayNode<Type> * newFirst = new ArrayNode<Type>(value);

	newFirst->setNext(current);
	head = newFirst;
    calculateSize();
}

template<class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	assert(size >= 0);
	assert(index >= 0);
	assert(index <= size);

	ArrayNode<Type> * currentSpot = head;
    ArrayNode<Type> * nextSpot = nullptr;
    ArrayNode<Type> * newNext;
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);

    
    
	for (int spot = 0; spot < index + 1; index++)
	{

		if (spot == index - 1)
		{
            newNext = newNode;
            nextSpot = currentSpot->getNext()->getNext();
			currentSpot->setNext(newNext);
		}
        if(spot == index)
        {
            newNode->setNext(nextSpot);
        }
		currentSpot = currentSpot->getNext();
	}
    calculateSize();
}

template<class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
	assert(size >= 0);


	ArrayNode<Type> * newEnd = new ArrayNode<Type>(value);
	ArrayNode<Type> * currentSpot = end;

	currentSpot->setNext(newEnd);
	newEnd->setNext(nullptr);
    calculateSize();
}

template<class Type>
Type CTECList<Type>::removeFromFront()
{
	Type thingToRemove;
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = this->head->getNext();
	thingToRemove = this->head->getValue();
    calculateSize();
	return thingToRemove;
}

/*
 * Loops to last node to remove that node , and sets the preceding node to end.
 * If size == 1, removes the only value.
 */
template<class Type>
Type CTECList<Type>::removeFromEnd()
{
	assert(size > 0);

	Type returnValue;
	if (size == 1)
	{
		ArrayNode<Type> * toRemove = end;
		returnValue = removeFromFront();
		end = nullptr;
		head = nullptr;
		delete toRemove;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for (int pos = 0; pos < size - 1; pos++)
		{
			current = current->getNext();
		}
		returnValue = end->getValue();
		delete end;
		current = end;
	}
    calculateSize();
	return returnValue;
}

template<class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
	assert(size > 0 && index >= 0 && index < size);

	Type thingToRemove;
	ArrayNode<Type> * current = head;
	ArrayNode<Type> * previousSpot;
	ArrayNode<Type> * newNext;

	for (int spot = 0; spot < index + 1; spot++)
	{
		if (spot == index - 1)
		{
			previousSpot = current;
		}
		if (spot == index)
		{
			thingToRemove = current->getValue();
			newNext = current->getNext();
			delete current;
		}
		current = current->getNext();
	}
	previousSpot->setNext(newNext);
    calculateSize();
	return thingToRemove;
}

template<class Type>
int CTECList<Type>::indexOf(Type searchValue)
{
    assert(this->size > 0);
    ArrayNode<Type> * searchPointer;
    
    
    int index = 0;
    
    for(searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer->getNext())
    {
        if(searchValue == searchPointer->getValue())
        {
            return index;
        }
        index++;
    }
    
    return index;
}

template<class Type>
void CTECList<Type>::calculateSize()
{
	assert(size >= 0);

	int count = 0;

	if (head == nullptr)
	{
		this->size = 0;
	}
	else
	{
		count++;
		ArrayNode<Type> * current = head;
		while(current->getNext() != nullptr)
		{
			count++;
			current = current->getNext();
		}
        this->size = count;
	}
}
