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

void solve(TreeNode* root,int &ans){
    if(root == NULL)
        return;
    if(root -> left == NULL &&root -> right == NULL ){
        ans++; 
        return;
    }

    if((root -> left != NULL &&root -> right == NULL )||( root -> left != NULL &&root -> right != NULL ))
        ans++;

    solve(root->left,ans);
    solve(root->right,ans);
    
}

int countNodes(TreeNode* root) {
    int ans=0;
    solve(root,ans);

    return ans;
}

int main(){
    vector<int> val={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,-1};
    int index=0;
    TreeNode* root = buildTree(val,index); 
    print(root);
    cout<<endl;
    cout<<countNodes(root);
}