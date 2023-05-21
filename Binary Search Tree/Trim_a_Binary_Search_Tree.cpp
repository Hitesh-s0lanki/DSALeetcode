// NOT Submited

#include<iostream>
#include<vector>
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
void levelOrderTraversal(TreeNode* root){
    queue<TreeNode* > q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<"\t";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    cout<<endl;
}

TreeNode* deleteNode(TreeNode* root,int val){
    //Base case
    if(root==NULL){
        return NULL;
    }
    if(root -> val == val){
        //if No child
        if( root -> left == NULL && root -> right == NULL ){
            return NULL;
        }
        //One child 
        else if( root -> left != NULL && root -> right == NULL ){
            return root -> left;
        }
        else if( root -> left == NULL && root -> right != NULL ){
            return root -> right;
        }
        else if( root -> left != NULL && root -> right != NULL ){
            TreeNode *temp=root->right;
            while(temp->left)
                temp=temp->left;
            int element= temp->val;
            root -> val =element;
            root-> right=deleteNode(root->right,element);
        }
            
    }
    else if(root -> val > val){
       root->left=deleteNode(root->left,val); 
    }
    else{
       root->right=deleteNode(root->right,val);
    }

    return root;
}

TreeNode* trimBST(TreeNode* root, int low, int high) {
   //Base Condition
   if(root == NULL)  
        return NULL;   
    if(root -> val < low || root -> val > high){
        root=deleteNode(root,root->val);
        root=trimBST(root,low,high);
    }
    if(root){
       root->left= trimBST(root->left,low,high);
       root->right= trimBST(root->right,low,high);
    }
    return root;
}

int main(){
    vector<int> put={8,3,10,1,6,14,4,7,13};
    TreeNode* root=NULL;
    root=buildBST(put);
    cout<<endl;
    root=trimBST(root,1,10);
    levelOrderTraversal(root);
    print(root);
}