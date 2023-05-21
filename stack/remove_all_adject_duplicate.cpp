#include <iostream>
#include <stack>
#include <cstring>
#include<algorithm>
using namespace std;
string removeDuplicates(string s)
{
    stack<char> ch;
    int i = 0;
    while (i < s.length())
    {
        if (!ch.empty())
        {
            if (ch.top() == s[i])
            {
                ch.pop();
            }
            else
            {
                ch.push(s[i]);
            }
        }
        else
        {
            ch.push(s[i]);
        }
        i++;
    }
    string ans = "";
    while (!ch.empty())
    {
        ans.push_back(ch.top());
        ch.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    string s = "abbaca";
    cout << removeDuplicates(s);
}