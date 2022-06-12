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

LinkedListNode<int> * reverse(LinkedListNode<int> * head)
{
    if(!head || !head -> next)
        return head;
    LinkedListNode<int> *p1 = head, *p2 = head -> next, *p3 = head -> next -> next;
    p1 -> next = NULL;
    while(p2)
    {
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
        if(p3)
            p3 = p3 -> next;
    }
    return p1;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(!head || !head -> next)
        return true;
    
    LinkedListNode<int> * slow = head, * fast = head;
    while(fast -> next && fast -> next -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    fast = reverse(slow -> next);
    slow = head;
    while(fast)
    {
        if(slow -> data != fast -> data)
            return false;
        
        slow = slow -> next;
        fast = fast -> next;
    }
    return true;
        
}
