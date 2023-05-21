#include<iostream>
#include<map>
using namespace std;
string decodeMessage(string key, string message) {
        map<char,char> store;
        char ch='a';
        int i=0;
        while(i<key.length()){
            if(key[i]!=32){
                if(store[key[i]]>='a'&&store[key[i]]<='z'){
                    
                }
                else
                store[key[i]]=ch++;
            }
            i++;
        }
        string ans="";
        i=0;
        while(i<message.length()){
            if(message[i]!=32)
            ans.push_back(store[message[i]]);
            else
            ans.push_back(32);

            i++;
        }
        return ans;
    }
int main(){
    string key="the quick brown fox jumps over the lazy dog";
    string message="vkbs bs t suepuv";
    cout<<decodeMessage(key,message);
}