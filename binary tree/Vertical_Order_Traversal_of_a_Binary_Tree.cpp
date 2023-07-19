#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
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
TreeNode* buildTree(TreeNode* root){
    cout<<"Enter the Data"<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);
    if(data==-1)
        return NULL;

        cout<<"Enter the data in left of "<<root->val<<endl;
        root->left=buildTree(root->left);
        cout<<"Enter the data in right of "<<root->val<<endl;
        root->right=buildTree(root->right);

    return root;
}
void preOrder(TreeNode* root){
    if(root==NULL)
        return;
        cout<<root->val<<"\t";
        preOrder(root->left);
        preOrder(root->right);
}
// vector<int> verticalOrder(TreeNode *root){
        
//     map<int,map<int,set<int>>> node;
//     queue<pair<TreeNode*,pair<int,int>>> q;
//     vector<int> ans;

//     if(root==NULL){
//         return ans;
//     }

//     q.push(make_pair(root,make_pair(0,0)));
//     while(!q.empty()){
//         pair<TreeNode*,pair<int,int>> temp=q.front();
//         q.pop();
//         TreeNode* frontNode=temp.first;
        
//         int hd=temp.second.first;//Horizontal distance
//         int lvl=temp.second.second;//level

//         node[hd][lvl].insert(frontNode->val);

//         if(frontNode->left){
//             q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
//         }
//         if(frontNode->right){
//             q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
//         }
//     }
//     for (auto i:node){
//         for (auto j:i.second){
//             for(auto k:j.second){
//                 ans.push_back(k);
//             }
//         }
//     }
//     return ans;
// }


vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        map<int,map<int,vector<int>>> node;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));

        while (!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();

            int hd = temp.second.first;
            int lvl = temp.second.second;

            node[hd][lvl].push_back(temp.first -> val);

            if(temp.first -> left){
                q.push(make_pair(temp.first -> left,make_pair(hd - 1, lvl + 1)));
            }
            if(temp.first->right){
                q.push(make_pair(temp.first -> right,make_pair(hd + 1, lvl + 1)));
            }

        }

        for(auto i:node){
            vector<int> temp;
            for(auto j: i.second){
                vector<int> temp2;
                for(auto k:j.second){
                    temp2.push_back(k);
                }
                sort(temp2.begin(),temp2.end());
                for(auto u:temp2){
                    temp.push_back(u);
                }
            }
            ans.push_back(temp);
        }
        
    return ans;
}

int main(){
    //1 2 4 -1 -1 6 -1 -1 3 5 -1 -1 7 -1 -1
    TreeNode* root=buildTree(root);
    preOrder(root);
    cout<<endl;
    vector<vector<int>> ans=verticalTraversal(root);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<'\t';
        }
        cout<<endl;
    }
}