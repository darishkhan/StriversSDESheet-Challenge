/****************************************************************

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

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    vector<Node*> v1, v2;
    while(firstHead)
    {
        v1.push_back(firstHead);
        firstHead=firstHead->next;
    }
    while(secondHead)
    {
        v2.push_back(secondHead);
        secondHead=secondHead->next;
    }
    int i=v1.size()-1, j = v2.size()-1;
    Node* ans=NULL;
    while(true)
    {
        // cout<<v1[i]->data<<" "<<v2[j]->data;
        if(i<0 or j<0) return ans;
        if(v1[i]!=v2[j])
        {
            if(i!=v1.size()-1 and j!=v2.size()-1) return ans = v1[i+1];
            else return ans;
        }
        i--;j--;
    }
    return ans=v1[i+1];
}
