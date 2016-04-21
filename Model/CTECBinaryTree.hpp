//
//  CTECBinaryTree.hpp
//  NodesProjectoBoss
//
//  Created by Baker, Rory on 4/13/16.
//  Copyright © 2016 Baker, Rory. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp

#include "TreeNode.hpp"

    template <class Type>
    class CTECBinaryTree
    {
    private:
        int size;
        TreeNode<Type> * root;
        int height;
        bool balanced;
        void calculateSize(TreeNode<Type> * currentNode);
        bool contains(Type value, CTECBinaryTree<Type> * currentTree);
        TreeNode<Type>* getRightMostChild(TreeNode<Type> * leftSubTree);
        TreeNode<Type>* getLeftMostChild(TreeNode<Type> * rightSubTree);
    public:
        CTECBinaryTree();
        ~CTECBinaryTree();
        bool insert(const Type& value);
        Type remove (const Type& value);
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
