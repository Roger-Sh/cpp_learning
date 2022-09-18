#include "BinaryTree.h"

// 释放二叉树
void FreeSpaceBinaryTree(BinaryNode* root)
{
    // check NULL
    if (root == NULL)
    {
        return;
    }

    // 后序遍历释放二叉树
    FreeSpaceBinaryTree(root->lchild);
    FreeSpaceBinaryTree(root->rchild);

    printf("free %c\n", root->ch);
    free(root);
}

// 拷贝二叉树
BinaryNode* CopyBinaryTree(BinaryNode* root)
{
    // check NULL
    if (root == NULL)
    {
        return NULL;
    }

    // 先序便利拷贝
    BinaryNode* tree_node = (BinaryNode*) malloc(sizeof(BinaryNode));
    tree_node->ch = root->ch;
    tree_node->lchild = CopyBinaryTree(root->lchild);
    tree_node->rchild = CopyBinaryTree(root->rchild);

    return tree_node;
}

// 递归先序遍历
void Recursion_preorder(BinaryNode* root)
{
    // check NULL to exit recursion
    if (root == NULL)
    {
        return;
    }

    // 先序遍历
    printf("%c", root->ch);     // root
    Recursion_preorder(root->lchild);    // left child
    Recursion_preorder(root->rchild);    // right child
}

// 递归中序遍历
void Recursion_inorder(BinaryNode* root)
{
    // check NULL to exit recursion
    if (root == NULL)
    {
        return;
    }

    // 中序遍历
    Recursion_inorder(root->lchild);       // left child
    printf("%c", root->ch);                 // root
    Recursion_inorder(root->rchild);       // right child
}

// 递归后序遍历
void Recursion_postorder(BinaryNode* root)
{
    // check NULL to exit recursion
    if (root == NULL)
    {
        return;
    }

    // 后序遍历
    Recursion_postorder(root->lchild);    // left child
    Recursion_postorder(root->rchild);    // right child
    printf("%c", root->ch);     // root

}

// 获取叶子节点数目，即没有子节点的节点
void getLeafNum(BinaryNode* root, int &num)
{
    // check root null
    if (root == NULL) 
    {
        return;
    }

    // 如果当前节点没有子节点
    if (root->lchild == NULL &&
        root->rchild == NULL)
    {
        num++;
    }
    
    // 如果当前节点有子节点，看子节点是否是叶子
    getLeafNum(root->lchild, num);
    getLeafNum(root->rchild, num);
}

// 获取二叉树高度
void getTreeHeight(BinaryNode* root, int &height)
{
    // check root null
    if (root == NULL) 
    {
        return;
    }

    // 当前高度+1
    height++;

    // check left height
    int l_height = 0;
    getTreeHeight(root->lchild, l_height);


    // check right height
    int r_height = 0;
    getTreeHeight(root->rchild, r_height);

    if (l_height > r_height)
    {
        height += l_height;
    }
    else
    {
        height += r_height;
    }
}