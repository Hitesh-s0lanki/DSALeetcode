#include<iostream>
#include<vector>
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
void print(TreeNode* root){
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->val<<"\t";
    print(root->right);
}
TreeNode* insertInBST(TreeNode* root,int d){
    //Base case 
    if(root==NULL){
        root=new TreeNode(d);
        return root;
    }
    else if(root->val > d ){
        root->left=insertInBST(root->left,d);
    }
    else{
        root->right=insertInBST(root->right,d);
    }
        return root;
}

TreeNode* buildBST(TreeNode* root){
    int data;
    cin>>data;

    while(data != -1){
        root=insertInBST(root,data);
        cin>>data;
    }
    return root;
}

void inOrder(TreeNode* root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> ans;
     inOrder(root,ans);

     int i=0;
     int j=ans.size()-1;

     while(i<j){
        int sum=ans[i]+ans[j];
        if(sum == k){
            return true;
        }
        else if(sum > k){
            j--;
        }
        else{
            i++;
        }
     }
     return false;
}

int main(){
    // 10 8 21 7 27 5 4 3 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
    cout<<endl;
    cout<<findTarget(root,29);

}