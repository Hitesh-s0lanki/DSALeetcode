#include<iostream>
#include<vector>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{

    cout << "enter the data for root node" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data in left node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data in Right node of " << data << endl;
    root->right = buildTree(root->right);
}
void preOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"\t";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void visitLeft(node* root,vector<int> &ans){
    if(root==NULL||(root->left==NULL&&root->right==NULL))
        return;
    ans.push_back(root->data);
    if(root->left){
        visitLeft(root->left,ans);
    }
    else if(root->right){
        visitLeft(root->right,ans);
    }
}
void visitLeaf(node* root,vector<int> &ans){
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL)
        ans.push_back(root->data);

        visitLeaf(root->left,ans);
        visitLeaf(root->right,ans);
}
void visitRight(node* root,vector<int> &ans){
    if(root==NULL||(root->left==NULL&&root->right==NULL))
        return;
    if(root->right){
        visitRight(root->right,ans);
    }
    else if(root->left){
        visitRight(root->left,ans);
    }
    ans.push_back(root->data);
}
vector <int> boundary(node *root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    ans.push_back(root->data);
    visitLeft(root->left,ans);
    //left tree leaf
    visitLeaf(root->left,ans);
    //right tree leaf
    visitLeaf(root->right,ans);
    visitRight(root->right,ans);
    return ans;
}
int main(){
    //1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
    node* root=buildTree(root);
    preOrderTraversal(root);
    cout<<endl;
    vector<int> ans=boundary(root);
    for(auto i:ans){
        cout<<i<<"\t";
    }
}