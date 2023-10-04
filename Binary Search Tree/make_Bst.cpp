#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};
TreeNode* insertInBST(TreeNode* root,int val){
    if(root == NULL){
        TreeNode* temp = new TreeNode(val);
        return temp;
    }
    else if (root -> val < val){
        root -> right = insertInBST(root -> right , val);
    }
    else{
        root -> left = insertInBST(root -> left , val);
    }
    return root;
}
TreeNode* buildBST(vector<int> val){
    TreeNode* root = NULL;
    for(auto i : val){
        root = insertInBST(root,i);
    }
    return root;
}
void print(TreeNode* root){
    if(root == NULL)
        return;
    print(root -> left);
    cout<<root -> val << "\t";
    print(root -> right);
}
int main(){
    vector<int> val = {2,1,3,4};
    TreeNode* root = buildBST(val);
    print(root);
}