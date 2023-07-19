#include "TreeNode.h"
#include<climits>

int solve(TreeNode* root){
    if(root == NULL)
        return INT_MIN;

    if(root -> left == NULL && root ->right == NULL)
        return root->val;

    int sum = 0;
    int leftSum = 0;
    int rightSum = 0;
    int left = solve(root->left);
    if(left != INT_MIN){
        sum += left;
        leftSum = sum + root->val;
    }
    int right = solve(root->right);
    if(right != INT_MIN){
        sum+=right;
        rightSum = sum + root -> val;
    }
    
    sum+=root->val;
    
    sum = max(sum,max(leftSum,rightSum));
    

    return max(root->val,max(right,max(sum,left)));
}

int maxPathSum(TreeNode* root) {
    return solve(root);
}
int main(){
    vector<int> val={1,2,-1,-1,3,-1,-1};
    int index=0;
    TreeNode* root=root->buildTree(val,index);
    root->preOrderPrint(root);
    cout<<endl;
    cout<<maxPathSum(root);
}