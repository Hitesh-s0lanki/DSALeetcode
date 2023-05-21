#include<iostream>
#include<vector>
#include<climits>
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
void print(TreeNode* root){
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->val<<"\t";
    print(root->right);
}


TreeNode* solve(vector<int>& preorder,int mini ,int maxi ,int &index){
    if( ( index >= preorder.size()) || (preorder[index] < mini || preorder[index] >maxi ) ){
        return NULL;
    }
    int element=preorder[index++];
    TreeNode* root=new TreeNode(element);

    root->left=solve(preorder,mini,element,index);
    root->right=solve(preorder,element,maxi,index);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int index=0;
    TreeNode* root=solve(preorder,mini,maxi,index);

    return root;
}

int main(){
    vector<int> preorder={8,5,1,7,10,12};
    TreeNode* root=bstFromPreorder(preorder);
    print(root);
}