#include<iostream>
#include<queue>
using namespace std;
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
BinaryTreeNode* buildTree(BinaryTreeNode* root){

    cout<<"Enter the data of root "<<endl;
    int data;
    cin>>data;
    
    root=new BinaryTreeNode(data);

    if(data==-1){
        return  NULL;
    }

    cout<<"enter the data of left node of "<<root->data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter the data of right node of "<<root->data<<endl;
    root->right=buildTree(root->right);

    return root;
}
void preOrderPrint(BinaryTreeNode* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<"\t";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
void counter(BinaryTreeNode *root,int &count){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        count++;
    }
    counter(root->left,count);
    counter(root->right,count);
}
int noOfLeafNodes(BinaryTreeNode *root){
    int n=0;
    counter(root,n);
    return n;
}
int main(){
    BinaryTreeNode* root=NULL;
    root=buildTree(root);
    preOrderPrint(root);
    cout<<endl;
    cout<<noOfLeafNodes(root);
}