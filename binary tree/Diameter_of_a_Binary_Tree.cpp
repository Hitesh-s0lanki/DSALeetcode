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
int height(TreeNode* root){
    
    if(root==NULL){
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);

    int ans=max(left,right)+1;

    return ans;
}
 int diameter(TreeNode* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        int opt1=diameter(root->left);
        int opt2=diameter(root->right);
        int opt3=height(root->left)+height(root->right)+1;

        int ans=max(opt1,max(opt2,opt3));

        return ans;
    }
int main(){
    //1 2 -1 -1 3 -1 -1 
    TreeNode* root=NULL;
    root=buildTree(root);
    preOrderPrint(root);
    cout<<endl;
    cout<<diameter(root);
}