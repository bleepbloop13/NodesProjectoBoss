/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: rbak9218
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_
#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/ArrayNode.h"
#include "../Model/CTECArray.cpp"
#include "../Model/CTECList.cpp"
#include "../Model/Timer.h"
#include <string>
using namespace std;

class NodeController
{
private:
	CTECArray<int> * notHipsterWorld;
	CTECList<int> * testList;
	Timer arrayTimer;
	void testLists();
    
    void swap(int first, int second);
    void quicksort(int first, int last);
    int partition(int first, int last);
    void doQuick();
    
    int * mergeData;
    void doMergesort();
    void mergesort(int data [], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
