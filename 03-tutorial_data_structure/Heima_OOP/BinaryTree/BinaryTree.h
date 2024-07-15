//
// Created by wenhan on 2021/1/28.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

// 二叉树 叶节点
typedef struct BINARYNODE
{
    char ch;
    struct BINARYNODE *lchild;
    struct BINARYNODE *rchild;
} BinaryNode;

// 二叉树栈节点
typedef struct BITREESTACKNODE
{
    BinaryNode *root;
    bool flag;
} BiTreeStackNode;

// 二叉树类
class BinaryTree
{
private:
    // 根节点
    BinaryNode *root;

public:
    BinaryTree();
    ~BinaryTree();

    // 创建 无参
    void createBinaryTree();

    // 创建 有参
    void createBinaryTree(char *nodeSeq, size_t num);

    // 先序遍历递归实现
    void recursion();

    // 先序遍历非递归实现，借助STL中的stack实现
    void nonRecursion();

    // 计算叶子结点数目
    void calculateLeafNum();

    // 计算二叉树的高度，对应视频无法观看，自己实现
    void calculateTreeHeight();

    // 序列化
    std::string serializeTree();

    // 反序列化
    void deserializeTree(const std::string &treeSeq);

    // 重载赋值运算符，实现拷贝
    BinaryTree &operator=(const BinaryTree &tree);

private: // 静态方法
    // 静态 // 先序遍历递归实现
    static void _recursion(BinaryNode *currentRoot);

    // 静态 清空
    static void _freeBinaryTree(BinaryNode *currentRoot);

    // 静态 计算叶子结点数目
    static void _calculateLeafNum(BinaryNode *currentRoot, int &num);

    // 静态 计算高度
    static void _calculateTreeHeight(BinaryNode *currentRoot, int &height);

    // 静态 拷贝 方式1, 繁琐
    static void _copyBinaryTree(BinaryNode *currentRoot, BinaryNode **copyRoot);

    // 静态 拷贝 方式2 简洁
    static BinaryNode *_copyBinaryTree(BinaryNode *currentRoot);

    // 静态 创建
    static BinaryNode *_createBinaryTree(const char *nodeSeq, size_t num, int &pos);

    // 静态 序列化
    static std::string _serializeTree(BinaryNode *currentRoot);

    // 静态 反序列化
    static BinaryNode *_deserializeTree(const std::string &treeSeq, int &pos);
};

#endif // BINARYTREE_BINARYTREE_H
