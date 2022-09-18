#include "BinaryTree.h"

void test_binary_tree()
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

    // 递归先序遍历
    Recursion_preorder(&node1);
    printf("\n");

    // 递归中序遍历
    Recursion_inorder(&node1);
    printf("\n");

    // 递归后序遍历
    Recursion_postorder(&node1);
    printf("\n");

    // 获取叶子节点的数目
    int leaf_num = 0;
    getLeafNum(&node1, leaf_num);
    printf("leaf num: %d\n", leaf_num);

    // 获取二叉树高度
    int tree_height = 0;
    getTreeHeight(&node1, tree_height);
    printf("tree_height: %d\n", tree_height);

    // 拷贝二叉树
    BinaryNode* new_tree = CopyBinaryTree(&node1);
    Recursion_preorder(new_tree);
    printf("\n");

    // 释放空间
    printf("new tree\n");
    FreeSpaceBinaryTree(new_tree);

    printf("old tree\n");
    // FreeSpaceBinaryTree(node1); // 这里不需要释放空间吗？

}


/**
 * @brief main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    test_binary_tree();

    return 0;
}