# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        if not root:
            return
        else:
            return self.checksum(root,targetSum,[],[])
        
    def checksum(self,root,target,curr,arr):
        if not root:
            return []
        else:
            if root.val==target and root.left==root.right==None:
                curr.append(root.val)
                arr.append(curr)
                
            self.checksum(root.left,target-root.val,curr+[root.val],arr)
            self.checksum(root.right,target-root.val,curr+[root.val],arr)
            return arr
                
        