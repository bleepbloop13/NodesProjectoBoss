/*
 * ArrayNode.h
 *
 *  Created on: Jan 29, 2016
 *      Author: rbak9218
 */

#ifndef MODEL_ARRAYNODE_H_
#define MODEL_ARRAYNODE_H_

#include "Node.h"
template <class Type>
class ArrayNode : public Node<Type>
{
private:
	ArrayNode<Type> * next;
public:
	ArrayNode();
	ArrayNode(const Type& value);
	ArrayNode(const Type& value, ArrayNode * next);
	virtual ~ArrayNode();
	ArrayNode * getNext();
	void setNext(ArrayNode * next);
	Type value;
};

#endif /* MODEL_ARRAYNODE_H_ */