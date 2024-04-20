class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        intial_length = len(nums)
        for i in range(intial_length):
            nums.append(nums[i])
        return nums