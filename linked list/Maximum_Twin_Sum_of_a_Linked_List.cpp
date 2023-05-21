#include<iostream>
#include<algorithm>
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
int length(ListNode* head){
    int cnt=0;
    while(head!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt;
}
int pairSum(ListNode* head) {
    int maxi=0;
    stack<int> s;
    int n=length(head);
    ListNode* temp=head;
    while(temp!=NULL){
        s.push(temp->val);
        temp=temp->next;
    }
    while(n!=n/2){
        maxi=max(maxi,head->val+s.top());
        head=head->next;
        s.pop();
        n--;
    }

    return maxi;
}
int main(){
    ListNode* head=NULL;
    ListNode* tail=NULL;
    // 5,4,2,1
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,1);
    print(head);
    cout<<"the maximum twin sum is "<<pairSum(head);
}