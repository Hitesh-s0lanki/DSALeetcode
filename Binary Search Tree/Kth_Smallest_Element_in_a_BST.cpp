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

void solve(TreeNode* root,int &k,int &ans){
    if(root==NULL){
        return;
    }
    solve(root->left,k,ans);
    k--;
    if(k==0){
        ans=root->val;
    }
    solve(root->right,k,ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans=0;
    solve(root,k,ans);

    return ans;        
}

int main(){
    // 3 4 1 2 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
    cout<<endl;
    cout<<kthSmallest(root,1);
}