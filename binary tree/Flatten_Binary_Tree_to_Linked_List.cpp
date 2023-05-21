#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val){
        this->val=val;
        this->right=NULL;
        this->left=NULL;
    }
};
TreeNode* buildTree(TreeNode* root){
    cout<<"Enter the data of root node"<<endl;
    int data;
    cin>>data;

    root=new TreeNode(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data in left of "<<root->val<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data in right of "<<root->val<<endl;
    root->right=buildTree(root->right);

    return root;
}
void preOrderPrint(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<"\t";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
void postOrderPrint(TreeNode* root){
    if(root==NULL){
        return;
    }
    preOrderPrint(root->left);
    preOrderPrint(root->right);
    cout<<root->val<<"\t";
}
void insertAtTail(TreeNode* &head,TreeNode* &tail,int d){
    TreeNode* temp=new TreeNode(d);
    if(head==NULL){
        head=temp;
        tail=temp;
        return ;
    }
    tail->right=temp;
    tail=temp;
}
void flattenFast(TreeNode* &head,TreeNode* &tail,TreeNode* root){
    if(root==NULL){
        return;
    }
    insertAtTail(head,tail,root->val);
    flattenFast(head,tail,root->left);
    flattenFast(head,tail,root->right);
}
void flatten(TreeNode* root) {
        TreeNode* head=NULL;
        TreeNode* tail=NULL;
        flattenFast(head,tail,root);
        root=head;
    }

int main(){
    TreeNode* root=buildTree(root);
    //1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
    preOrderPrint(root);
    cout<<endl;
    postOrderPrint(root);
    flatten(root);
    cout<<endl;
}