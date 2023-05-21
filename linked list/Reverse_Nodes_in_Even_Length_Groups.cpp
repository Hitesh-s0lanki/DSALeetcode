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
void reverse(ListNode *&head, ListNode *&tail)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *store = NULL;
    tail = head;
    while (curr != NULL)
    {
        store = curr->next;
        curr->next = prev;
        prev = curr;
        curr = store;
    }
    head = prev;
}
int lengthOfNode(ListNode *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}
ListNode *reverseEvenLengthGroups(ListNode *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    int len = lengthOfNode(head);
    int count = 1;
    ListNode *temp = head;
    ListNode *store = head;
    while (temp != NULL)
    {
        if (count % 2 == 0 && len >= count)
        {
            ListNode *part = NULL;
            ListNode *partTail = NULL;
            int i = count;
            while (temp != NULL && i)
            {
                insertAtTail(part, partTail, temp->val);
                temp = temp->next;
                i--;
            }
            reverse(part, partTail);
            //    print(part);
            store->next = part;
            partTail->next = temp;
            store = partTail;
        }
        else if (len % 2 == 0 && count != 1 && len < count)
        {
            ListNode *part = NULL;
            ListNode *partTail = NULL;
            int i = len;
            while (temp != NULL && i)
            {
                insertAtTail(part, partTail, temp->val);
                temp = temp->next;
                i--;
            }
            reverse(part, partTail);
            print(part);
            store->next = part;
            partTail->next = temp;
        }
        else
        {
            int i = count;
            while (temp != NULL && i)
            {
                store = temp;
                temp = temp->next;
                i--;
            }
        }
        len = len - count;
        count++;
    }
    return head;
}
int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 8);
    insertAtTail(head, tail, 6);

    print(head);
    ListNode *ans = reverseEvenLengthGroups(head);
    print(ans);
}