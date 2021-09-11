
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

    int lchild, rchild, rooot;
    queue<Node *> q;
    Node *temp;
    cin >> rooot;
    root = new Node;
    root->lchild = root->rchild = NULL;
    root->data = rooot;
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

void PreOrder(Node *temp)
{

    if (temp != NULL)
    {
        cout << temp->data << " ";
        PreOrder(temp->lchild);
        PreOrder(temp->rchild);
    }
}

void InsertInBinary(Node *temp, int key)
{

    queue<Node *> q;
    q.push(temp);

    while (!q.empty())
    {

        temp = q.front(), q.pop();
        if (temp->lchild == NULL)
        {
            Node *r = new Node;
            r->data = key;
            r->lchild = r->rchild = NULL;
            temp->lchild = r;
            break;
        }
        else
        {
            q.push(temp->lchild);
        }

        if (temp->rchild == NULL)
        {
            Node *r = new Node;
            r->data = key;
            r->lchild = r->rchild = NULL;
            temp->rchild = r;
            break;
        }
        else
        {
            q.push(temp->rchild);
        }
    }
}
int main()
{
    CreateTree();
    PreOrder(root);
    cout << endl;
    InsertInBinary(root, 19);
    InsertInBinary(root, 1);
    // InsertInBinary(root, 100);
    // InsertInBinary(root, 56);
    // InsertInBinary(root, 134);
    cout << "after insertion:" << endl;
    PreOrder(root);
}