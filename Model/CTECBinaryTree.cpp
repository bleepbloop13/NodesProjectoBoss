//
//  CTECBinaryTree.cpp
//  NodesProjectoBoss
//
//  Created by Baker, Rory on 4/13/16.
//  Copyright © 2016 Baker, Rory. All rights reserved.
//

#include "CTECBinaryTree.hpp"
#include <iostream>
using namespace std;

template<class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    this->root = nullptr;
    this->size = 0;
    this->height = 0;
    this->balanced = true;
}

template<class Type>
int CTECBinaryTree<Type> :: getSize()
{
    size = 0;
    size = calculateSize(root);
    return size;
}

template<class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild());
        calculateSize(currentNode->getRightChild());
        size++;
    }
}

template<class Type>
TreeNode<Type>* CTECBinaryTree<Type> :: getRoot()
{
    
}

template <class Type>
void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue() << " ";
        preorderTraversal(currentNode->getLeftChild());
        preorderTraversal(currentNode->getRightChild());
    }
}

template<class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " ";
        inorderTraversal(currentNode->getRightChild());
    }
}

template<class Type>
void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " ";
    }
}

template<class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    bool isInTree = false;
    
    if(root != nullptr)
    {
        if(root->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value > root->getValue())
            {
                isInTree = contains(value, root->getLeftChild());
            }
            if(value < root->getValue())
            {
                isInTree = contains(value, root->getRightChild());
            }
        }
    }
    
    return isInTree;
}

template<class Type>
TreeNode<Type>* CTECBinaryTree<Type> :: getRightMostChild(TreeNode<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree;
    while(rightNode->getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}

template<class Type>
TreeNode<Type>* CTECBinaryTree<Type> :: getLeftMostChild(TreeNode<Type> * rightSubTree)
{
    TreeNode<Type> leftNode = rightSubTree;
    while(leftNode->getLeftChild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}


template<class Type>
bool CTECBinaryTree<Type> :: insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    else
    {
        TreeNode<Type> * currentNode = root;
        TreeNode<Type> * trailNode;
        
        if(root == nullptr)
        {
            root = new TreeNode<Type>(value);
        }
        else
        {
            while(currentNode != nullptr)
            {
                trailNode = currentNode;
                
                if (currentNode->getValue() < value)
                {
                    currentNode = currentNode->getRightChild();
                }
                else
                {
                    currentNode = currentNode->getLeftChild();
                }
            }
            if(trailNode->getValue() > value)
            {
                trailNode-setLeftChild(new TreeNode<Type>(value, trailNode));
            }
            else
            {
                TreeNode<Type> * insertedNode = new TreeNode<Type>(value, trailNode);
                trailNode->setRightChild(insertedNode);
            }
        }
    }
    return true;
}

template<class Type>
bool CTECBinaryTree<Type> :: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    bool isInTree = false;
    
    if(currentTree != nullptr)
    {
        if(currentTree->getRoot()->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value > currentTree->getRoot()->getValue())
            {
                isInTree = contains(value, currentTree->getRoot()->getLeftChild());
            }
            if(value < currentTree->getRoot()->getValue())
            {
                isInTree = contains(value, currentTree->getRoot()->getRightChild());
            }
        }
    }
    return isInTree;
}

template<class Type>
Type CTECBinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    
    if(!contains(value))
    {
        return;
    }
    else
    {
        current= root;
        trailing = root;
        
        while(current != nullptr && current->getvalue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        if(current == root)
        {
            remove(root);
        }
        else if(trailing->getValue() > value)
        {
            remove(trailing->getLeftChild());
        }
        else
        {
            remove(trailing->getRightChild());
        }
    }
}