#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class compare{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second <= b.second;
    }
};

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,int> marking ;
        priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pq;
        int num =0;
        for(auto i:mat){
            for(auto j:i){
                if(j==1){
                    marking[num]++;
                }
            }
            if(pq.size() < k){
                pq.push(make_pair(num,marking[num]));
            }
            else if(pq.top().second > marking[num]){
                pq.pop();
                pq.push(make_pair(num,marking[num]));
            }
            num++;
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
int main(){
    vector<vector<int>> mat ={{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};

    int k = 3;
    vector<int> ans = kWeakestRows(mat,k);
    for(auto i:ans){
        cout<<i<<"\t";
    }
}