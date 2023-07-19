#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isSort(vector<int>& arr1,int n){

    int i = 1 ;

    while(i<n){
        if(arr1[i-1] >= arr1 [i])
            break;
        i++;
    }
    return i == n; 
}

int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    int cnt =0; 
       for(int i = 0 ; i < arr1.size() && !isSort(arr1,arr1.size()) ;i++){
            sort(arr2.begin(),arr2.end());
            for(auto j:arr2){
                if(i == 0 && arr1[i] > j){
                    swap(arr1[i],j);
                    cnt++;
                    break;
                }
                else if(i != 0 && j != arr1[i]  && arr1[i - 1] < j){
                        swap(arr1[i],j);
                        cnt++;
                        break;
                }
            }
            if(!isSort(arr1,i+1)){
                return -1;
            }
       } 
    return cnt;
}

int main(){
    // vector<int> arr1 = {1,5,3,6,7}, arr2 = {4,3,1};
    // vector<int> arr1 = {1,5,3,6,7}, arr2 = {1,6,3,3};
    // vector<int> arr1 = {0,11,6,1,4,3}, arr2 = {5,4,11,10,1,0};
    // vector<int> arr1 = {1,5,3,6,7}, arr2 = {1,3,2,4};
    vector<int> arr1 = {5,16,19,2,1,12,7,14,5,16}, arr2 = {6,17,4,3,6,13,4,3,18,17,16,7,14,1,16};
    
    cout<<makeArrayIncreasing(arr1,arr2)<<endl;

    for(auto i: arr1)
        cout<<i<<"\t";

}