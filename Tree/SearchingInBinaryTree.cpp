

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

int SearchRecursion(Node *temp, int key)
{
    int t;

    if (temp == NULL)
        return 0;
    else
    {
        if (temp->data == key)
            return 1;
        else
        {
            t = SearchRecursion(temp->lchild, key);
            if (t != 0)
                return t;
            else
                return SearchRecursion(temp->rchild, key);
        }
    }
    return 0;
}

Node *Search(Node *temp, int key)
{

    queue<Node *> q;
    q.push(temp);

    while (!q.empty())
    {

        temp = q.front(), q.pop();
        if (temp != NULL)
            if (temp->data == key)
                return temp;
        if (temp->lchild != NULL)
            q.push(temp->lchild);
        if (temp->rchild != NULL)
            q.push(temp->rchild);
    }
    return NULL;
}

int main()
{
    CreateTree();
    // PreOrder(root);

    int key;
    cin >> key;

    // if (Search(root, key) != NULL)
    // {
    //     cout << "Element is at this address" << Search(root, key) << endl;
    // }
    // else
    // {
    //     cout << "Not Found" << endl;
    // }

    if (SearchRecursion(root, key))
    {
        cout << "Found" << endl;
    }
    else
        cout << "Not Found" << endl;
}