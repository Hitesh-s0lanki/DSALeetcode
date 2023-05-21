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
vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode* > q;
        vector<double> ans;
        q.push(root);
        q.push(NULL);
        double num=0;
        int count=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(num/count);
                count=0;
                num=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                count++;
                num+=temp->val;
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
    vector<double> a=averageOfLevels(root);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"\t";
    }
}