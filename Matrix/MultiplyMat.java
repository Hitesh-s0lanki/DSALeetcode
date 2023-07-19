public class MultiplyMat {

    public int[][] solve(int[][] matA,int[][] matB){
        int row = matA.length; 
        int col = matA[0].length; 
        int[][] ans = new int[row][col];

        for(int i = 0; i < row ; i++){
            for(int j = 0 ; j < col ; j++ ){
                for(int k = 0 ; k < row ; k++){
                    ans[i][j] += matA[i][k] * matB[k][j]; 
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] matA = {{1,2,3},{4,5,6},{7,8,9}};
        int[][] matB = {{1,0,0},{0,1,0},{0,0,1}};

        MultiplyMat m = new MultiplyMat(); 
        int[][] ans = m.solve(matA,matA);
        for (int[] is : ans) {
            for (int i : is) {
                System.out.print(i + "  ");
            }
            System.out.println();
        }
    }
    
}