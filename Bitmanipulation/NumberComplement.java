public class NumberComplement {
    public int findComplement(int num) {
        int a = num;
        int val = 0;
        
        while(a != 0){
            val = val<<1|1;
            a = a>>1;
        }
        int ans = ~num & val;
        return ans;
    }

    public static void main(String[] args) {
        
        // Bitwise operator
        NumberComplement n = new NumberComplement();
        System.out.println(n.findComplement(4));
    }
    
}