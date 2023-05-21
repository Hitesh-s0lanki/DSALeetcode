#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(Node *root)
{

    cout << "enter the data of root " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the data in left of " << root->data << endl;
    root->left = buildTree(root->left);

    cout << "enter the data in right of " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}
void preOrderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "\t";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
pair<bool,int> isSumTreeFast(Node* root){

    //base case
    if(root==NULL){
        pair<bool,int> p(true,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
    pair<bool,int> left=isSumTreeFast(root->left);
    pair<bool,int> right=isSumTreeFast(root->right);

    bool leftCheck=left.first;
    bool rightCheck=right.first;

    bool sum=(left.second+right.second)==root->data;
    pair<bool,int> ans;
    if(leftCheck&& rightCheck && sum){
        ans.first=true;
        ans.second=root->data+left.second+right.second;
    }
    else{
        ans.first=false;
    }
    

    return ans ;
}
bool isSumTree(Node* root)
    {
       return isSumTreeFast(root).first;
    }
int main()
{
    // 3 1 -1 -1 2 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    preOrderPrint(root);
    cout << endl;
    if(isSumTree(root)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}