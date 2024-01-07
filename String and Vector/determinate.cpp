#include <iostream>
#include <vector>
using namespace std;

int determinate(vector<vector<int>> val, int n)
{

    if (n <= 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return val[0][0];
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> nextDeterminate;
        for (int j = 1; j < n; j++)
        {
            vector<int> temp;
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    temp.push_back(val[j][k]);
                }
            }
            nextDeterminate.push_back(temp);
        }
        if (i % 2 == 0)
        {
            ans = ans + val[0][i] * determinate(nextDeterminate, n - 1);
        }
        else
        {
            ans = ans - val[0][i] * determinate(nextDeterminate, n - 1);
        }
    }

    return ans;
}

vector<vector<int>> squareMat(int n)
{
    vector<vector<int>> ans;
    int cnt = 1;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(cnt++);
        }
        ans.push_back(temp);
    }

    return ans;
}

void print(vector<vector<int>> val)
{
    for (auto i : val)
    {
        for (auto j : i)
        {
            cout << j << "\t";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> val = squareMat(3);
    // vector<vector<int>> val = {{1, 0, 2, -1},
    //                            {3, 0, 0, 5},
    //                            {2, 1, 4, -3},
    //                            {1, 0, 5, 0}};
    print(val);
    cout << determinate(val, val.size());
}