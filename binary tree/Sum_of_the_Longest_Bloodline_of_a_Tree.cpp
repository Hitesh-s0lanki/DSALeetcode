#include<iostream>
#include<climits>
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

void solve(Node* root,int sum,int &MaxSum,int len,int &Maxlen){
    if(root==NULL){
        if(len>Maxlen){
            Maxlen=len;
            MaxSum=sum;
        }
        else if(len==Maxlen){
            MaxSum=max(MaxSum,sum);
        }
        return;
    }
    sum+=root->data;
    solve(root->left,sum,MaxSum,len+1,Maxlen);
    solve(root->right,sum,MaxSum,len+1,Maxlen);
}
int sumOfLongRootToLeafPath(Node *root){

    int sum=0;
    int MaxSum=INT_MIN;

    int len=0;
    int Maxlen=0;

    solve(root,sum,MaxSum,len,Maxlen);
    return MaxSum;    
}


int main(){
    // 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1
    Node* root=buildTree(root);
    preOrder(root);
    cout<<endl;
    cout<<sumOfLongRootToLeafPath(root);
}
    //     4        
    //    / \       
    //   2   5      
    //  / \ / \     
    // 7  1 2  3    
    //   /
    //  6