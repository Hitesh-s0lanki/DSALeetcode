public class implement {
    public static boolean binarySearch(int[] arr,int start,int end,int data){
        if(start > end){
            return false;
        }
        int mid = (start + end)/2;
        if(arr[mid] == data){
            return true;
        }
        if(arr[mid] < data){
            return binarySearch(arr, mid+1, end, data);
        }
        return binarySearch(arr, start, mid - 1, data);
    }
    public static void main(String[] args) {
        
        int[] arr = {1,2,3,4,5,6};

        System.out.println(binarySearch(arr, 0, 5, 4));

    }
}