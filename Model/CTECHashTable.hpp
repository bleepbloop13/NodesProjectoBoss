//
//  CTECHashTable.hpp
//  NodesProjectoBoss
//
//  Created by Baker, Rory on 5/5/16.
//  Copyright © 2016 Baker, Rory. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include <stdio.h>

namespace CTECData
{
    template <class Type>
    class CTECHashTable
    {
    private:
        int size;
        int capacity;
        Type * internalStorage;
        double efficiencyPercentage;
        
        int findPosition(const Type& value);
        int handleCollision(const Type& value);
        void updateCapacity();
    public:
        CTECHashTable();
        ~CTECHashTable();
        
        void add(const Type& value);
        bool remove(const Type& value);
        bool contains(const Type& value);
        int getSize();
    };
}

#endif /* CTECHashTable_hpp */
