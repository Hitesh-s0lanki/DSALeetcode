import java.util.ArrayList;
import java.util.List;

public class subset {
    public void solve(int[] nums,List<Integer> temp,List<List<Integer>> ans,int start){
        ans.add(new ArrayList<>(temp));
        for(int i = start ; i<nums.length ;i++){
            temp.add(nums[i]);
            solve(nums, temp, ans, i+1);
            temp.remove(temp.size()-1);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        int index = 0;
        solve(nums,temp,ans,index);

        return ans;
    }
    public static void main(String[] args) {
        int[] nums = {1,2,3};
        subset s = new subset();
       List<List<Integer>> ans  = s.subsets(nums);

       for (List<Integer> list : ans) {
        for (int i : list) {
            System.out.print(i+"  ");
        }
        System.out.println();
       }
    }    
}