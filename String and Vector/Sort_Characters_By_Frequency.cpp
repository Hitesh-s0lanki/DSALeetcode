#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string frequencySort(string s) {
    sort(s.begin(),s.end());
    vector<string> store;
        int i=0;
        while(i<s.length()){
            string temp;
            int j=i;
            while(s[j]==s[i]){
                temp.push_back(s[i++]);
            }
            store.push_back(temp);
        }
        //sort
        for(int i=0;i<store.size()-1;i++){
            for(int j=i+1;j<store.size();j++){
                if(store[i].length()<store[j].length()){
                    swap(store[i],store[j]);
                }
            }
        }
        //for the string
        i=0;
        string ans="";
        while(i<store.size()){
            ans+=store[i++];
        }
        return ans;
    }
int main(){
    string s="trre";
    cout<<frequencySort(s);
    // "eeeeoollvtdc"
}
