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
TreeNode* insertIntoBST(TreeNode* root, int val) {
         //Base case 
            if(root==NULL){
                root=new TreeNode(val);
                return root;
            }
            else if(root->val > val ){
                root->left=insertIntoBST(root->left,val);
            }
            else{
                root->right=insertIntoBST(root->right,val);
            }
                return root;
    }
TreeNode* buildBST(TreeNode* root){
    int data;
    cin>>data;

    while(data != -1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
    return root;
}
int main(){
    // 10 8 21 7 27 5 4 3 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
}