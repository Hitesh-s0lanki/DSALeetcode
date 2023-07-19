#include <iostream>
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
ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode* temp = head;
        while(temp != NULL && temp -> next != NULL){
            ListNode* curr = temp -> next;
            if(temp -> val > curr -> val){
                temp -> next = curr -> next;
                ListNode* prev = NULL;
                ListNode* ptr = head;
                while(ptr != NULL && ptr -> val < curr -> val){
                    prev = ptr;
                    ptr = ptr -> next;
                }
                if(prev == NULL){
                    curr -> next = head;
                    head = curr;
                }
                else{
                    prev -> next = curr;
                    curr -> next = ptr;
                }
            }
            else{
                temp = temp -> next;
            }
        }
        return head;
    }
int main()
{
    // 4,2,1,3
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 3);
    print(head);
    ListNode* ans=insertionSortList(head);
    print(ans);
}