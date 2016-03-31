/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: rbak9218
 */
#include <iostream>
#include "ArrayNode.h"

/**
 * Assigns next to null.
 */
template <class Type>
ArrayNode<Type>::ArrayNode() : Node<Type>()
{
	this->next = nullptr;
}

template <class Type>
ArrayNode<Type>::~ArrayNode()
{
	// TODO Auto-generated destructor stub
}

/**
 * Assigns next to null. Assigns value of node to inputed value.
 */
template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value) : Node<Type>(value)
{
	this->next = nullptr;
	this->value = value;
}

/**
 * Assigns next to another node. Assigns value of node to inputed value.
 */
template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value, ArrayNode<Type> * next) : Node<Type>(value)
{
	this->value = value;
	this->next = next;
}

/**
 * Gets the pointer for next.
 */
template <class Type>
ArrayNode<Type> * ArrayNode<Type>::getNext()
{
    return this->next;
}

/**
 * Sets the pointer for next to input.
 */
template <class Type>
void ArrayNode<Type>::setNext(ArrayNode<Type> * next)
{
	this->next = next;
}
