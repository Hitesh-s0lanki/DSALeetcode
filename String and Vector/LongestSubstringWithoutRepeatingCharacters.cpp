#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void solve(string s,int &maxi){
    if(s.length() == 0)
        return;

    
    int cnt = 0;

    map<char,bool> visited;

    for(auto i:s){
        if(visited[i])
            break;
        cnt++;
        visited[i] = true;
    }
    maxi = max(maxi,cnt);

    solve(s.substr(1),maxi);
}

int lengthOfLongestSubstring(string s) {
        int maxi = 0;  
        solve(s,maxi);

    return maxi;
}

int main(){
    string s = "";
    cout<<lengthOfLongestSubstring(s);
}