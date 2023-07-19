#include "TreeNode.h"


void solve(TreeNode* root,string pre,int &ans){
    //BASE condition
    if(root == NULL)
        return;

    pre.push_back(root->val + '0');
    solve(root->left,pre,ans);
    solve(root->right,pre,ans);

    if(root->left == NULL && root -> right == NULL){
        int number = 0;
        while(pre.length() != 0){
            number = number*10 + (pre[0]-'0');
            pre = pre.substr(1);
        }
        ans+=number;
        return ;
    }

    pre.pop_back();
}

int sumNumbers(TreeNode* root) {
      int ans = 0;  
      string pre;
      solve(root,pre,ans);

      return ans;
}
int main(){
    vector<int> val = {1,2,-1,-1,3,-1,-1};
    int index = 0;
    TreeNode* root = root -> buildTree(val,index);
    cout<<sumNumbers(root);
}