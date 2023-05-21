#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
TreeNode* buildTree(TreeNode* root){
    
    cout<<"enter the root node "<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);

    if(data==-1){
        return NULL;
    }

    cout<<"enter the data in left node of "<<root->val<<endl;
    root->left=buildTree(root->left);

    cout<<"enter the data in right node of "<<root->val<<endl;
    root->right=buildTree(root->right);

    return root;
}
void preOrderPrint(TreeNode* root){
    if(root==NULL){
        return ;
    }

    cout<<root->val<<"\t";
    preOrderPrint(root->left);
    preOrderPrint(root->right);

}
void getPreOrderDataLeft(TreeNode* root,vector<int> &left){
    if(root==NULL){
        return;
    }
    getPreOrderDataLeft(root->right,left);
    left.push_back(root->val);
    getPreOrderDataLeft(root->left,left);

}
void getPreOrderDataRight(TreeNode* root,vector<int> &left){
    if(root==NULL){
        return;
    }
    getPreOrderDataRight(root->left,left);
    left.push_back(root->val);
    getPreOrderDataRight(root->right,left);

}
void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\t";
    }
    cout<<endl;
}
 bool isSymmetric(TreeNode* root) {
        vector<int> left;
        getPreOrderDataLeft(root->left,left);
        vector<int> right;
        getPreOrderDataRight(root->right,right);
        print(left);
        print(right);
        return left==right;
    }
int main(){
    //1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1
    //1 2 -1 3 -1 -1 2 -1 3 -1 -1
    TreeNode* root=NULL;
    root=buildTree(root);
    preOrderPrint(root);
    cout<<endl;
    cout<<isSymmetric(root);
}