#include <iostream>
#include <vector>
using namespace std;

bool checkCondition(string s, string val, int index)
{
    // four dot check
    int dot = 0;

    // 0 - 255
    int number = 0;

    for (int i = 0; i < val.length(); i++)
    {
        if (val[i] == '.')
        {
            if (number > 255)
            {
                return false;
            }
            dot++;
            number = 0;
            if (dot >= 4)
                return false;
        }
        else
        {
            number = number * 10 + (val[i] - '0');
        }
    }

    if (s.length() - (index + 1) < (3 - dot))
    {
        return false;
    }

    return true;
}

void solve(string s, vector<string> &ans, string val, int index)
{
    if (index >= s.length())
    {

        int dot4 = 0;
        for (auto i : val)
        {
            if (i == '.')
            {
                dot4++;
            }
        }
        if (val != "" && dot4 == 3)
        {
            ans.push_back(val);
        }
        return;
    }

    if (checkCondition(s, val, index))
    {
        // Put Dot
        solve(s, ans, val + s[index] + ".", index + 1);

        // Go for next value
        solve(s, ans, val + s[index], index + 1);
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;

    solve(s, ans, "", 0);

    return ans;
}

int main()
{

    vector<string> ans = restoreIpAddresses("0002567");

    for (auto i : ans)
    {
        cout << i << endl;
    }
}