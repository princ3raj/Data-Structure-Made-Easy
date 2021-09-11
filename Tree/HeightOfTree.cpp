

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

int RHeight(Node *temp)
{

    int leftHeight, rightHeight;

    if (temp == NULL)
        return -1;
    else
    {

        leftHeight = RHeight(temp->lchild);
        rightHeight = RHeight(temp->rchild);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

int deepestNode(Node *temp)
{
    Node *deepNode;
    queue<Node *> q;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front(), q.pop();
        if (temp->lchild != NULL)
            q.push(temp->lchild);
        if (temp->rchild != NULL)
            q.push(temp->rchild);
        if (temp->lchild == NULL && temp->rchild == NULL)
            deepNode = temp;
    }

    return deepNode->data;
}

int main()
{

    CreateTree();

    // cout << RHeight(root) << endl;
    cout << deepestNode(root) << endl;
}