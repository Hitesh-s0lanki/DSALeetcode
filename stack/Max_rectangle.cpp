#include <iostream>
#include <vector>
#include <climits>
#include <vector>
#include <stack>
using namespace std;
vector<int> prevElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestAreaCal(int arr[], int n)
{
    vector<int> prev(n);
    prev = prevElement(arr, n);

    vector<int> next(n);
    next = nextElement(arr, n);

    int area = INT_MIN;
    int i = 0;
    while (i < n)
    {
        int l = arr[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
        i++;
    }
    return area;
}
int maxArea(int M[4][4], int n, int m)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
                M[i][j] += M[i - 1][j];
            else
                M[i][j] = 0;
        }
    }
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int newArea = largestAreaCal(M[i], m);
        area = max(area, newArea);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
    return area;
}
int main()
{
    int matrix[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 1}};
    cout << maxArea(matrix, 4, 4);
}