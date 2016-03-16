/*
 * Node.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: rbak9218
 */
#include <iostream>
#include "Node.h"

/**
 * Assigns pointers default to nullptr.
 */
template <class Type>
Node<Type>::Node()
{
	this->pointers = nullptr;
}

/**
 * Assigns pointers to nullptr. Assigns value to inputed value.
 */
template <class Type>
Node<Type>::Node(const Type& value)
{
	this->value = value;
	this->pointers = nullptr;
}

template <class Type>
Node<Type>::~Node()
{
	// TODO Auto-generated destructor stub

}

/**
 * Returns value.
 */
template <class Type>
Type Node<Type>::getValue()
{
	return this->value;
}

/**
 * Sets value to input.
 */
template <class Type>
void Node<Type>::setValue(const Type& value)
{
	this->value = value;
}

/**
 * Returns pointers.
 */
template <class Type>
Node<Type>* Node<Type>:: getPointers()
{
	return this->pointers;
}
