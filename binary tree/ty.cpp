#include<iostream>
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
TreeNode* buildTree(TreeNode* root){
    cout<<"Enter the Data"<<endl;
    int data;
    cin>>data;
    root = new TreeNode(data);
    if( data == -1)
        return NULL;
    cout<<"Enter the value in ";
    root -> left = buildTree(root ->left);
    root -> right = buildTree(root ->right);

    return root;
}
int main(){

}