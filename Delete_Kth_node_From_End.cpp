#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(!head || !K)
        return head;
    LinkedListNode<int>* temp(head);
    int count = 0;
    while(temp)
    {
        count++;
        temp = temp -> next;
    }
    count -= K;
    temp = head;
    if(!count)
    {
        temp = temp -> next;
        delete head;
        head = NULL;
        return temp;
    }
    while(--count)
    {
        temp = temp -> next;
    }
    LinkedListNode<int>* t2 = temp -> next -> next;
    delete temp -> next;
    temp -> next = t2;
    return head;
}
