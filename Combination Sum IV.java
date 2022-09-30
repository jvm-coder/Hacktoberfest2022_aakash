/*
377. Combination Sum IV
Medium
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.
Example 1:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:
Input: nums = [9], target = 3
Output: 0
 
Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
 
Follow up: What if negative numbers are allowed in the given array? How does it change the problem? 
What limitation we need to add to the question to allow negative numbers?
*/
/*
Approch 1: Recursion - TLE
*/
class Solution {
    public int combinationSum4(int[] nums, int target) {
        if(target ==0){
            return 1;
        }
        int res=0;
        for(int i=0;i<nums.length;i++){
            if(target>=nums[i]){
                 res += combinationSum4(nums,target-nums[i]);
            }
        }
        return res;
    }
}
/*
Approch 2: Memoization -> Bottom-up-approach
*/
class Solution {
    public static int solve(int[] nums,int target,int dp[]){
        if(dp[target] !=-1){
            return dp[target];
        }
        int res=0;
        for(int i=0;i<nums.length;i++){
            if(target>=nums[i]){
                 res += solve(nums,target-nums[i],dp);
            }
        }
        dp[target] =res;
        return dp[target];
    }
    public int combinationSum4(int[] nums, int target) {
        int dp[] = new int[target+1];
        Arrays.fill(dp,-1);
        dp[0] =1;
        int res = solve(nums,target,dp);
        return res;

    }
}
/*
Tabulation : Top-down Approach
*/
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int dp[] = new int[target+1];
        dp[0] =1;
        for(int i=1;i<target+1;i++){
            for(int num:nums){
                if(i>=num){
                int tar = i-num;
                dp[i] += dp[tar];
                }
            }
        }
        return dp[target];
    }
}
