

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

struct Node1
{
    Node1 *lchild;
    int data;
    Node1 *rchild;
};
Node1 *root1;
queue<Node1 *> q1;

void CreateTreeTwo()
{

    Node1 *temp, *r;
    root1 = new Node1;
    int i;
    cin >> i;
    root1->lchild = root1->rchild = NULL;
    root1->data = i;
    q1.push(root1);
    while (!q1.empty())
    {

        temp = q1.front(), q1.pop();
        int input;
        cin >> input;
        if (input != -1)
        {

            r = new Node1;
            r->lchild = r->rchild = NULL;
            r->data = input;
            temp->lchild = r;
            q1.push(r);
        }

        cin >> input;
        if (input != -1)
        {
            r = new Node1;
            r->lchild = r->rchild = NULL;
            r->data = input;
            temp->rchild = r;
            q1.push(r);
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

void LevelOrder1(Node1 *temp)
{

    queue<Node1 *> level_order_queue;
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

int IdenticalStructure(Node *temp1, Node1 *temp2)
{
    int one, two;
    one = two = 0;
    queue<Node *> tq1;
    queue<Node1 *> tq2;
    tq1.push(temp1);
    tq2.push(temp2);
    while (!(tq1.empty() && tq2.empty()))
    {
        temp1 = tq1.front(), tq1.pop();
        temp2 = tq2.front(), tq2.pop();

        if (one == two)
        {

            if (temp1->lchild != NULL)
            {
                tq1.push(temp1->lchild);
                one++;
            }

            if (temp1->rchild != NULL)
            {
                tq1.push(temp1->rchild);
                one++;
            }

            if (temp2->lchild != NULL)
            {
                tq2.push(temp2->lchild);
                two++;
            }

            if (temp2->rchild != NULL)
            {
                tq2.push(temp2->rchild);
                two++;
            }
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    CreateTree();
    CreateTreeTwo();
    LevelOrder(root);
    cout << endl;
    LevelOrder1(root1);
    cout << endl;
    if (IdenticalStructure(root, root1))
    {

        cout << "Identical" << endl;
    }
    else
        cout << "Not Identical" << endl;
}