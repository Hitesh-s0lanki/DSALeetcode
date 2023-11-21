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

int treeHeight(TreeNode* root){
    if(root == NULL) return 0;
    return max(treeHeight(root -> left), treeHeight(root -> right)) + 1;
}

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

TreeNode* leftShift(TreeNode* root){
    TreeNode* new_root = root -> right;
    new_root -> left = root;
    root -> right = NULL;
    return new_root;
}

TreeNode* rightShift(TreeNode* root){
    TreeNode* new_root = root -> left;
    new_root -> right = root;
    root -> left = NULL;
    return new_root;
}

TreeNode* pivotNode(TreeNode* pivot, int val, bool flag){

    if(flag){
        if(pivot -> left && pivot -> left -> val == val){
            pivot -> left = rightShift(pivot -> left);
        }
        return leftShift(pivot);
    }else{
        if(pivot -> right && pivot -> right -> val == val){
            pivot -> right = leftShift(pivot -> right);
        }
        return rightShift(pivot);
    }
}


TreeNode* isBalance(TreeNode* root, int val){
    if(root == NULL){
        return NULL;
    }

    int leftHeight = treeHeight(root -> left);
    int rightHeight = treeHeight(root -> right);

    if(abs(leftHeight - rightHeight) > 1){
        if(root -> val < val){
            return pivotNode(root, val, true);
        }else{
            return pivotNode(root, val, false);
        }
    }

    root -> left = isBalance(root -> left, val);
    root -> right = isBalance(root -> right, val);

    return root;
} 

TreeNode* buildTree(vector<int> val,int end){
    TreeNode* root = NULL;
    for(int i = 0; i< end;i++){
        root = isBalance(insertBST(root, val[i]), val[i]);
    }
    return root;
}



int main(){
    vector<int> val = {21, 26, 30, 9, 4, 14, 28, 18, 15, 10, 2, 3, 7};

    TreeNode* root = buildTree(val, 7);

    levelOrder(root);

}