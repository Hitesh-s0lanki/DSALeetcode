#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insertAtTail(ListNode *&head, ListNode *&tail, int d){
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
void print(ListNode *head){
    while (head != NULL)
    {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode* ,vector<ListNode*> , compare> pq;  

        //inserting all first Node
        for(auto i : lists){
            pq.push(i);
        }

        ListNode* head = NULL; 
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            if(head == NULL){
                head = tail = temp;
            }
            else{
                tail -> next =temp;
                tail = temp;
            }


            //geting the other nodes
            if(temp -> next != NULL){
                ListNode* tmp = temp->next;
                pq.push(tmp);
            }
        }
    return head;
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