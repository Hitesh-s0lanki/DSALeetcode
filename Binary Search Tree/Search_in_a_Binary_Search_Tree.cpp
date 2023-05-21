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

TreeNode* searchBST(TreeNode* root, int val) {
    while(root!=NULL){
        if(root->val==val){
            return root;
        }
        else if(root->val < val){
            root=root->right;
        }
        else{
            root=root->left;
        }

    }
    return NULL;
}

int main(){
    // 4 2 7 1 3 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    // print(root);
    TreeNode* ans=searchBST(root,3);
    print(ans);
}