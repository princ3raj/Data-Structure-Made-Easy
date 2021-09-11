

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

int NoOfleaves(Node *temp)
{

    queue<Node *> q1;
    q1.push(temp);
    int count = 0;

    while (!q1.empty())
    {

        temp = q1.front(), q1.pop();
        if (temp->lchild == NULL && temp->rchild == NULL)
            count++;
        if (temp->lchild != NULL)
            q1.push(temp->lchild);
        if (temp->rchild != NULL)
            q1.push(temp->rchild);
    }
    return count;
}

int findNoOfFullNodes(Node *temp)
{

    queue<Node *> q1;
    q1.push(temp);
    int count = 0;

    while (!q1.empty())
    {

        temp = q1.front(), q1.pop();
        if (temp->lchild != NULL && temp->rchild != NULL)
            count++;
        if (temp->lchild != NULL)
            q1.push(temp->lchild);
        if (temp->rchild != NULL)
            q1.push(temp->rchild);
    }
    return count;
}

int main()
{
    CreateTree();
    cout << NoOfleaves(root) << endl;
    cout << findNoOfFullNodes(root) << endl;
}