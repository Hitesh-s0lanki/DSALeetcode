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


TreeNode* insertIntoBST(vector<int> ans,int s,int e){

    if(s>e){
        return NULL;
    }

    int mid=(s+e)/2;

    TreeNode* root=new TreeNode(ans[mid]);
    
    root->left=insertIntoBST(ans,s,mid-1);
    root->right=insertIntoBST(ans,mid+1,e);

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

TreeNode* balanceBST(TreeNode* root) {
    vector<int> ans;
    inOrder(root,ans);

    TreeNode* NewTree=insertIntoBST(ans,0,ans.size()-1);

    return NewTree;
}


int main(){
    // 10 8 21 7 27 5 4 3 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root=NULL;
    root=buildBST(root);
    print(root);
}