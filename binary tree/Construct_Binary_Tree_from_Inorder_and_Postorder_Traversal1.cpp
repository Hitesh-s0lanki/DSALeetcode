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


TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &postOrderIndex,int startIndexvalue,int endvalueIndex,int n,map<int,int> marking){
    //base Case
    if(postOrderIndex < 0 || startIndexvalue > endvalueIndex){
        return NULL;
    }
    int element=preorder[postOrderIndex--];
    TreeNode * ans=new TreeNode(element);

    int p=marking[element];

    //right
    ans->right=solve(preorder,inorder,postOrderIndex,p+1,endvalueIndex,n,marking);
    //left
    ans->left=solve(preorder,inorder,postOrderIndex,startIndexvalue,p-1,n,marking);

    return ans;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       map<int,int> marking;
        //Creating the maping
        createMap(marking,inorder); 
        int n=inorder.size()-1;
        int postOrderIndex=n;

        TreeNode* ans= solve(postorder,inorder,postOrderIndex,0,n,n,marking);

        return ans;
    }
int main(){
    // vector<int> put={3,9,-1,-1,20,15,-1,-1,7,-1,-1};
    // int index=0;
    // TreeNode* root=buildTree(root,put,index);
    // preOrder(root);
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};

    TreeNode* root=buildTree(inorder,postorder);


    preOrder(root);

}