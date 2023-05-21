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

bool solve(TreeNode* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->val < min || root->val > max){
        return false;
    }
    bool left=solve(root->left,min,root->val);

    bool right=solve(root->right,root->val,max);

    return left==true && right ==true;
}

bool validateBST(TreeNode *root) {
    int min=INT_MIN;
    int max=INT_MAX;
    return solve(root,min,max);
}



int main(){
    // 10 8 21 7 27 5 4 3 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
    cout<<endl;
    cout<<validateBST(root);
}