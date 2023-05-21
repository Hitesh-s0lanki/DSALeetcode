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
void insertAtTail(ListNode* &head,ListNode* &tail,int d){
    ListNode* temp=new ListNode(d);
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
ListNode* reverse(ListNode* head,ListNode* &tail){
    ListNode* prev=NULL;
    ListNode*curr=head;
    ListNode* store=NULL;
    while(curr!=NULL){
        store=curr->next;
        curr->next=prev;
        prev=curr;
        curr=store;
    }
    tail=head;
    return prev;
}
  ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        int lefter=left;
        ListNode* temp=head;
        ListNode* part=NULL;
        ListNode* partTail=NULL;
        ListNode* store=temp;
        while(left>1){
            store=temp;
            temp=temp->next;
            left--;
            right--;
        }
        while(temp!=NULL&&right){
            insertAtTail(part,partTail,temp->val);
            temp=temp->next;
            right--;
        }
        //  print(part);
        part=reverse(part,partTail);
        print(part);
         if(lefter==1){
            head=part;
        }
        else{
        store->next=part;
        }
        partTail->next=temp;
        return head;

    }
int main(){
    ListNode * head=NULL;
    ListNode* tail=NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    // insertAtTail(head,tail,3);
    // insertAtTail(head,tail,4);
    // insertAtTail(head,tail,5);
    // print(head);
    ListNode* ans=reverseBetween(head,1,2);
    print(ans);
}