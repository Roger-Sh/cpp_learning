#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树节点
typedef struct BINARYNODE
{
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

// 递归先序遍历
void Recursion_preorder(BinaryNode* root);

// 递归中序遍历
void Recursion_inorder(BinaryNode* root);

// 递归后序遍历
void Recursion_postorder(BinaryNode* root);

// 获取叶子节点数目，即没有子节点的节点
void getLeafNum(BinaryNode* root, int &num);

// 获取二叉树高度
void getTreeHeight(BinaryNode* root, int &height);

// 拷贝二叉树
BinaryNode* CopyBinaryTree(BinaryNode* root);

// 释放二叉树
void FreeSpaceBinaryTree(BinaryNode* root);

#endif // BINARYTREE_H