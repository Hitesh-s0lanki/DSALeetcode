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

pair<int,int> predecessorSuccessor(TreeNode* root, int key){
    int pred=-1;
    int succ=-1;

    TreeNode* temp=root;
    while(temp->val != key){
        if(temp -> val < key){
            pred = temp -> val;
            temp = temp -> right;
        }
        else{
            succ = temp -> val;
            temp = temp -> left;
        }
    }

    //pred and succ

    TreeNode* leftNode = temp -> left;
    while(leftNode != NULL){
        pred = temp -> val;
        leftNode = leftNode -> right;
    }
    TreeNode* rightNode = temp -> right;
    while(rightNode != NULL){
        succ = temp -> val;
        leftNode = leftNode -> left;
    }

    pair<int,int> ans=make_pair(pred,succ);

    return ans;
}


int main(){
    // 8 3 10 1 6 14 13 4 7 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
    cout<<endl;
    pair<int,int> ans=predecessorSuccessor(root,4);
    cout<<"the pre is "<<ans.first<<"\t";
    cout<<"the succ is "<<ans.second;
}