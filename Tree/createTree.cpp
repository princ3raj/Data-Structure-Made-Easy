#include <iostream>
#include <queue>
#include <stack>
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

void Preorder(Node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

void Postorder(Node *temp)
{
    if (temp != NULL)
    {

        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout << temp->data << " ";
    }
}

void Inorder(Node *temp)
{

    if (temp != NULL)
    {
        Inorder(temp->lchild);
        cout << temp->data << " ";
        Inorder(temp->rchild);
    }
}

void IterativePreorder()
{

    Node *temp;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {

        temp = s.top(), s.pop();
        if (temp != NULL)
        {

            cout << temp->data << " ";
            if (temp->rchild != NULL)
                s.push(temp->rchild);
            if (temp->lchild != NULL)
                s.push(temp->lchild);
        }
    }
}

void IterativePostorder()
{
    int flag1 = 0;
    stack<Node *> lstack, rstack;
    rstack.push(root);
    Node *temp;
    while (!flag1)
    {

        temp = rstack.top();
        if (temp != NULL)
        {

            if (temp->lchild != NULL)
                lstack.push(temp->lchild);
            rstack.push(temp->rchild);
        }
        else
        {
            rstack.pop();
            flag1 = 1;
        }
    }

    while (!lstack.empty())
    {

        temp = lstack.top(), lstack.pop(), rstack.push(temp);
        if (temp->lchild != NULL)
            lstack.push(temp->lchild);
        if (temp->rchild != NULL)
            lstack.push(temp->rchild);
    }

    while (!rstack.empty())
    {
        temp = rstack.top(), rstack.pop();
        cout << temp->data << " ";
    }
}

void IterativeInorder()
{
    int flag = 0;
    Node *temp;
    stack<Node *> lstack, rstack;
    lstack.push(root->lchild);
    rstack.push(root->rchild);
    while (!flag)
    {

        temp = lstack.top();
        if (temp != NULL)
        {

            if (temp->rchild != NULL)
                rstack.push(temp->rchild);
            lstack.push(temp->lchild);
        }
        else
        {
            flag = 1;
            lstack.pop();
        }
    }

    while (!rstack.empty())
    {

        temp = rstack.top(), rstack.pop(), lstack.push(temp);
        if (temp->lchild != NULL)
            rstack.push(temp->lchild);
        if (temp->rchild != NULL)
            rstack.push(temp->rchild);
    }

    while (!lstack.empty())
    {
        temp = lstack.top(), lstack.pop(), rstack.push(temp);
    }

    while (!rstack.empty())
    {
        temp = rstack.top(), rstack.pop();
        cout << temp->data << " ";
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

int main()
{

    CreateTree();
    cout << "Preorder : ";
    Preorder(root);
    cout << endl;

    cout << "Postorder: ";
    Postorder(root);
    cout << endl;

    cout << "Inorder: ";
    Inorder(root);
    cout << endl;

    cout << "IterativePreorder: ";
    IterativePreorder();
    cout << endl;

    cout << "Iterative Postorder: ";
    IterativePostorder();
    cout << endl;

    cout << "Iterative Inorder:";
    IterativeInorder();
    cout << endl;

    cout << "Iterative Level Order" << endl;
    LevelOrder(root);
    cout << endl;
}