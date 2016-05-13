//
//  HashNode.hpp
//  NodesProjectoBoss
//
//  Created by Baker, Rory on 5/9/16.
//  Copyright © 2016 Baker, Rory. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <iostream>
#include <stdio.h>

template<class Type>
class HashNode
{
private:
    int key;
    Type value;
public:
    HashNode();
    HashNode(int key, const Type& value);
    int getKey();
    Type getValue();
};

#endif /* HashNode_hpp */
