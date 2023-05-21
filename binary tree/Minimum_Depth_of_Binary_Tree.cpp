#include<iostream>
#include<algorithm>
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
int minDepth(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }

        int left=minDepth(root->left);
        int right=minDepth(root->right);

        int ans=min(left,right)+1;

        return ans;
    }
int main(){
    //3,9,20,null,null,15,7
    // 3  9 -1 -1 20 15 -1 -1 7 -1 -1
    TreeNode* root=NULL;
    root=buildTree(root);
    preOrderPrint(root);
    cout<<endl;
    cout<<minDepth(root);
}