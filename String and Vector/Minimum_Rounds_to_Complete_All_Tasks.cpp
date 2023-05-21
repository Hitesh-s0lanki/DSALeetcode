#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimumRounds(vector<int>& tasks) {
    sort(tasks.begin(),tasks.end());
    int i=tasks.size()-1;
    int round=0;
    while(i>=0){
        int count=0;
        int j=i;
        while(i>=0&&tasks[i]==tasks[j]){
            i--;
            count++;
        }
        if(count==1){
            return -1;
        }
        else if(count!=0){
            round+=count/3;
            if(count%3<3&&count%3!=0)
            round++;
        }
    }
    return round;
}
int main(){
    vector<int> a={7,7,7,7,7,7,7};
    cout<<minimumRounds(a);
}