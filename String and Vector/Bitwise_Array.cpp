#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool solve(vector<int> value, int n, int x, int y, int cnt)
{
    if (cnt >= n)
    {
        int orNumber = 0;
        int andNumber = INT_MAX;
        for (auto i : value)
        {
            orNumber = orNumber | i;
            andNumber = andNumber & i;
        }

        if (orNumber == x && y == andNumber)
        {
            return true;
        }
    }
    else
    {
        for (int i = y; i <= x; i++)
        {
            value.push_back(i);
            if (solve(value, n, x, y, cnt + 1))
                return true;
            value.pop_back();
        }
    }

    return false;
}

int isPossible(int n, int x, int y)
{

    if (solve({}, n, x, y, 0))
        return 1;

    return 0;
}

int main()
{
    cout << isPossible(2, 7, 5);
}