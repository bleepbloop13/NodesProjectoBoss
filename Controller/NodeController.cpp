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

void NodeController::testLists()
{
	testList->addToFront(3);
	testList->addToEnd(8);
	testList->addAtIndex(1, 5);
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

void NodeController::start()
{
	arrayTimer.startTimer();

	for(int index = 0; index < notHipsterWorld->getSize(); index++)
	{
		notHipsterWorld->set(index, (index * 13));
	}

	for(int index = notHipsterWorld->getSize()-1; index >= 0; index--)
	{
		cout << "The contents of the notHipsterWorld array node " << index << " are: " << notHipsterWorld->get(index) << endl;
	}

	testLists();

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();

}
