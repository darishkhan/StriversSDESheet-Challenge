/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    Node* node1 = head;
    Node* node2 = head;
    if(head==NULL) return head;
    if(head->next==NULL) return head;
    while(true)
    {
        if(node2==NULL)
        {
            return node1;
        }
        else if(node2->next==NULL)
        {
            return node1;
        }
        node1=node1->next;
        node2=node2->next->next;
    }
}

