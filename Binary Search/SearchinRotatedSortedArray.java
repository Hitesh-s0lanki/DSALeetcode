public class SearchinRotatedSortedArray {


    public int pivot(int[] nums){
        int s = 0;
        int e = nums.length;

        int mid = s+(e-s)/2;

        while(s < e){
            if(nums[0] < nums[mid]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }

        return mid;
    }  
    public int search(int[] nums, int target) {
        int pivotIndex = pivot(nums);
        return pivotIndex;
    }
    public static void main(String[] args) {
        
        int[] nums = {1,2,1,3,5,6,4}; 
        int target = 0 ; 

        SearchinRotatedSortedArray s =new SearchinRotatedSortedArray();
        System.out.println(s.search(nums, target));
    }
    
}
