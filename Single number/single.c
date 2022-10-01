int singleNumber(int* nums, int numsSize){
        int j;
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        for(j=0;j<numsSize;j++)
        {
            if(nums[i]==nums[j])
            {
                count++;
                if(count>1)
                {
                    count=0;
                    break;
                }
            }
        }
        if(count==1)
        {
            return nums[i];
        }
        
    }
    return 0;    


}