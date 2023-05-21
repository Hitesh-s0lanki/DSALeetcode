#include<iostream>
#include<vector>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode* child;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
        this->child=NULL;
    }
};
void insertAtTail(ListNode* &head,ListNode* &tail,int d){
    ListNode* temp=new ListNode(d);
    if(head==NULL){
        head=temp;
        tail=temp;
        return ;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"\t";
        head=head->next;
    }
    cout<<endl;
}
void insertAtChild(ListNode *&head,int d){
    ListNode* temp=new ListNode(d);
    head->child=temp;
}
void flattenFast(ListNode* head,vector<int> &v){
    if(head==NULL)
    return ;

    v.push_back(head->val);
    flattenFast(head->child,v);
    flattenFast(head->next,v);
}
ListNode* flatten(ListNode* head) {
        vector<int> ans;
        flattenFast(head,ans);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<"\t";
        }
        cout<<endl;
        return head;
    }
int main(){
    ListNode* head=NULL;
    ListNode* tail=NULL;
    
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    ListNode* child=tail;
    insertAtChild(child,7);
    insertAtTail(head,child,8);
    ListNode* child2=child->child;
    insertAtChild(child2,11);
    insertAtTail(head,child2,12);
    insertAtTail(head,child,9);
    insertAtTail(head,child,10);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);

    print(head);

    flatten(head);
}