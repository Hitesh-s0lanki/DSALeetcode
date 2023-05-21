#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> s;
    s.push(-1);
    int i = nums2.size();
    while (i >= 0)
    {
        s.push(nums2[i--]);
    }
    i = 0;
    vector<int> ans;
    while (i < nums1.size())
    {
        stack<int> temp = s;
        while (temp.top() != nums1[i])
        {
            temp.pop();
        }
        temp.pop();
        if (temp.top() > nums1[i] || temp.top() == -1)
            ans.push_back(temp.top());

        else
            ans.push_back(-1);
        i++;
    }
    return ans;
}
int main()
{
    // nums1 = [4,1,2], nums2 = [1,3,4,2]
    vector<int> num1 = {2, 4};
    vector<int> num2 = {1, 2, 3, 4};
    vector<int> ans = nextGreaterElement(num1, num2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\t";
    }
}