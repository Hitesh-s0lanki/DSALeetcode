#include<iostream>
#include<vector>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};
class TreeNode{
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
void printInoder(TreeNode* root){
    if(root==NULL){
        return;
    }
    printInoder(root->left);
    cout<<root->val<<"\t";
    printInoder(root->right);
}

void print(ListNode* head){
    ListNode* temp=head;
    while(head != NULL){
        cout<<head->val<<"\t";
        head=head->next;
    }
    cout<<endl;
}
void insertAtTail(ListNode* &head,ListNode* &tail,int data){
    ListNode* temp=new ListNode(data);
    if(head == NULL){
        head=temp;
        tail=temp;
    }
    tail->next=temp;
    tail=temp;
}
int lengthOfList(ListNode* head){
    ListNode* temp=head;
    int cnt=0;
    while(head != NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

TreeNode* solve(ListNode* &head,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode* left = solve(head,s,mid-1);

    TreeNode* root=new TreeNode(head->val);
    head=head->next;

    root->right=solve(head,mid+1,e);

    root->left=left;

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int len=lengthOfList(head);
    TreeNode* root=solve(head,0,len-1);

    return root;
}
int main(){
    vector<int> values={ -10,-3,0,5,9};
    ListNode* head=NULL;
    ListNode* tail=NULL;
    for (auto i: values)
        insertAtTail(head,tail,i);
    
    // print(head);

    TreeNode* root=sortedListToBST(head);
    printInoder(root);
}