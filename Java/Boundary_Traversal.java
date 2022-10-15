import java.util.* ;
import java.io.*; 
/************************************************************
    Following is the Binary Tree node structure:
    
   class TreeNode {
	    int data;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int data) {
		    this.data = data;
		    this.left = null;
		    this.right = null;
	    }
    }
************************************************************/

import java.util.ArrayList;

public class Solution {
    public static boolean isLeaf(TreeNode node){
        if(node.left==null && node.right==null){
            return true;
        }
        return false;
        }
    public static void leftboundary(TreeNode node,ArrayList<Integer> res){
        TreeNode curr = node.left;
        while(curr!=null){
            if(!isLeaf(curr)) res.add(curr.data);
            if(curr.left!=null) curr =curr.left;
            else curr = curr.right;
        }
    }
    public static void rightboundary(TreeNode node,ArrayList<Integer> res){
        ArrayList<Integer> temp = new ArrayList<>();
        TreeNode curr = node.right;
        while(curr!=null){
            if(!isLeaf(curr)) temp.add(curr.data);
            if(curr.right!=null) curr =curr.right;
            else curr = curr.left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.add(temp.get(i));
        }
    }
    public static void addleaf(TreeNode node,ArrayList<Integer> res){
        if(isLeaf(node)){
            res.add(node.data);
            return;
        }
        if(node.left!=null)  addleaf(node.left,res);
        if(node.right!=null)  addleaf(node.right,res);
    }

	public static  ArrayList<Integer> traverseBoundary(TreeNode root){
		// Write your code here.
        ArrayList<Integer> res = new ArrayList<>();
        if(root==null) return res;
        if(!isLeaf(root)) res.add(root.data);
        leftboundary(root,res);
        addleaf(root,res);
        rightboundary(root,res);
        return res;
	}
}
