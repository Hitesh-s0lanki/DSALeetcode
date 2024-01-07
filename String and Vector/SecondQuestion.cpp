#include<iostream>
#include<vector>
using namespace std;

int minimumSubarray(int n, int x, int y, vector<int> &a){
    int minLen = INT_MAX;
    int negSum = 0, posSum = 0;
    int i = 0;

    for(int j = 0; j < n; j++) {
        if(a[j] < 0)
            negSum += a[j];
        else
            posSum += a[j];

        while(i < j && (negSum <= x && posSum >= y)) {
            minLen = min(minLen, j - i + 1);

            if(a[i] < 0)
                negSum -= a[i];
            else
                posSum -= a[i];

            i++;
        }
    }

    return minLen == INT_MAX ? -1 : minLen;
}

int main(){
    cout<<
}