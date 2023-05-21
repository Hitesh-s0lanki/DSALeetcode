#include <iostream>
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
    void preOrderPrint(TreeNode* root){
        if(root == NULL)
            return;
        cout<<root->val<<"\t";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
    TreeNode* buildTree(vector<int> val,int &index){
        if(val[index] == -1){
            index++;
            return NULL;
        }
        TreeNode* root = new TreeNode(val[index++]);

        root->left = buildTree(val,index);
        root->right = buildTree(val,index);

        return root;
    }
};