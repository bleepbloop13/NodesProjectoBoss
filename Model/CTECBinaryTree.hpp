//
//  CTECBinaryTree.hpp
//  NodesProjectoBoss
//
//  Created by Baker, Rory on 4/13/16.
//  Copyright © 2016 Baker, Rory. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp

#include "TreeNode.cpp"

    template <class Type>
    class CTECBinaryTree
    {
    private:
        int size;
        TreeNode<Type> * root;
        int height;
        bool balanced;
        void calculateSize(TreeNode<Type> * currentNode);
        bool contains(Type value, TreeNode<Type> * currentTree);
        TreeNode<Type>* getRightMostChild(TreeNode<Type> * leftSubTree);
        TreeNode<Type>* getLeftMostChild(TreeNode<Type> * rightSubTree);
    public:
        CTECBinaryTree();
        virtual ~CTECBinaryTree();
        bool insert(const Type& value);
        void remove (const Type& value);
        void remove(TreeNode<Type> * nodeToBeRemoved);
        bool contains (Type value);
        int getSize();
        int getHeight();
        bool isBalanced();
        TreeNode<Type> * getRoot();
        void preorderTraversal(TreeNode<Type> * currentNode);
        void inorderTraversal(TreeNode<Type> * currentNode);
        void postorderTraversal(TreeNode<Type> * currentNode);
    };


#endif /* CTECBinaryTree_hpp */
