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
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
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