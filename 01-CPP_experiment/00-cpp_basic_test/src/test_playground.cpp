#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 图节点定义
struct Node
{
    int data;                 // 数据
    vector<Node *> neighbors; // 邻居节点
};

// 广度优先搜索函数
void bfs(Node *start)
{
    // 创建一个队列
    queue<Node *> q;

    //
    vector<bool> visited(start->data + 1, false);

    q.push(start);
    visited[start->data] = true;

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        for (Node *neighbor : current->neighbors)
        {
            if (!visited[neighbor->data])
            {
                visited[neighbor->data] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    // 创建图节点
    Node *n1 = new Node{1};
    Node *n2 = new Node{2};
    Node *n3 = new Node{3};
    Node *n4 = new Node{4};
    Node *n5 = new Node{5};

    // 添加邻居关系
    n1->neighbors = {n2, n3, n4};
    n2->neighbors = {n1, n4, n5};
    n3->neighbors = {n1, n4, n5};
    n4->neighbors = {n1, n2, n3, n5};
    n5->neighbors = {n2, n3, n4};

    // 从节点1开始进行广度优先搜索
    bfs(n1);

    return 0;
}