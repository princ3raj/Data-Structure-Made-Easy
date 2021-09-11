#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    Node *rchild;
    int data;
    Node *lchild;

} *root = NULL;

void CreateTree()
{
    int lchild, rchild;
    Node *temp;
    queue<Node *> q;
    root = new Node;
    int data;
    cin >> data;
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
            q.push(r);
            temp->lchild = r;
        }

        cin >> rchild;
        if (rchild != -1)
        {
            Node *r = new Node;
            r->data = rchild;
            r->lchild = r->rchild = NULL;
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

int MaxElementInBinaryTreeRecursive(Node *temp)

{
    int max, left, right, rut = INT_MIN;

    if (temp == NULL)
        return 0;
    else
    {
        rut = temp->data;
        left = MaxElementInBinaryTreeRecursive(temp->lchild);
        right = MaxElementInBinaryTreeRecursive(temp->rchild);
        if (left > right)
            max = left;
        else
            max = right;

        if (rut > max)
            max = rut;
    }

    return max;
}

void NonRecursive(Node *temp)
{
    int max = 0;
    queue<Node *> q;
    q.push(temp);

    while (!q.empty())
    {

        temp = q.front(), q.pop();

        if (temp->lchild != NULL)
            q.push(temp->lchild);
        if (temp->rchild != NULL)
            q.push(temp->rchild);
        if (temp != NULL)
            if (temp->data > max)
                max = temp->data;
    }

    cout << max << endl;
}

int main()
{

    CreateTree();
    cout << MaxElementInBinaryTreeRecursive(root);

    // cout << "Non-Recursive: ";
    // NonRecursive(root);
}