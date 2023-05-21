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
pair<bool,int> isBalancedFast(Node* root){
    if(root==NULL){
        pair<bool,int> p(true,0);
        return p;
    }

    pair<bool,int> left=isBalancedFast(root->left);
    pair<bool,int> right=isBalancedFast(root->right);

    bool leftcheck = left.first;
    bool rightcheck = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    if(leftcheck && rightcheck && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    ans.second=max(left.second,right.second)+1;

    return ans;
}
bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
}
int main()
{
    // 1 10 5 -1 -1 -1 39 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    preOrderPrint(root);
    cout << endl;
    if(isBalanced(root)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}