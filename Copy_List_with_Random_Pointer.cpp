#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(!head)
        return head;
    
    LinkedListNode<int> * tempHead = head;
    while(tempHead)
    {
        //inserting clone nodes
        LinkedListNode<int> *tempNext = tempHead -> next;
        tempHead -> next = new LinkedListNode<int>(tempHead -> data);
        tempHead = tempHead -> next -> next = tempNext;
    }
    tempHead = head;
    while(tempHead)
    {
        //assigning random pointers
        tempHead -> next -> random = (tempHead -> random) ? tempHead -> random -> next : NULL;
        tempHead = tempHead -> next -> next;
    }
    tempHead = head;
    LinkedListNode<int> *clone = head -> next, *cloneTemp = clone;
    while(tempHead)
    {
        //breaking connections and separating lists 
        tempHead -> next = tempHead -> next -> next;
        cloneTemp -> next = (cloneTemp -> next) ? cloneTemp -> next -> next : NULL;
        
        tempHead = tempHead -> next;
        cloneTemp = cloneTemp -> next;
    }
    return clone;
}
