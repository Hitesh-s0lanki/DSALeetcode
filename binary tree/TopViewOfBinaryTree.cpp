#include "TreeNode.h"
#include<queue>
#include<map>

vector<int> getTopView(TreeNode *root) {
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,map<int,vector<int>>> node;
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<TreeNode*,pair<int,int>> temp = q.front();

        q.pop();

        int hd = temp.second.first;
        int lvl = temp.second.second;

        node[hd][lvl].push_back(temp.first->val);

        if(temp.first->left){
            q.push(make_pair(temp.first->left,make_pair(hd - 1 , lvl + 1)));
        }
        if(temp.first->right){
            q.push(make_pair(temp.first->right,make_pair(hd + 1 , lvl + 1)));
        }
    }

    for(auto i:node){
        for(auto j:i.second){
            ans.push_back(j.second[0]);
            break;
        }
    }
    return ans;
}
int main(){
    vector<int> val = {1,2,4,-1,7,9,10,-1,-1,-1,-1,5,-1,-1,3,-1,6,8,-1,11,-1,-1,-1};
    int index = 0;
    TreeNode* root = root->buildTree(val,index);

    vector<int> ans = getTopView(root);
    cout<<endl;
    for(auto i:ans){
        cout<<i<<"\t";
    }
}