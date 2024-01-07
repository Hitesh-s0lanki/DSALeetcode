#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// create sub <Mat
vector<vector<float>> createSub(vector<vector<float>> val, int n, int row, int col)
{
    vector<vector<float>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i == row)
            continue;

        vector<float> temp;
        for (int j = 0; j < n; j++)
        {
            if (j != col)
            {
                temp.push_back(val[i][j]);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}

float determinate(vector<vector<float>> val, int n)
{

    if (n <= 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return val[0][0];
    }

    float ans = 0;

    for (int i = 0; i < n; i++)
    {
        vector<vector<float>> nextDeterminate;
        for (int j = 1; j < n; j++)
        {
            vector<float> temp;
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

vector<vector<float>> squareMat(int n)
{
    vector<vector<float>> ans;
    float cnt = 1;

    for (int i = 0; i < n; i++)
    {
        vector<float> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(cnt++);
        }
        ans.push_back(temp);
    }

    return ans;
}

void print(vector<vector<float>> val)
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

vector<vector<float>> transpose(vector<vector<float>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<float>> ans;
    for (int i = 0; i < m; i++)
    {
        vector<float> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(matrix[j][i]);
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<float>> inverse(vector<vector<float>> val, int n)
{
    int det = determinate(val, n);

    vector<vector<float>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<float> temp;
        for (int j = 0; j < n; j++)
        {
            vector<vector<float>> sub = createSub(val, n, i, j);
            temp.push_back((pow(-1, i + j) * determinate(sub, sub.size())) / det);
        }
        ans.push_back(temp);
    }

    return transpose(ans);
}

int main()
{
    // vector<vector<int>> val = squareMat(2);
    // vector<vector<int>> val = {{2, 1}, {7, 4}};
    vector<vector<float>> val = {{1, 2, 0}, {3, 1, 4}, {5, 6, 7}};
    print(val);

    // vector<vector<int>> sub = createSub(val, val.size(), 1, 0);
    // print(sub);
    // cout << sub.size();

    cout << endl;
    cout << "The Inverse of Matrix is : " << endl;
    cout << endl;

    vector<vector<float>> ans = inverse(val, val.size());
    print(ans);
}