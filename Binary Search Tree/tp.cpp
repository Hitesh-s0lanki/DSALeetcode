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
        this->val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void inOrder(TreeNode* root){
    if(root == NULL) return ;

    inOrder(root -> left);
    cout<<root -> val<< "\t";
    inOrder(root -> right);
}

TreeNode* insertBST(TreeNode* root, int val){
    if(root == NULL){
        TreeNode* temp = new TreeNode(val); 
        return temp;
    }
    if(root -> val > val){
        root -> left = insertBST(root -> left, val);
    }else if(root -> val < val){
        root -> right = insertBST(root -> right, val);
    }
    return root;
}

TreeNode* buildTree(vector<int> val){
    TreeNode* root = NULL;
    for(auto i:val){
        root = insertBST(root, i);
    }
    return root;
}

void levelOrder(TreeNode* root){
    queue<TreeNode* > q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp -> val<<"\t";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }

}

int main(){
    vector<int> val = {9, 15, 20, 8, 7, 13, 10};

    TreeNode* root = buildTree(val);

    levelOrder(root);
    // inOrder(root);
}