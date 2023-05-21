#include<iostream>
#include<vector>
#include<map>
#include<queue>
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
vector<int> verticalOrder(TreeNode *root){
        
    map<int,map<int,vector<int>>> node;
    queue<pair<TreeNode*,pair<int,int>>> q;
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<TreeNode*,pair<int,int>> temp=q.front();
        q.pop();
        TreeNode* frontNode=temp.first;
        
        int hd=temp.second.first;//Horizontal distance
        int lvl=temp.second.second;//level

        node[hd][lvl].push_back(frontNode->val);
        cout<<hd<<" "<<lvl<<"\t";
        cout<<frontNode->val<<endl;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
    }
    for (auto i:node){
        for (auto j:i.second){
            for(auto k:j.second){
                cout<<k<<endl;
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main(){
    //1 2 4 -1 -1 6 -1 -1 3 5 -1 -1 7 -1 -1
    TreeNode* root=buildTree(root);
    preOrder(root);
    cout<<endl;
    vector<int> ans=verticalOrder(root);
    for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<"\t";
    }
}