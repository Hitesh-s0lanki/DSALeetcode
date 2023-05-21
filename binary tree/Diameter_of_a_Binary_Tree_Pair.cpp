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
 pair<int,int> diameterFast(TreeNode* root) {
    if(root==NULL){
        pair<int,int> p(0,0);
        return p;
    }

    pair<int,int> left=diameterFast(root->left);
    pair<int,int> right=diameterFast(root->right);

    int opt1=left.first;
        int opt2=right.first;
        int opt3=left.second+right.second+1;

        pair<int,int> ans;
        ans.first = max(opt1, max(opt2, opt3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
 }
 int diameter(TreeNode* root) {
    
        return diameterFast(root).first;
    }
int main(){
    //1 2 -1 -1 3 -1 -1 
    TreeNode* root=NULL;
    root=buildTree(root);
    preOrderPrint(root);
    cout<<endl;
    cout<<diameter(root);
}