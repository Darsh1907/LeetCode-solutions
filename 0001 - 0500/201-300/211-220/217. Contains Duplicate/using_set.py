class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hdx = set()
        for i in nums:
            if i in hdx:
                return True
            else:
                hdx.add(i)