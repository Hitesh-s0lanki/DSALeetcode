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
void insertAtHead(ListNode* &head,int d){
    ListNode* temp=new ListNode(d);
    if(head==NULL){
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}
  ListNode* removeNodes(ListNode* head) {
        stack<int> s;
        ListNode* ans=NULL;
        while(head!=NULL){
            while(!s.empty()&&s.top()<head->val){
                s.pop();
            }
            s.push(head->val);
            head=head->next;
        }
        while(!s.empty()){
            insertAtHead(ans,s.top());
            s.pop();
        }
        return ans;
    }
int main(){
    // 5,2,13,3,8
    ListNode* head=NULL;
    ListNode* tail=NULL;
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,13);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,8);
    print(head);
    ListNode* ans=removeNodes(head);
    print(ans);
}