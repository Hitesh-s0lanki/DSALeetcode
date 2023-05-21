#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void preOrder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<"\t";
    preOrder(root->left);
    preOrder(root->right);
}
Node* buildTree(Node* root){
    cout<<"Enter the data of root Node"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the Data in left of "<<root->data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the Data in right of "<<root->data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void solve(Node* root,pair<int,int> &ans,int index){
    if(root==NULL){
        return;
    }
    if(index%2==0){
        ans.first+=root->data;
    }
    else{
        ans.second+=root->data;
    }

    //left
    solve(root->left,ans,index+1);
    //right
    solve(root->right,ans,index+1);

}

int getMaxSum(Node *root) {
    pair<int,int> ans=make_pair(0,0);
    solve(root,ans,0);
    return max(ans.first,ans.second);
}
int main(){
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    Node* root=buildTree(root);
    preOrder(root);
    cout<<endl;
    cout<<getMaxSum(root);
}