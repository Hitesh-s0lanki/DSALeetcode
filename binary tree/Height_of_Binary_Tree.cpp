#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root){
    cout<<"Enter the data of root node"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"enter the data in left node of tree of "<<root->data<<endl; 
    root->left=buildTree(root->left);
    cout<<"enter the data in right node of tree of "<<root->data<<endl; 
    root->right=buildTree(root->right);
    return root;
}
void preOrderPrint(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"\t";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
// int height(node* root){
//         queue<node*> q;
//         q.push(root);
//         q.push(NULL);
//         int count=0;
//         while(!q.empty()){
//             node* temp=q.front();
//             q.pop();
//             if(temp==NULL){
//                 count++;
//                 if(!q.empty()){
//                     q.push(NULL);
//                 }
//             }
//             else{
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//             }
//         }
//         return count;
//     }
int height(node* root){
    //base case
    if(root==NULL){
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);

    int ans=max(left,right)+1;
    return ans;
}
int main(){
    // 1 2 -1 -1 3 -1 -1
    // 2 -1 1 3 -1 -1 -1 
    node* root=NULL;
    root=buildTree(root);
    preOrderPrint(root);
    cout<<endl;
    cout<<height(root);
}