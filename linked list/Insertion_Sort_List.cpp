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
ListNode *insertionSortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *temp1 = head;
    ListNode *store = head->next;
    while (temp1->next != NULL)
    {
        ListNode *temp1 = store->next;
        store->next = temp1->next;
        ListNode *prev = NULL;
        ListNode *curr = head;
        store=temp1->next;
        while (curr != NULL)
        {
            if (curr->val > temp1->val)
            {
                break;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        if (prev==NULL)
        {
            temp1->next = curr;
            // store=store->next;print(store);
            head=temp1;
            print(head);
        }
        // else
        // {
        //     ListNode* storestore=store;
        //     store=store->next;
        //     prev->next = storestore;
        //     storestore->next = curr;
        // }
        // print(store);
    }
    return head;
}
int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    print(head);
    ListNode* ans=insertionSortList(head);
    print(ans);
}