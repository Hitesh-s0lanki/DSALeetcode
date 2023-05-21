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
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *temp = head;
    ListNode *store = head;
    ListNode *ans = NULL;
    ListNode *tail = NULL;
    while (temp != NULL)
    {
        bool check = true;
        int curr = temp->val;
        cout<<curr<<endl;
        if (temp->next != NULL)
        {
            store = temp->next;
        }
        while (temp->next!=NULL&&store != NULL && curr == store->val)
        {
            check = false;
            temp = store;
            store = store->next;
        }
        if (check)
        {
            insertAtTail(ans, tail, curr);
        }
        temp=temp->next;
    }
    print(ans);
}
int main()
{
    // 1,2,3,3,4,4,5
    // 1,1,1,2,3
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    print(head);
    deleteDuplicates(head);
}