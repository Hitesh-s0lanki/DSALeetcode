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


void inorder(TreeNode* root,vector<int > &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

TreeNode* increasingBST(TreeNode* root) {
    if(root== NULL){
        return root;
    }
     vector<int > ans;
     TreeNode* temp=root;
     inorder(temp,ans);
    
     TreeNode* curr=new TreeNode(ans[0]);

     for(int i=1;i<ans.size();i++){
        TreeNode* temp=new TreeNode(ans[i]);
        curr->right=temp;
        curr->left=NULL;
        curr=temp;
     }   
     curr->left=curr->right=NULL;
     return root;
}


int main(){
    // 5 3 6 2 4 8 7 9 1 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
}