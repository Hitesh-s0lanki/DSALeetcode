#include<iostream>
#include<vector>
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
        this-> right=NULL;
    }
};
void print(TreeNode* root){
    if(root == NULL)
        return;
    print(root->left);
    cout<<root->val<<"\t";
    print(root->right);
}

TreeNode* insertIntoBST(TreeNode* root,int d){
    if(root == NULL){
        TreeNode* temp=new TreeNode(d);
        return temp;
    }
    if( root -> val > d){
        root->left=insertIntoBST(root->left,d);
    }
    else{
        root->right=insertIntoBST(root->right,d);
    }

    return root;

}
TreeNode* buildBST(vector<int> put){
    TreeNode* root=NULL;
    for (auto i:put){
       root=insertIntoBST(root,i);
    }
    return root;
}

void CreateInOrder(TreeNode* root,vector<int> &in){
    if(root == NULL)
        return;
    CreateInOrder(root->left,in);
    in.push_back(root->val);
    CreateInOrder(root->right,in);
}
void ProperAll(TreeNode* root,vector<int> in,int &index){
    if(root == NULL)
        return;
    ProperAll(root->left,in,index);
    root->val=in[index++];
    ProperAll(root->right,in,index);
}
void recoverTree(TreeNode* root) {
      vector<int> in;
      CreateInOrder(root,in);  
      sort(in.begin(),in.end());
      int index=0;
      ProperAll(root,in,index);
}

int main(){
    vector<int> put={8,3,10,1,6,14,4,7,13};
    TreeNode* root=NULL;
    root=buildBST(put);
    print(root);
    cout<<endl;
}