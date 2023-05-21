#include "TreeNode.h"
#include<climits>

void solve(TreeNode* root,int &ans){
    if(root == NULL)
        return ;

    solve(root->left,ans);
    solve(root->right,ans);

    int sum = ans + root->val;

    ans = max(ans,sum);
}

int maxPathSum(TreeNode* root) {
    int ans=0;
    solve(root,ans);
    return ans;
}
int main(){
    vector<int> val={1,2,-1,-1,3,-1,-1};
    int index=0;
    TreeNode* root=root->buildTree(val,index);
    root->preOrderPrint(root);
    cout<<endl;
    cout<<maxPathSum(root);
}