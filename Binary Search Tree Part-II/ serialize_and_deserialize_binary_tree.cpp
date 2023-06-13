/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *head;
queue<TreeNode<int> *> q;
void dfss(queue<TreeNode<int>*> &q, string &order)
{
    while(!q.empty())
    {
        TreeNode<int> *root = q.front();
        q.pop();
        if(root->left) 
        {
            order+=(to_string(root->left->data)+',');
            q.push(root->left);
        }
        else order+="#,";
        if(root->right)
        {
            order+=(to_string(root->right->data)+',');
            q.push(root->right);
        }
        else order+="#,";
    }
}
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string order="";
    if(root==NULL) return "";
    q.push(root);
    order+=to_string(root->data)+',';
    dfss(q, order);
    return order;
}
int stringtoint(string &s)
{
    if(s=="#") return -1;
    int i=0, n=0;
    while(i<s.size())
    {
        n=10*n+int(s[i])-48;
        i++;
    }
    return n;
}
queue<TreeNode<int>*> p;
void *dfs(vector<int> &order, int &k)
{
    while(!p.empty())
    {
        TreeNode<int>* curr = p.front();
        p.pop();
        TreeNode<int>* node= NULL;
        if(order[k]==-1) curr->left=NULL;
        else
        {
            TreeNode<int>* node= new TreeNode<int>(order[k]);
            curr->left=node;
            p.push(node);
        }
        k++;
        if(order[k]==-1) curr->right=NULL;
        else
        {
            TreeNode<int> *node = new TreeNode<int>(order[k]);
            curr->right=node;
            p.push(node);
        }
        k++;
    }    
}
TreeNode<int>* deserializeTree(string &serialized)
{
    // Write your code here for deserializing the tree
    if(serialized=="") return NULL;
    int i=0;
    vector<int> order;
    string temp="";
    // cout<<serialized;
    i=0;

    while(i<serialized.size())
    {
        if(serialized[i]==',') 
        {
            order.push_back(stringtoint(temp));
            temp="";
        }  
        else temp+=serialized[i];
        i++;
    }

    // for(int i=0;i<order.size();i++)
    // {
    //     cout<<order[i]<<" ";
    // }
    int k=0;
    TreeNode<int> *g = new TreeNode<int>(order[k]);
    k++;
    p.push(g);
    dfs(order, k);
    return g;
    // return NULL;
}



