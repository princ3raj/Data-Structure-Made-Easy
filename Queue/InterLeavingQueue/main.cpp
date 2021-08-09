//
//  main.cpp
//  InterLeavingQueue
//
//  Created by princeraj on 09/08/21.
//

/*
 
 Problem-10  Given a queue of integers, rearrange the elements by interleaving the first half of the list with the second half of the list. For example, suppose a queue stores the following sequence of values: [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]. Consider the two halves of this list: first half: [11, 12, 13, 14, 15] second half: [16, 17, 18, 19, 20]. These are
  
 combined in an alternating fashion to form a sequence of interleave pairs: the first values from each half (11 and 16), then the second values from each half (12 and 17), then the third values from each half (13 and 18), and so on. In each pair, the value from the first half appears before the value from the second half. Thus, after the call, the queue stores the following values: [11, 16, 12, 17, 13, 18, 14, 19, 15, 20].
 */

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> q;
stack<int> st1, st2;

void insertElementInQueue(int n)
{

    for (int i = 11; i <= n; i++)
        q.push(i);
}

void moveQueueElementsToStackAndThenToQueue()
{
    int temp1, temp2;
    int size = q.size() / 2;

    for (int i = 0; i < size; i++)
        st1.push(q.front()), q.pop();

    for (int i = 0; i < size; i++)
        st2.push(q.front()), q.pop();

    while (!st1.empty() || !st2.empty())
        q.push(st1.top()), q.push(st2.top()), st1.pop(), st2.pop();

    while (!q.empty())
        st1.push(q.front()), q.pop();

    while (!st1.empty())
        temp1 = st1.top(), st1.pop(), temp2 = st1.top(), st1.pop(), q.push(temp2), q.push(temp1);

    while (!q.empty())
    {
        cout << q.front() << " ", q.pop();
    }
}

void interLeavingQueues()
{
    moveQueueElementsToStackAndThenToQueue();
}

int main()
{
    insertElementInQueue(20);
    interLeavingQueues();

    return 0;
}
