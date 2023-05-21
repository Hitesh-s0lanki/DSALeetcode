#include <iostream>
#include <vector>
#include<stack>
#include<algorithm>
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
void reverseNode(ListNode* &head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* store;
    while(curr!=NULL){
        store=curr->next;
        curr->next=prev;
        prev=curr;
        curr=store;
    }
    head=prev;
}
vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s;
        s.push(0);
        reverseNode(head);
        vector<int> a;
        while(head!=NULL){
            while(s.top()!=0&&s.top()<head->val){
                s.pop();
            }
            a.push_back(s.top());
            s.push(head->val);
            head=head->next;
        }
       reverse(a.begin(),a.end());
        return a;
    }
int main()
{

    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 5);
    print(head);
    vector<int> ans=nextLargerNodes(head);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\t";
    }
}