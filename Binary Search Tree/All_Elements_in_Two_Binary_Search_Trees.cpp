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

void InOrder(TreeNode* root,vector<int> &ans){
    if(root==NULL){
        return ;
    }
    InOrder(root->left,ans);
    ans.push_back(root->val);
    InOrder(root->right,ans);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1,ans2;
        InOrder(root1,ans1);
        InOrder(root2,ans2);

        int i=0,j=0;
        vector<int> ans;
        while(i < ans1.size() && j < ans2.size() ){
            if(ans1[i] > ans2[j]){
                ans.push_back(ans2[j++]);
            }
            else{
                ans.push_back(ans1[i++]);
            }
        }

        while(i < ans1.size()){
            ans.push_back(ans1[i++]);
        }
        while(j < ans2.size()){
            ans.push_back(ans2[j++]);
        }

        return ans;
}


int main(){
    // 2 1 4 -1 1 0 3 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode* root1=NULL;
    root1=buildBST(root1);
    // print(root1);
    cout<<endl;
    TreeNode* root2=NULL;
    root2=buildBST(root2);
    // print(root2);

    vector<int> ans=getAllElements(root1,root2);
    for(auto i: ans){
        cout<<i<<"\t";
    }
}