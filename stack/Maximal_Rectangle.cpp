#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> prevElement(vector<char> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i]-'0';
        while (s.top() != -1 && arr[s.top()]-'0' >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextElement(vector<char> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i]-'0';
        while (s.top() != -1 && arr[s.top()]-'0' >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestAreaCal(vector<char> arr, int n)
{
    vector<int> prev(n);
    prev = prevElement(arr, n);

    vector<int> next(n);
    next = nextElement(arr, n);

    int area = INT_MIN;
    int i = 0;
    while (i < n)
    {
        int l = arr[i]-'0';
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
int maximalRectangle(vector<vector<char>>& M) {
    int n=M.size();
    int m=M[0].size();
        for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
                M[i][j] =M[i][j] + (M[i - 1][j]-'0');
            else
                M[i][j] = '0';
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
int main(){
    vector<vector<char>> a={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalRectangle(a);
}