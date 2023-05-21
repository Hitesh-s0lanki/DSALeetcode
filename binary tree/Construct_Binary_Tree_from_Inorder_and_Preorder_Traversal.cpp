#include<iostream>
#include<vector>
#include<map>
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
void preOrder(TreeNode *root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<"\t";
    preOrder(root->left);
    preOrder(root->right);
}
// TreeNode* buildTree(TreeNode* root,vector<int> put,int &index){
//     root=new TreeNode(put[index++]);
//     if(root->val==-1){
//         return NULL;
//     }
//     root->left=buildTree(root->left,put,index);
//     root->right=buildTree(root->right,put,index);
//     return root;
// }

void createMap(map<int,int> &marking,vector<int>& inorder){
    for(int i=0;i<inorder.size();i++){
        marking[inorder[i]]=i;
    }
}


TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preOrderIndex,int startIndexvalue,int endvalueIndex,int n,map<int,int> marking){
    //base Case
    if(preOrderIndex > n || startIndexvalue > endvalueIndex){
        return NULL;
    }
    int element=preorder[preOrderIndex++];
    TreeNode * ans=new TreeNode(element);

    int p=marking[element];

    //left
    ans->left=solve(preorder,inorder,preOrderIndex,startIndexvalue,p-1,n,marking);
    //right
    ans->right=solve(preorder,inorder,preOrderIndex,p+1,endvalueIndex,n,marking);

    return ans;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> marking;
        //Creating the maping
        createMap(marking,inorder);

        int preOrderIndex=0;
        int n=inorder.size()-1;
        
        TreeNode* ans= solve(preorder,inorder,preOrderIndex,0,n,n,marking);

        return ans;

    }

int main(){
    // vector<int> put={3,9,-1,-1,20,15,-1,-1,7,-1,-1};
    // int index=0;
    // TreeNode* root=buildTree(root,put,index);
    // preOrder(root);
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};

    TreeNode* root=buildTree(preorder,inorder);


    preOrder(root);

}