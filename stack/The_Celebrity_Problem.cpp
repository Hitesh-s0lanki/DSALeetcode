#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
bool knows(vector<vector<int> >& M,int a,int b,int n){
    if(M[a][b]==1)
    return true;
    else
    return false;
}
int celebrity(vector<vector<int> >& M, int n){
       stack<int> s;
       int i=0;
       while(i<n){
        s.push(i);
        i++;
       }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int remain=s.top();
        bool rowCheck=true;

        for(int i=0;i<M[remain].size();i++){
            if(M[remain][i]==1)
            rowCheck=false;
        }

        bool colCheck=false;
        int colcount=0;
        for(int i=0;i<M.size();i++){
            if(M[i][remain]==1)
            colcount++;
        }
        if(colcount==M.size()-1){
            colCheck=true;
        }
        if(colCheck&&rowCheck){
            return remain;
        }
        return -1;
    }
int main(){
    vector<vector<int>> a={{0,1,0},{0,0,0}, {0,1,0}};
    cout<<celebrity(a,a.size());
}