class Solution {
    public int findClosestNumber(int[] nums) {
        int diff = Integer.MAX_VALUE;
        int val = 0;
        
        for(int num : nums) {
            if(Math.abs(num) < diff) {
                diff = Math.abs(num);
                val = num;
            }
            else if(Math.abs(num) == diff) {
                if(val < num)
                    val = num;
            }
        }
        
        return val;
    }
}
