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
void leafArray(TreeNode* root,vector<int> & v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        v.push_back(root->val);
    }
    leafArray(root->left,v);
    leafArray(root->right,v);
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left;
        leafArray(root1,left);
         vector<int> right;
          leafArray(root2,right);

          return left==right;
    }
int main(){
    //1 2 -1 -1 3 -1 -1
    TreeNode* root=NULL;
    root=buildTree(root);
    // preOrderPrint(root);
    TreeNode* root2=NULL;
    root=buildTree(root2);
    // preOrderPrint(root2);
    cout<<leafSimilar(root,root2);
}