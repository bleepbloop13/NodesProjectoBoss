/*
 * Node.h
 *
 *  Created on: Jan 27, 2016
 *      Author: rbak9218
 */

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

template <class Type>
class Node {
private:
	Type value; //What is stored in the node.
	Node * pointers; // Reference to the array of nodes this is connected to.
public:
	Node();
	Node(const Type& value);
	virtual ~Node();
	Type getValue();
	void setValue(const Type& value);
	Node * getPointers();
};

#endif /* MODEL_NODE_H_ */
