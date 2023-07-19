#include "TreeNode.h"
#include<queue>

TreeNode* reverseOddLevels(TreeNode* root) {

    vector<TreeNode*> temp2;
    vector<vector<TreeNode*>> ans;
    queue<TreeNode* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp =q.front();
        q.pop();
        if(temp == NULL){
            ans.push_back(temp2);
            temp2.clear();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            temp2.push_back(temp);
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp ->right);
        }
    } 
    for(int i = 1 ;i<ans.size();i=i+2){
        for(int j=0;j<ans[i].size()/2;j++){
            int temp = ans[i][j]->val;
            ans[i][j]->val = ans[i][ans[i].size() - j - 1]->val;
            ans[i][ans[i].size() - j - 1]->val = temp;
        }
    }
    return root;
}

int main(){

}