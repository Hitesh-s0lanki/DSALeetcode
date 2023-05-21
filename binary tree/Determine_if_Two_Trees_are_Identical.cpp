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
bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL&&r2==NULL){
            return true;
        }
        if(r1==NULL&&r2!=NULL){
            return false;
        }
        if(r1!=NULL&&r2==NULL){
            return false;
        }
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        
        if(r1->data==r2->data&&left&&right){
            return true;
        }
        return false;
    }
int main()
{
    // 1 10 5 -1 -1 -1 39 -1 -1
    Node *root1 = NULL;
    root1 = buildTree(root1);
    preOrderPrint(root1);
    cout << endl;
    Node *root2 = NULL;
    root2 = buildTree(root2);
    preOrderPrint(root2);
    cout << endl;
    cout<<isIdentical(root1,root2);
}