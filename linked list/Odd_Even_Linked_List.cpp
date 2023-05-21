#include<iostream>
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
void insertAtTail(ListNode* &head,ListNode* &tail,int val){
    ListNode* temp=new ListNode(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"\t";
        head=head->next;
    }
    cout<<endl;
}
ListNode* oddEvenList(ListNode* head) {
        ListNode* anshead=NULL;
        ListNode* anstail=NULL;
        ListNode* temp=head;
        while(temp!=NULL&&temp->next!=NULL){
            ListNode* curr=temp->next;
            if(curr==NULL)
            break;
            insertAtTail(anshead,anstail,curr->val);
            temp->next=curr->next;
            if(temp->next!=NULL)
            temp=temp->next;
        }
        temp->next=anshead;
        return head;
    }
int main(){
    // ,2,3,4,5,6,7,8
    ListNode* head=NULL;
    ListNode* tail=NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,8);
    print(head);
    ListNode* ans=oddEvenList(head);
    print(ans);
}