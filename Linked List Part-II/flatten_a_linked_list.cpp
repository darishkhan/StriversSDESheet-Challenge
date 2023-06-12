/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head->next==NULL) return head;
	// Node* curr = head;
	Node* curr2 = head->next;
	while(curr2)
	{
		Node* curr = head;
		Node* curr3 = curr2;
		curr2=curr2->next;
		while(curr and curr3)
		{
			curr->next=NULL;
			curr3->next=NULL;
			if(curr->data<=curr3->data and curr->child==NULL)
			{
				curr->child=curr3;break;
			}
			else if(curr->data<=curr3->data and curr->child->data>=curr3->data)
			{
				Node* curr4 = curr->child;
				curr->child = curr3;
				curr3=curr3->child;
				curr->child->child=curr4;
				curr=curr->child;
			}
			else if(curr3->data<=curr->data)
			{
				Node* curr4 = curr;
				curr=curr3;
				curr3=curr3->child;
				curr->child=curr4;
				if(curr4==head) head=curr;
			}
			else{
				curr=curr->child;
			}
		}
	}
	head->next=NULL;
	return head;
}
