#include<iostream>
#include<stack>
using namespace std;
int findMinimumCost(string str) {
    if(str.size()%2!=0){
        return -1;
    }
  stack<char> ch;
  int i=0;
  while(i<str.length()){
    if(!ch.empty()&&str[i]=='}'&&ch.top()=='{'){
        ch.pop();
    }
    else{
        ch.push(str[i]);
    }
    i++;
  }
  int a=0,b=0;
  while(!ch.empty()){
    if(ch.top()=='{'){
        a++;
    }
    else{
        b++;
    }
    ch.pop();
  }
  int count=((a+1)/2)+((b+1)/2);
  return count;
}
int main(){
    string s="{{{}";
    cout<<findMinimumCost(s);
}