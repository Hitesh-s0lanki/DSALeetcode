#include<iostream>
#include<vector>
#include<queue>
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
Node* buildTree(Node* root){
    cout<<"Enter the data of root"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data in left of "<<root->data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data in right of "<<root->data<<endl;
    root->right=buildTree(root->right);

    return root;
}
void print(Node* root){
    if(root==NULL)
        return;
        cout<<root->data<<"\t";
        print(root->left);
        print(root->right);
}
void levelOrderTranvesal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<"\t";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
vector<int> zigZagTraversal(Node* root){
    vector<int> result;
        queue<Node*> q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> ans(size);
            //add data to ans
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);

                    //loading the value
                    int index=leftToRight?i:size-i-1;
                    ans[index]=temp->data;
            }
            //direction change
            leftToRight=!leftToRight;
            for(auto i:ans){
                result.push_back(i);
            }
        }
        return result;
    }
int main(){
    //1 2 4 -1 -1 -1 3 -1 5 6 -1 -1 -1
    Node* root=buildTree(root);
    print(root);
    cout<<endl;
    // levelOrderTranvesal(root);
    vector<int> ans=zigZagTraversal(root);
    for(auto i:ans){
        cout<<i<<"\t";
    }
}