package SearchInBST;

public class Solution {
    public static void main(String[] args) {
        TreeNode left = new TreeNode(2);
        TreeNode rightRR = new TreeNode(84);
        TreeNode rightR= new TreeNode(63,null,rightRR);
        TreeNode right = new TreeNode(22,null,rightR);
        TreeNode root = new TreeNode(18,left , right);
        printNodes(searchBST(root,63));
    }
    private static TreeNode searchBST(TreeNode root, int val){
        if(root == null){
            return null;
        }
        TreeNode temp = null;
        if (root.val < val) {
            temp = dfs(root.right, val);

        } else {
            temp =dfs(root.left, val);
        }
        return temp;
    }
    private static TreeNode dfs(TreeNode root, int val){
        if(root == null){
            return null;
        }
        TreeNode temp = null;
        if(root.val == val){
            return root; 
        }
        else if(root.val < val){
            temp = dfs(root.right, val);
        }
        else{
            temp =dfs(root.left, val);
        }
        return temp;        

    }
    private static void printNodes(TreeNode root){
        if(root == null){
            return;
        }
        System.out.print(root.val + "->");
        printNodes(root.left);
        printNodes(root.right);
    }

}
