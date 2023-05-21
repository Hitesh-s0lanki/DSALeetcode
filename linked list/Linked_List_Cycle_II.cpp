#include<iostream>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insertAtTail(ListNode *&head, ListNode *&tail, int d)
{
    ListNode *temp = new ListNode(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}
void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}
ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL||fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            if(fast==slow){
                break;
            }
        }
        if(fast!=slow){
            return NULL;
        }
        fast=head;
        while(fast==slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
int main(){
    ListNode* head=NULL;
    ListNode* tail=NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    ListNode* store=tail;
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);
    tail->next=store;
    // print(head);
    ListNode* ans=detectCycle(head);
    cout<<ans->val<<endl;
}