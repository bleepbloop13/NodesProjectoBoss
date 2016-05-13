//
//  CTECHashTable.hpp
//  NodesProjectoBoss
//
//  Created by Baker, Rory on 5/5/16.
//  Copyright © 2016 Baker, Rory. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp
#include "HashNode.cpp"
#include "CTECList.cpp"
#include <stdio.h>

namespace CTECData
{
    template <class Type>
    class CTECHashTable
    {
    private:
        int size;
        int capacity;
        HashNode<Type> ** internalStorage;
        double efficiencyPercentage;
        
        int chainedCapacity;
        int chainedSize;
        CTECList<HashNode<Type>> * chainedStorage;
        void updateChainCapacity();
        
        
        int findPosition(HashNode<Type> currentNode);
        int handleCollision(HashNode<Type> currentNode);
        void updateCapacity();
        
        int getNextPrime();
        bool isPrime(int candidateNumber);
    public:
        CTECHashTable();
        ~CTECHashTable();
        
        void add(HashNode<Type> currentNode);
        bool remove(HashNode<Type> currentNode);
        bool contains(HashNode<Type> currentNode);
        int getSize();
    };
}

#endif /* CTECHashTable_hpp */
