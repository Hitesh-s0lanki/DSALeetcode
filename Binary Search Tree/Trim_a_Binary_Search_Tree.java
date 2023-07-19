public class Trim_a_Binary_Search_Tree {
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val){
            this.val = val;
            this.left = null;
            this.right = null;
        }
    }
    public TreeNode insertInBST(TreeNode root,int i){
        if(root == null){
            TreeNode temp = new TreeNode(i);
            return temp;
        }
        if(i > root.val){
            root.right = insertInBST(root.right, i); 
        }
        else{
            root.left = insertInBST(root.left, i); 
        }
        return root;
    }
    public TreeNode buildTree(int[] arr){
        TreeNode root = null;
        for (int i : arr) {
            root = insertInBST(root,i);
        }
        return root;
    }
    public void printInoder(TreeNode root){
        if(root == null)
            return;
            System.out.print(root.val+"  ");
            printInoder(root.left);
        printInoder(root.right);
    }
    class Solution {
        public TreeNode deleteNode(TreeNode root,int val){
            if(root == null){
                return null;
            }
            if(root.val == val){
                //No Children
                if(root.left == null && root.right == null){
                    return null;
                }
                //one child
                if(root.left != null && root.right == null){
                    return root.left;
                }
                if(root.left == null && root.right != null){
                    return root.right;
                }
                //Both Children There
                TreeNode temp = root.right;
                while(temp.left != null){
                    temp = temp.left;
                }
                root.val = temp.val;
                root.right = deleteNode(root.right, temp.val);
            }
            else if(root.val > val){
                root.left = deleteNode(root.left, val);
            }
            else{
                root.right = deleteNode(root.right, val);
            }
            return root;
        }

    }
        public TreeNode trimBST(TreeNode root, int low, int high) {
            if(root == null){
                return null;
            }
            if(root.val < low){
                root = root.right;
                root = trimBST(root,low,high);
            }
            else if(root.val > high){
                root = root.left;
                root = trimBST(root,low,high);
            }
            if(root != null && root.left != null )
                root.left = trimBST(root.left, low, high);
            if(root != null && root.right != null)
                root.right = trimBST(root.right, low, high);
    
            return root;
        }
    public static void main(String[] args) {
        Trim_a_Binary_Search_Tree b = new Trim_a_Binary_Search_Tree();
        int[] arr = {41,37,44,24,39,42,48,1,35,38,40,43,46,49,0,2,30,36,45,47,4,29,32,3,9,26,31,34,7,11,25,27,33,6,8,10,16,28,5,15,19,12,18,20,13,17,22,14,21,23};
        TreeNode root = b.buildTree(arr);
        
        root = b.trimBST(root, 25, 55);
        b.printInoder(root);
    }
    
}