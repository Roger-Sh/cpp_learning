#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_set>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

void get_tree_sum(TreeNode *node, int &temp_sum, int &total_sum)
{
    // check nullptr
    if (node == nullptr)
    {
        return;
    }

    temp_sum *= 10;
    temp_sum += node->val;

    // 末端叶子, 加入总和后, 将sum恢复到上一个状态
    if (node->left == nullptr && node->right == nullptr)
    {
        std::cout << "temp_sum: " << temp_sum << std::endl;
        total_sum += temp_sum;
    }
    else
    {
        get_tree_sum(node->left, temp_sum, total_sum);
        get_tree_sum(node->right, temp_sum, total_sum);
    }

    // 当前节点跑完后, 将sum恢复到上一个状态
    temp_sum -= node->val;
    temp_sum /= 10;
}

int main()
{
    TreeNode *node_1 = new TreeNode(1);
    TreeNode *node_2 = new TreeNode(3);
    TreeNode *node_3 = new TreeNode(5);
    TreeNode *node_4 = new TreeNode(4);
    TreeNode *node_5 = new TreeNode(2);
    TreeNode *node_6 = new TreeNode(9);
    node_1->left = node_2;
    node_1->right = node_3;
    node_2->left = node_4;
    node_2->right = node_5;
    node_3->left = node_6;

    int sum = 0;
    int total_sum = 0;
    get_tree_sum(node_1, sum, total_sum);

    std::cout << "total sum: " << total_sum << std::endl;

    return 0;
}