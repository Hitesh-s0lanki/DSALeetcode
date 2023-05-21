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
    if(root == NULL){
        return;
    }
    cout<<root->val<<"\t";
    print(root->left);
    print(root->right);
}
TreeNode* buildTree(vector<int> val , int &index){
    if(val[index] == -1)
        return NULL;
    
    TreeNode* root = new TreeNode(val[index]);
    index++;
    root->left = buildTree(val,index);
    index++;
    root->right = buildTree(val,index);

    return root;

}
int countNode(TreeNode* root){
    if(root == NULL)
        return 0;

    return 1+countNode(root->left)+countNode(root->right);
}

bool solveisCompleteTree(TreeNode* root,int index,int total){
    if(root == NULL)
        return true;
    if((root -> left == NULL && root -> right != NULL)||(index >= total))
        return false;

    return solveisCompleteTree(root->left,index*2+1,total) && solveisCompleteTree(root->right,index*2+2,total);
}

bool isMaxHeap(TreeNode* root){
    if(root == NULL || (root->left == NULL && root -> right == NULL))
        return true;
    
    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);

    if(root->left != NULL && root -> right == NULL)
        return left && right && (root->left->val < root->val);

    return left && right && (root->left->val < root->val) && (root->right->val < root->val);
    
}

bool isHeap(TreeNode* root) {
    int total = countNode(root);
    return solveisCompleteTree(root,0,total) && isMaxHeap(root);
}

int main(){
    vector<int> val={60,50,20,-1,-1,40,-1,-1,30,-1,-1};
    int index=0;
    TreeNode* root = buildTree(val,index); 
    print(root);
    cout<<endl;
    cout<<isHeap(root);
}