#include<iostream>
#include<queue>
#include<climits>
#include<map>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int ans = INT_MIN;

    char lastRemove = ' ';
    map<char,bool> visited;
    queue<char> q;

    for(auto ch:s){
        if(!visited[ch]){
            visited[ch] = true;
            q.push(ch);
            int size = q.size();
            ans = max(ans, size);
        }else{
            while(!q.empty() && q.front() != ch){
                visited[q.front()] = false;
                q.pop();
            }
            q.pop();
            q.push(ch);
        }
    }
    return ans;
}
int main(){
    string a = "aab";
    cout<<lengthOfLongestSubstring(a);
}