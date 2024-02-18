class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        nums = list(set(nums))
        nums.sort()
        count = 1
        maximum = 1
        for i in range(len(nums)-1):
            if((nums[i]+1) == nums[i+1]):
                count = count + 1
            else:
                if count>maximum:
                    maximum = count
                count = 1
        if count>maximum:
            maximum = count
        return maximum