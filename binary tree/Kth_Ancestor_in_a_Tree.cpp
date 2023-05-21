#include<iostream>
#include<climits>
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

Node* solve(Node* root,int &k,int node){
    //Base Condition
    if(root==NULL)
        return NULL;
    if(root->data==node){
        return root;
    }

    Node* leftAns=solve(root->left,k,node);
    Node* rightAns=solve(root->right,k,node);

    if(leftAns !=NULL && rightAns == NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns ==NULL && rightAns != NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node){
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node){
        return -1;
    }
    return ans->data;
}

int main(){
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    Node* root=buildTree(root);
    preOrder(root);
    cout<<endl;
    cout<<kthAncestor(root,2,4);
}