#include<iostream>
#include<vector>
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
    if(data==0){
        return NULL;
    }
    cout<<"Enter the Data in left of "<<root->data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the Data in right of "<<root->data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void solve(Node* root,int k,vector<int> path,int &count){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);

    solve(root->left,k,path,count);
    solve(root->right,k,path,count);
    int sum=0;
    int size=path.size();
    for (int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k)
            count++;
    }
    path.pop_back();
}

int sumK(Node *root,int k){
    vector<int> path;
    int count=0;
    solve(root,k,path,count);
    return count;    
}

int main(){
    // 1 3 2 0 0 1 1 0 0 0 -1 4 1 0 0 2 0 0 5 0 6 0 0
    Node* root=buildTree(root);
    preOrder(root);
    cout<<endl;
    cout<<sumK(root,5);
}
//            1
//         /     \
//       3        -1
//     /   \     /   \
//    2     1   4     5                        
//         /   / \     \                    
    //    1   1   2     6  