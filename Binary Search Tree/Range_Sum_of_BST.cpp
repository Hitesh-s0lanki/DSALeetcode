#include<iostream>
#include<vector>
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
TreeNode* insertInBST(TreeNode* root,int d){
    //Base case 
    if(root==NULL){
        root=new TreeNode(d);
        return root;
    }
    else if(root->val > d ){
        root->left=insertInBST(root->left,d);
    }
    else{
        root->right=insertInBST(root->right,d);
    }
        return root;
}

TreeNode* buildBST(TreeNode* root){
    int data;
    cin>>data;

    while(data != -1){
        root=insertInBST(root,data);
        cin>>data;
    }
    return root;
}

void solve(TreeNode* root, int low, int high,int &ans){
    if(root==NULL)
        return;
    if(root->val >=low && root->val <=high){
        ans+=root->val;
    }
    if(root->val < high){
        solve(root->right,low,high,ans);
    }
    if(root->val > low){
        solve(root->left,low,high,ans);
    }
}

int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        solve(root,low,high,ans);
        return ans;
}

int main(){
    // 10 5 7 3 15 18 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
    cout<<endl;
    cout<<rangeSumBST(root,7,15);
}