#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> val, int cnt, int counter)
{

    if (counter >= cnt)
    {
        ans.push_back(val);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        val.push_back(i);
        solve(ans, val, cnt, counter + 1);
        val.pop_back();
    }
}

int digitCombination(int cnt)
{
    vector<vector<int>> ans;

    solve(ans, {}, cnt, 0);

    return ans.size();
}

int main()
{
    cout << digitCombination(2);
}