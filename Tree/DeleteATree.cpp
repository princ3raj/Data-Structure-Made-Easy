

//created by princeraj

#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct Node
{

    int data;
    Node *lchild;
    Node *rchild;
} *root = NULL;

void CreateTree()
{

    Node *temp;
    queue<Node *> q;
    int data, lchild, rchild;
    cin >> data;
    root = new Node;
    root->data = data;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (!q.empty())
    {

        temp = q.front(), q.pop();
        cin >> lchild;
        if (lchild != -1)
        {

            Node *r = new Node;
            r->lchild = r->rchild = NULL;
            r->data = lchild;
            q.push(r);
            temp->lchild = r;
        }

        cin >> rchild;
        if (rchild != -1)
        {

            Node *r = new Node;
            r->lchild = r->rchild = NULL;
            r->data = rchild;
            q.push(r);
            temp->rchild = r;
        }
    }
}

void LevelOrder(Node *temp)
{

    queue<Node *> level_order_queue;
    if (temp != NULL)
        level_order_queue.push(temp);

    while (!level_order_queue.empty())
    {

        temp = level_order_queue.front(), level_order_queue.pop();
        cout << temp->data << " ";
        if (temp->lchild != NULL)
            level_order_queue.push(temp->lchild);
        if (temp->rchild != NULL)
            level_order_queue.push(temp->rchild);
    }
}

void DeleteATree(Node *temp)
{

    if (temp == NULL)
        return;
    DeleteATree(temp->lchild);
    DeleteATree(temp->rchild);
    free(temp);
}

int main()
{
    CreateTree();
    // LevelOrder(root);
    cout << endl;
    DeleteATree(root);
    root = NULL;
    LevelOrder(root);
}