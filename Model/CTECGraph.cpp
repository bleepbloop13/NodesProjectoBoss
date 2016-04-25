//
//  CTECGraph.cpp
//  NodesProjectoBoss
//
//  Created by Baker, Rory on 4/25/16.
//  Copyright © 2016 Baker, Rory. All rights reserved.
//

#include "CTECGraph.hpp"

using namespace CTECData;

template <class Type>
const int CTECGraph<Type> :: MAXIMUM;

template <class Type>
void CTECGraph<Type> :: addVertex(const Type& value)
{
    assert(size() < MAXIMUM);
    int newVertexNumber = manyVertices;
    manyVertices++;
    
    for(int iterator = 0; iterator < manyVertices; iterator++)
    {
        adjacencyMatrix[iterator][newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][iterator] = false;
    }
    labels[newVertexNumber] = value;
}

template <class Type>
void CTECGraph<Type> :: addEdge(int source, int target)
{
    
}