#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{

    cout << "enter the data for root node" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data in left node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data in Right node of " << data << endl;
    root->right = buildTree(root->right);
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "\t";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void fillStack(stack<node *> &s,node* root){
    if(root==NULL){
        return ;
    }
    s.push(root);
    s.push(NULL);
    fillStack(s,root->left);
    fillStack(s,root->right);
}
void reverseLevelOrderTraversal(node *root)
{
    stack<node *> s;
    fillStack(s,root);
    while(!s.empty()){
        if(s.top()==NULL){
            cout<<endl;
            s.pop();
        }
        cout<<s.top()->data<<"\t";
        s.pop();
    }
}
void preOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"\t";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<"\t";
    inOrderTraversal(root->right);
}
void postOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<"\t";
}
void buildFromLevelOrder(node* &root){

    queue<node*> q;

    cout<<"enter the data of root  node"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        int leftData;
        cout<<"enter the data of left Node of "<<temp->data<<endl;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        int rightData;
        cout<<"enter the data of right Node of "<<temp->data<<endl;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }



}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // node *root = NULL;
    // root = buildTree(root);
    // levelOrderTraversal(root);
    // // reverseLevelOrderTraversal(root);
    // cout<<"Preorder traversal : ";
    // preOrderTraversal(root);
    // cout<<endl;
    // cout<<"Inorder traversal : ";
    // inOrderTraversal(root);
    // cout<<endl;
    // cout<<"Postorder traversal : ";
    // postOrderTraversal(root);
    // cout<<endl;

    node* root=NULL;
    buildFromLevelOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
}