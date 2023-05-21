#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<"\t";
    preOrder(root->left);
    preOrder(root->right);
}
Node* buildTree(Node* root,vector<int> put,int &index){
    root=new Node(put[index++]);
    if(root->val==-1){
        return NULL;
    }
    root->left=buildTree(root->left,put,index);
    root->right=buildTree(root->right,put,index);
    return root;
}


void flatten(Node *root){
    Node* curr=root;

    while(curr!=NULL){
        if(curr->left){
            Node* prev=curr->left;
            while(prev->right)
                prev=prev->right;
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;

    }

}



int main(){
    vector<int> put={1,2,3,-1,-1,4,-1,7,-1,-1,5,-1,6,-1,-1};
    int index=0;
    Node* root=buildTree(root,put,index);
    preOrder(root);
    flatten(root);
    cout<<endl;
    preOrder(root);


}
