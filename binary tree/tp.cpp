#include "TreeNode.h"
#include<queue>
#include<algorithm>

using namespace std;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                temp.push_back(front -> val);
                if(front->left)
                    q.push(front->left);
                if(front -> right)
                    q.push(front->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
    vector<int> val ={3,9,-1,-1,20,15,-1,-1,7,-1,-1};
    int index = 0;
    TreeNode* root = root->buildTree(val,index);
    // root->preOrderPrint(root);
    vector<vector<int>> ans = levelOrderBottom(root);
    for(auto i:ans){
        for(auto j:i)
            cout<<j<<"\t";
        cout<<endl;
    }
}