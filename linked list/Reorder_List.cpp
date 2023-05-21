#include<iostream>
#include<stack>
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
int middleCount(ListNode* head){
    int cnt=0;
    while(head!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt/2;
}
void reorderList(ListNode* head) {
        int cnt=middleCount(head);
        stack<ListNode* > s;
        ListNode* temp=head;
        while(temp!=NULL){
            s.push(temp);
            temp=temp->next;
        }
        temp=head;
        ListNode* store=NULL;
        while(cnt){
            store=temp->next;
            temp->next=s.top();
            temp=temp->next;
            temp->next=store;
            temp=temp->next;
            s.pop();
            cnt--;
        }
        temp->next=NULL;
    }
int main(){
    ListNode* head=NULL;
    ListNode* tail=NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    print(head);
    reorderList(head);
    print(head);
}