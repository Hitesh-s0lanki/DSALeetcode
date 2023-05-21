#include<iostream>
#include<vector>
#include<map>
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
void preOrderPrint(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"\t";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
Node* buildTree(vector<int> put,int &index){
    Node* root=new Node(put[index++]);
    if(root->data==-1){
        return NULL;
    }
    root->left=buildTree(put,index);
    root->right=buildTree(put,index);

    return root;
}

//creating the mapping to the parent node
//returning the target Node
Node* createMapping(Node* root, int target,map<Node*,Node*> &childToParent){
    Node* targetNode=NULL;

    queue<Node*> q;
    q.push(root);

    childToParent[root]=NULL;

    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        
        if(front->data == target){
            targetNode=front;
        }
        if(front->left){
            childToParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            childToParent[front->right]=front;
            q.push(front->right);
        }
    }

    return targetNode;
}

int burnTree(Node* root,map<Node*,Node*> &childToParent){
    int ansTime=0;

    map<Node*,bool> visited;

    queue<Node*> q;
    q.push(root);
    visited[root]=true;
    while(!q.empty()){
        int size=q.size();
        bool flag=false;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                visited[temp->left]=true;
                q.push(temp->left);
                flag=true;
            }
            if(temp->right && !visited[temp->right]){
                visited[temp->right]=true;
                q.push(temp->right);
                flag=true;
            }
            if(childToParent[temp] && !visited[childToParent[temp]]){
                visited[childToParent[temp]]=true;
                q.push(childToParent[temp]);
                flag=true;
            }
        }
        if(flag){
            ansTime++;
        }
    }
    return ansTime;
}

int minTime(Node* root, int target){
    map<Node*,Node*> childToParent;
    
    Node* targetNode=createMapping(root,target,childToParent);

    int ans=burnTree(targetNode,childToParent);
    return ans;
}



int main(){
    vector<int> put={1,2,4,-1,-1,5,7,-1,-1,8,-1,-1,3,-1,6,-1,9,-1,10,-1,-1};
    int index=0;
    Node* root=buildTree(put,index);
    preOrderPrint(root);
    cout<<endl;
    cout<<minTime(root,8);
}
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10