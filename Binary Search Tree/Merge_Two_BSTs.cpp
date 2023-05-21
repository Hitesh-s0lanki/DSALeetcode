#include<iostream>
#include<vector>
using namespace std;

template<typename T> class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void print(TreeNode<int>* root){
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->val<<"\t";
    print(root->right);
}
TreeNode<int>* insertInBST(TreeNode<int>* root,int d){
    //Base case 
    if(root==NULL){
        root=new TreeNode<int>(d);
        return root;
    }
    else if(root->val > d ){
        root->left=insertInBST(root->left,d);
    }
    else{
        root->right=insertInBST(root->right,d);
    }
        return root;
}

TreeNode<int>* buildBST(TreeNode<int>* root){
    int data;
    cin>>data;

    while(data != -1){
        root=insertInBST(root,data);
        cin>>data;
    }
    return root;
}

int getLength(TreeNode<int>* root){
    int cnt=0;
    while(root != NULL){
        root=root->right;
        cnt++;
    }
    return cnt;
}

void CreateLinkedList(TreeNode<int> *root, TreeNode<int> *&head){

    if(root == NULL){
        return;
    }

    CreateLinkedList(root->right,head);

    root->right=head;

    if(head != NULL)
        head->left=root;
    
    head = root;

    CreateLinkedList(root->left,head);

}

TreeNode<int>* mergeList(TreeNode<int>* head1,TreeNode<int>* head2){

    TreeNode<int>* head=NULL;
    TreeNode<int>* tail=NULL;

    while(head1 != NULL && head2 != NULL){
        if( head1 -> val < head2 ->val){
            if(head == NULL){
                head = head1;
            }
            else{
                tail -> right = head1;
            }
            tail = head1;
            head1 = head1 -> right;
        }
        else{
            if(head == NULL){
                head = head2;
            }
            else{
                tail -> right = head2;
            }
            tail = head2;
            head2 = head2 -> right;
        }
    }

    while(head1 != NULL){
        if(head == NULL){
                head = head1;
            }
            else{
                tail -> right = head1;
            }
            tail = head1;
            head1 = head1 -> right;
    }

    while (head2 != NULL){
        if(head == NULL){
                head = head2;
            }
            else{
                tail -> right = head2;
            }
            tail = head2;
            head2 = head2 -> right;
    }

    return head;
}

TreeNode<int>* CreateBinarySearchTree(TreeNode<int>* &head,int s ,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;

    TreeNode<int>* left= CreateBinarySearchTree(head,s,mid-1);

    TreeNode<int>* root=new TreeNode<int>(head -> val);
    head = head -> right;

    root -> right = CreateBinarySearchTree(head,mid+1,e);

    root->left = left;

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    TreeNode<int> *head1=NULL,*head2=NULL;
    CreateLinkedList(root1,head1);
    CreateLinkedList(root2,head2);

    TreeNode<int>* real= mergeList(head1,head2);

    int len=getLength(real);
    TreeNode<int>* ans= CreateBinarySearchTree(real,0,len-1);    

    return ans;
}

int main(){
    // 2 1 3 -1 4 -1
    cout<<"Enter the data in BST"<<endl;
    TreeNode<int>* root1=NULL;
    root1=buildBST(root1);
    TreeNode<int>* root2=NULL;
    root2=buildBST(root2);
    print(root1);
    cout<<endl;
    print(root2);
    cout<<endl;
    TreeNode<int>* ans = mergeBST(root1,root2);
    print(ans);
}