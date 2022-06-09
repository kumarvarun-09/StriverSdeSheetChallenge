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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    LinkedListNode<int> * p1 = head, *p2 = head -> next, *p3 = head -> next -> next;
    p1 -> next = NULL;
    while(p2 != NULL)
    {
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
        if(p3 != NULL)
            p3 = p3->next;
    }
    return p1;
}
