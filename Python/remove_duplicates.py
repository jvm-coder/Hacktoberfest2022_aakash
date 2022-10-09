class Solution:
    def removeDuplicates(self, nums: list) -> int:

        for i in range(len(nums)-1, 0, -1):
            if nums[i] == nums[i-1]:
                nums.pop(i)

        return len(nums)


print(Solution().removeDuplicates([1, 1, 2]))
