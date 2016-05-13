//
//  HashNode.cpp
//  NodesProjectoBoss
//
//  Created by Baker, Rory on 5/9/16.
//  Copyright © 2016 Baker, Rory. All rights reserved.
//

#include "HashNode.hpp"

template<class Type>
HashNode<Type> :: HashNode()
{
    
}

template<class Type>
HashNode<Type> :: HashNode(int key, const Type& value)
{
    this->key = key;
    this->value = value;
}

template<class Type>
int HashNode<Type> :: getKey()
{
    return key;
}

template<class Type>
Type HashNode<Type> :: getValue()
{
    return value;
}