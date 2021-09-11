

//created by princeraj

//still some fixes to be done

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
    Node *lchild;
    int data;
    Node *rchild;
};
Node *root;
queue<Node *> q;

void CreateTree()
{

    Node *temp, *r;
    root = new Node;
    int i;
    cin >> i;
    root->lchild = root->rchild = NULL;
    root->data = i;
    q.push(root);
    while (!q.empty())
    {

        temp = q.front(), q.pop();
        int input;
        cin >> input;
        if (input != -1)
        {

            r = new Node;
            r->lchild = r->rchild = NULL;
            r->data = input;
            temp->lchild = r;
            q.push(r);
        }

        cin >> input;
        if (input != -1)
        {
            r = new Node;
            r->lchild = r->rchild = NULL;
            r->data = input;
            temp->rchild = r;
            q.push(r);
        }
    }
}

void LevelOrder(Node *temp)
{

    queue<Node *> level_order_queue;
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

Node *FindKey(Node *temp, int key)
{

    queue<Node *> q1;
    q1.push(temp);
    while (!q1.empty())
    {

        temp = q1.front(), q1.pop();
        if (temp->data == key)
            return temp;
        if (temp->lchild != NULL)
            q1.push(temp->lchild);
        if (temp->rchild != NULL)
            q1.push(temp->rchild);
    }
    return NULL;
}

Node *deepestNode(Node *temp)
{
    Node *deepNode;
    queue<Node *> q2;
    q2.push(temp);
    while (!q2.empty())
    {
        temp = q2.front(), q2.pop();
        if (temp->lchild != NULL)
            q2.push(temp->lchild);
        if (temp->rchild != NULL)
            q2.push(temp->rchild);
        if (temp->lchild == NULL && temp->rchild == NULL)
            deepNode = temp;
    }

    return deepNode;
}

void DeleteAnElement(Node *temp, int data)
{

    Node *t = FindKey(temp, data);

    Node *deepNode = deepestNode(temp);
    t->data = deepNode->data;
    deepNode->data = 0;
    delete deepNode;
}

int main()
{

    CreateTree();
    LevelOrder(root);
    cout << endl;
    DeleteAnElement(root, 6);
}