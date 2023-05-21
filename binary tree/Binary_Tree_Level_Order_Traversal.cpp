#include<iostream>
#include<vector>
#include<algorithm>
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
    
    cout<<"enter the root node "<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);

    if(data==-1){
        return NULL;
    }

    cout<<"enter the data in left node of "<<root->val<<endl;
    root->left=buildTree(root->left);

    cout<<"enter the data in right node of "<<root->val<<endl;
    root->right=buildTree(root->right);

    return root;
}
void preOrderPrint(TreeNode* root){
    if(root==NULL){
        return ;
    }

    cout<<root->val<<"\t";
    preOrderPrint(root->left);
    preOrderPrint(root->right);

}
 vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> ans;
        vector<int> temp1;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(temp1);
                temp1.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                temp1.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
int main(){
     //3 9 -1 -1 20 15 -1 -1 7 -1 -1
    TreeNode* root=NULL;
    root=buildTree(root);
    preOrderPrint(root);
    cout<<endl;
    vector<vector<int>> ans=levelOrder(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }
}