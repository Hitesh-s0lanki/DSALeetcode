#include<iostream>
#include<vector>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next =NULL;
    }
};
void print(ListNode* head){
    ListNode* temp=head;
    while(temp != NULL){
        cout<<temp->val<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtTail(ListNode* &head,ListNode* &tail,int val){
    ListNode* temp=new ListNode(val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

ListNode* solve(ListNode* first,ListNode* second){
    if(first == NULL){
        return second;
    }
    ListNode* head = NULL;
    ListNode* tail = NULL;

    while(first != NULL && second != NULL){
        if(first -> val > second -> val){
            if(head == NULL){
                head = second;
            }
            else{
                tail -> next = second;
            }
            tail = second;
            second = second-> next;
        }
        else{
            if(head == NULL){
                head = first;
            }
            else{
                tail -> next = first;
            }
            tail = first;
            first = first-> next;
        }
    }
    while(first != NULL){
        tail -> next = first;
        tail = first;
        first = first -> next;
    }
    while(second != NULL){
        tail -> next = second;
        tail = second;
        second = second -> next;
    }
    return head;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size=lists.size();
    if(size==0)
        return NULL;

    ListNode* ans = NULL;
    for(int i=0;i<size;i++){
        if(lists[i] != NULL)
            ans = solve(ans,lists[i]);
    }
    return ans;
}


int main(){
    // [[1,4,5],[1,3,4],[2,6]]
    ListNode* head1 =NULL;
    ListNode* tail1 =NULL;
    ListNode* head2 =NULL;
    ListNode* tail2 =NULL;
    ListNode* head3 =NULL;
    ListNode* tail3 =NULL;
    vector<int> value={1,4,5};
    for(auto i : value)
        insertAtTail(head1,tail1,i);
    print(head1);
    value={1,3,4};
    for(auto i : value)
        insertAtTail(head2,tail2,i);
    print(head2);
    value={2,6};
    for(auto i : value)
        insertAtTail(head3,tail3,i);
    print(head3);

    vector<ListNode*> lists={head1,head2,head3};

    ListNode* ans= mergeKLists(lists);
    print(ans);
}