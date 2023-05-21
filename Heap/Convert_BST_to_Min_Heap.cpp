#include<iostream>
#include<vector>
using namespace std;

class BST{
    public:
    int val;
    BST* left;
    BST* right;
    BST(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void inOrderPrint(BST* root){
    if(root == NULL)
        return;
    inOrderPrint(root->left);
    cout<<root->val<<"\t";
    inOrderPrint(root->right);
}
BST* insertIntoBST(BST* root,int val){
    if(root == NULL){
        BST* temp = new BST(val);
        return temp;
    }
    if(root -> val > val){
        root -> left = insertIntoBST(root -> left ,val);
    }
    else{
        root -> right = insertIntoBST(root -> right ,val);
    }

    return root;
}
BST* buildTree(vector<int> val){
    BST* root = NULL;
    for(auto i:val){
        root = insertIntoBST(root,i);
    }
    return root;
}
void CreateInOrder(BST* root,vector<int> &inOrder){
    if(root == NULL)
        return;
    CreateInOrder(root->left,inOrder);
    inOrder.push_back(root->val);
    CreateInOrder(root->right,inOrder);    
}
void PreOrderTranversal(BST* root,vector<int> inOrder,int &index){
    if(root == NULL)
        return;
    root->val = inOrder[index++];
    PreOrderTranversal(root->left,inOrder,index);
    PreOrderTranversal(root->right,inOrder,index);
}
void BSTToMinHeap(BST* root){
    vector<int> inOrder;
    CreateInOrder(root,inOrder);
    int index=0;
    PreOrderTranversal(root,inOrder,index);
}
int main(){
    vector<int> val = {4,2,6,1,3,5,7};
    BST* root = buildTree(val);
    inOrderPrint(root);
    cout<<endl;
    BSTToMinHeap(root);
    inOrderPrint(root);
}
// Input:            4
//                 /   \*
//               2     6
//             /  \   /  \*
//           1   3  5    7  
// Output:          1
//                /   \*
//              2     5
//            /  \   /  \*
//          3     4 6    7 