#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void preOrder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<"\t";
    preOrder(root->left);
    preOrder(root->right);
}
Node* buildTree(Node* root){
    cout<<"Enter the data of root Node"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the Data in left of "<<root->data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the Data in right of "<<root->data<<endl;
    root->right=buildTree(root->right);

    return root;
}

Node* lca(Node* root ,int n1 ,int n2 ){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftAns=lca(root->left,n1,n2);
    Node* rightAns=lca(root->right,n1,n2);

    if(leftAns != NULL &&rightAns != NULL)
        return root;
    else if(leftAns !=NULL &&rightAns ==NULL){
        return leftAns;
    }
    else if(leftAns ==NULL && rightAns !=NULL){
        return rightAns;
    }
}
int main(){
    // 5 2 3 -1 -1 4 -1 -1 -1
    Node* root=buildTree(root);
    preOrder(root);
    cout<<endl;
    Node* ans=lca(root,3,4);
    cout<<ans->data;
}
    //        5    
    //       /    
    //      2  
    //     / \  
    //    3   4