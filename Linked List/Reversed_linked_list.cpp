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
    LinkedListNode<int> *node1 = head;
    if(head==NULL) return node1;
    if(head->next==NULL) return node1;
    LinkedListNode<int> *node2 = node1->next;
    if(node2->next==NULL)
    {
        node2->next=node1;
        node1->next=NULL;
        return node2;
    }
    LinkedListNode<int> *node3 = node2->next;
    while(node3!=NULL)
    {
        node2->next=node1;
        if(node1==head) node1->next=NULL;
        // else node1->next
        node1 = node2;
        node2 = node3;
        node3 = node3->next;//
        if(node3==NULL)
        {
            node2->next=node1;
            // node1->next=NULL;
            return node2;
        }
    }

}
