/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: rbak9218
 */

#include "NodeController.h"
#include <iostream>
using namespace std;

NodeController::NodeController()
{
	notHipsterWorld = new CTECArray<int>(5);
	testList = new CTECList<int>();

}

NodeController::~NodeController()
{
	// TODO Auto-generated destructor stub
}

void NodeController::quicksort(int first, int last)
{
    int pivotIndex;
    
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quicksort(first, pivotIndex-1);
        quicksort(pivotIndex+1, last);
    }
}

int NodeController::partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    swap(first, smallIndex);
    
    return smallIndex;
}

void NodeController::swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController::doQuick()
{
    mergeData = new int[1000000000];

    for(int spot = 0; spot < 1000000000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    quicksort(0, 1000000000-1);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    delete [] mergeData;
}

void NodeController::testLists()
{
	testList->addToFront(3);
    testList->addAtIndex(1, 5);
	testList->addToEnd(8);
	cout << "End should be 8 and is: " << testList->getEnd() << endl;
	cout << "Head should be 3 and is: " << testList->getFront() << endl;
	cout << "Index 1 should be 5 and is: " << testList->getFromIndex(1) << endl;
	testList->removeFromEnd();
	cout << "End should now be 5 and is: " << testList->getEnd() << endl;
	testList->removeFromFront();
	cout << "Head should now be 5 and is: " << testList->getFront() << endl;
	testList->addToFront(7);
	testList->addToEnd(10);
	testList->removeFromIndex(1);
	cout << "Index 1 should now be 10 and is: " << testList->getFromIndex(1) << endl;

}

void NodeController::doMergesort()
{
    mergeData = new int[500000];
    
    for (int spot = 0; spot < 500000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", ";
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 500000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", ";
    }
    delete [] mergeData;
}

void NodeController::mergesort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        mergesort(data, sizeOne);
        mergesort((data+sizeOne), sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
}

void NodeController::merge(int data[],int sizeOne, int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while ((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne) [copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController :: tryTree()
{
    CTECBinaryTree<int> firstTree;
    firstTree.insert(72);
    firstTree.insert(1325);
    firstTree.insert(6);
    firstTree.insert(13);
    firstTree.insert(1);
    firstTree.insert(2);
    firstTree.insert(5);
    firstTree.insert(14);
    firstTree.insert(19);
    cout << "this is post insertion" << endl;
    firstTree.inorderTraversal(firstTree.getRoot());
    firstTree.remove(72);
    cout << "this is post removal" << endl;
    firstTree.inorderTraversal(firstTree.getRoot());
    firstTree.insert(84);
    cout << "this is post second insertion" << endl;
    firstTree.postorderTraversal(firstTree.getRoot());
    firstTree.remove(2);
    cout << "this is post second removal" << endl;
    firstTree.preorderTraversal(firstTree.getRoot());
}

void NodeController:: tryGraphs()
{
    CTECGraph<int> testGraph;
    //Add 7 vertices
    testGraph.addVertex(2);
    testGraph.addVertex(5);
    testGraph.addVertex(6);
    testGraph.addVertex(1);
    testGraph.addVertex(3);
    testGraph.addVertex(4);
    testGraph.addVertex(7);
    testGraph.addVertex(9);
    testGraph.addVertex(12);
    testGraph.addVertex(19);
    //Add enough edges including a loop
    testGraph.addEdge(0,0);
    testGraph.addEdge(0,1);
    testGraph.addEdge(1,2);
    testGraph.addEdge(2,3);
    testGraph.addEdge(3,4);
    testGraph.addEdge(4,5);
    testGraph.addEdge(5,6);
    testGraph.addEdge(6,7);
    testGraph.addEdge(7,8);
    testGraph.addEdge(8,9);
    testGraph.addEdge(6,2);
    testGraph.addEdge(5,2);
    //test both travrsals
    testGraph.depthFirstTraversal(testGraph, 0);
    testGraph.breadthFirstTraversal(testGraph, 0);
}

void NodeController :: tryHashTables()
{
    CTECHashTable<int> testTable;
    HashNode<int> tempArray[10];
    for(int spot = 0; spot < 10; spot++)
    {
        int key = spot;
        int value = spot + 1;
        HashNode<int> * temp = new HashNode<int>(key, value);
        testTable.add(*temp);
        tempArray[spot] = *temp;
        
    }
    
    bool test = testTable.contains(tempArray[1]);
    string result;
    if(test)
    {
        result = "yes";
    }
    else
    {
        result = "no";
    }

    cout << result << endl;
}

void NodeController::start()
{
	arrayTimer.startTimer();

	//for(int index = 0; index < notHipsterWorld->getSize(); index++)
	//{
	//	notHipsterWorld->set(index, (index * 13));
	//}

	//for(int index = notHipsterWorld->getSize()-1; index >= 0; index--)
	//{
	//	cout << "The contents of the notHipsterWorld array node " << index << " are: " << notHipsterWorld->get(index) << endl;
	//}

	//testLists();
    //doMergesort();
    //tryTree();
    //tryGraphs();
    tryHashTables();
    
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
}
