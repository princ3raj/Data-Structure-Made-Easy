

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
} *root = NULL;

void CreateTree()
{
    Node *temp;
    int lchild, rchild;
    queue<Node *> q;
    int data;
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
            r->data = lchild;
            r->lchild = r->rchild = NULL;
            temp->lchild = r;
            q.push(r);
        }

        cin >> rchild;
        if (rchild != -1)
        {
            Node *r = new Node;
            r->data = rchild;
            r->lchild = r->rchild = NULL;
            temp->rchild = r;
            q.push(r);
        }
    }
}

int RSize(Node *temp)
{

    if (temp == NULL)
        return 0;
    else
        return RSize(temp->lchild) + 1 + RSize(temp->rchild);
}

int Size(Node *temp)
{

    int count = 0;
    queue<Node *> q;
    q.push(temp);
    while (!q.empty())
    {

        temp = q.front(), q.pop();
        if (temp->lchild != NULL)
            q.push(temp->lchild);
        if (temp->rchild != NULL)
            q.push(temp->rchild);
        count++;
    }
    return count;
}

int main()
{
    CreateTree();
    cout << Size(root) << endl;
    cout << RSize(root) << endl;
}