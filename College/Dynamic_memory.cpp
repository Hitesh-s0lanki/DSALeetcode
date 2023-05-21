#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next=NULL;
};
int main(){
    ListNode* head=new ListNode;
    head->val=12;
    cout<<head->val<<endl;
    cout<<head->next<<endl;
}