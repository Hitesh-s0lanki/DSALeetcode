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

TreeNode* minimumNode(TreeNode* root){
    TreeNode* temp=root;
    while(temp->left)
        temp=temp->left;

    return temp;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if( root == NULL){
        return root;
    }
    else if(root->val == key){
        //No child
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        //One child Present
            //left 
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            //right
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
        
        //Both the Child present
            //Find the minimum node in right Child
            if(root->left != NULL && root->right != NULL){
                int mini=minimumNode(root->right) -> val;
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
    }
    else if(root->val > key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->val < key){
        root->right=deleteNode(root->right,key);
    }
    return root;
}
int main(){
    // 5 3 6 2 4 7 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
    cout<<endl;
    TreeNode* ans=deleteNode(root,4);
    print(ans);
}