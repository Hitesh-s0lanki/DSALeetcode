// Moore’s Voting Algorithm

public class MajorityElement {
    public static int majorityElement(int[] nums) {
        int cnt = 0;
        int element = -1;

        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                element = nums[i];
                cnt = 1;
            } else if (element == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }

        // check if the element voted is high
        int checkCnt = 0;
        for (int i = 0; i < n; i++) {
            if (element == nums[i])
                checkCnt++;
        }

        if (checkCnt > n / 2)
            return element;

        return -1;
    }

    public static void main(String[] args) {
        System.out.println(majorityElement(new int[] { 2, 2, 1, 1, 1, 2, 2 }));
    }
}
