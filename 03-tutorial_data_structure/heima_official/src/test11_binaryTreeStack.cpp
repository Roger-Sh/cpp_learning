/**
 * @file BinaryTreeStack.cpp
 * @author your name (you@domain.com)
 * @brief 二叉树的非递归遍历
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StackLink.h"

// 二叉树节点
typedef struct BINARYNODE
{
    char ch;
    struct BINARYNODE *lchild;
    struct BINARYNODE *rchild;
} BinaryNode;

typedef struct BITREESTACKNODE
{
    ST_L::LinkNode node;
    BinaryNode* root;
    bool flag;

}BiTreeStackNode;

// 创建栈中的节点
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node, bool flag)
{
    BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
    newnode->root = node;
    newnode->flag = flag;

    return newnode;
}


// 非递归遍历二叉树
void NonRecursionBinaryTree(BinaryNode* root)
{
    // 创建栈
    ST_L::StackLink* stack = ST_L::init_StackLink();

    // 把根结点放入栈中
    ST_L::push_StackLink(stack, (ST_L::LinkNode *)CreateBiTreeStackNode(root, false));

    // 非递归遍历二叉树
    while (ST_L::getSize_StackLink(stack) > 0)
    {
        // 先弹出栈顶元素
        BiTreeStackNode* node = (BiTreeStackNode*) ST_L::top_StackLink(stack);
        ST_L::pop_StackLink(stack);

        // 判断弹出的节点是否为空
        if (node->root == NULL)
        {
            continue;
        }

        // 判断节点flag
        if (node->flag == true)
        {
            std::cout << node->root->ch;
        }
        else
        {
            // 先序遍历
            // 右节点入栈
            ST_L::push_StackLink(stack, (ST_L::LinkNode *)CreateBiTreeStackNode(node->root->rchild, false));
            // 左节点入栈
            ST_L::push_StackLink(stack, (ST_L::LinkNode *)CreateBiTreeStackNode(node->root->lchild, false));
            // 当前节点入栈
            node->flag = true;
            ST_L::push_StackLink(stack, (ST_L::LinkNode *)node);

            // // 中序遍历
            // // 右节点入栈
            // ST_L::push_StackLink(stack, (ST_L::LinkNode *)CreateBiTreeStackNode(node->root->rchild, false));
            // // 当前节点入栈
            // node->flag = true;
            // ST_L::push_StackLink(stack, (ST_L::LinkNode *)node);
            // // 左节点入栈
            // ST_L::push_StackLink(stack, (ST_L::LinkNode *)CreateBiTreeStackNode(node->root->lchild, false));

            // // 后序遍历
            // // 当前节点入栈
            // node->flag = true;
            // ST_L::push_StackLink(stack, (ST_L::LinkNode *)node);
            // // 右节点入栈
            // ST_L::push_StackLink(stack, (ST_L::LinkNode *)CreateBiTreeStackNode(node->root->rchild, false));
            // // 左节点入栈
            // ST_L::push_StackLink(stack, (ST_L::LinkNode *)CreateBiTreeStackNode(node->root->lchild, false));
        }
    }
    std::cout << std::endl;
    

}


// 创建二叉树
void createBinaryTree()
{
    // 创建节点
    BinaryNode node1 = {'A', NULL, NULL};
    BinaryNode node2 = {'B', NULL, NULL};
    BinaryNode node3 = {'C', NULL, NULL};
    BinaryNode node4 = {'D', NULL, NULL};
    BinaryNode node5 = {'E', NULL, NULL};
    BinaryNode node6 = {'F', NULL, NULL};
    BinaryNode node7 = {'G', NULL, NULL};
    BinaryNode node8 = {'H', NULL, NULL};

    // 建立节点关系
    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;

    // 二叉树非递归打印
    NonRecursionBinaryTree(&node1); 
}



int main(int argc, char const *argv[])
{
    createBinaryTree();


    return 0;
}
