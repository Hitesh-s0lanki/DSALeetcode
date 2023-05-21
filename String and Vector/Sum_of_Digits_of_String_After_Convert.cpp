#include <iostream>
#include <map>
using namespace std;
int getLucky(string s, int k)
{
    map<char, int> store;
    int count = 1;
    for (char i = 'a'; i <= 'z'; i++)
    {
        store[i] = count++;
    }
    int i = 0;
    int sum = 0;
    while (i < s.length())
    {
     int num=store[s[i]];
        while ( num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        i++;
    }
    while (k != 1)
    {
        int last = 0;
        int value = sum;
        while (value != 0)
        {
            last += value % 10;
            value /= 10;
        }
        sum = last;
        k--;
    }
    return sum;
}
int main()
{
    string s = "iiii";
    int n = 1;
    cout << getLucky(s, n);
}