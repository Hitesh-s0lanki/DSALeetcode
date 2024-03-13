#include <iostream>
#include <vector>
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

void insertAtTail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *temp = new ListNode(val);

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        tail->next = temp;
    }
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

vector<int> convertListNodeToArray(ListNode *head)
{
    vector<int> val;

    while (head != NULL)
    {
        val.push_back(head->val);
    }

    return val;
}

void subArray(vector<vector<int>> ans, vector<int> nums, vector<int> temp, int i)
{

    if (i >= nums.size())
    {
        ans.push_back()
    }
    // exclude
    subArray(ans, nums, temp, i + 1);

    // include
    temp.push_back(nums[i]);
    subArray(ans, nums, temp, i + 1);
}

ListNode *removeZeroSumSublists(ListNode *head)
{
}

int main()
{

    ListNode *head = NULL;
    ListNode *tail = NULL;

    vector<int> nums = {1, 2, -3, 3, 1};

    for (int num : nums)
    {
        insertAtTail(head, tail, num);
    }

    print(head);

    return 0;
}