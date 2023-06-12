/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* ans;
    Node* curr;
    int number=0, flag=1;
    while(num1 and num2)
    {
        number += num1->data+num2->data;
        Node *thisnode = new Node(0);    
        if(!flag)  curr->next = thisnode;
        if(number<10) thisnode->data = number;
        else thisnode->data = number%10;
        number=number/10;
        curr = thisnode;
        if(flag)
        {
            ans = thisnode;
            flag=0;
        }
        num1=num1->next;num2=num2->next;
        if(num1==NULL and num2==NULL)
        {
            if(number>0)
            {
                Node *thatnode = new Node(0);
                curr->next = thatnode;
                if(number<10) thatnode->data = number;
                else thatnode->data = number%10;
                number=number/10;
            }
        }
        else if(num1==NULL)
        {
            while(num2)
            {
                number += num2->data;
                Node *thatnode = new Node(0);
                if(!flag)  curr->next = thatnode;
                if(number<10) thatnode->data = number;
                else thatnode->data = number%10;
                number=number/10;
                curr = thatnode;  
                num2=num2->next;     
            }
        }
        else if(num2==NULL)
        {
            while(num1)
            {
                number += num1->data;
                Node *thatnode = new Node(0);
                if(!flag)  curr->next = thatnode;
                if(number<10) thatnode->data = number;
                else thatnode->data = number%10;
                number=number/10;
                curr = thatnode;
                num1=num1->next;
            }
        }
    }
    
    return ans;
}
