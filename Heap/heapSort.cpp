#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& nums,int n,int i){
    int index=i;
    int leftIndex = 2*i + 1;
    int rightIndex = 2*i + 2;

    if(leftIndex < n && nums[index] < nums[leftIndex]){
        index = leftIndex;
    }
    if(rightIndex < n && nums[index] < nums[rightIndex]){
        index = rightIndex;
    }

    if(index != i){
        swap(nums[index],nums[i]);
        heapify(nums,n,index);
    }
    return;
}


void heapSort(vector<int> &nums){
    int size = nums.size()-1;

    while(size > 0){
        //swap
        swap(nums[0],nums[size--]);

        //heapify
        heapify(nums,size+1,0);
    }

}

vector<int> sortArray(vector<int>& nums) {
    //heap Sort 
    //First Step heapify the vector
    int n = nums.size();
         for(int i = n/2 -1 ;i >= 0 ; i--){
            heapify(nums,n,i);
         }   
    heapSort(nums);

    return nums;
}
int main(){
    vector<int> nums={5,2,3,1,0,4};
    nums=sortArray(nums);
    for(auto i: nums){
        cout<<i<<"\t";
    }
}