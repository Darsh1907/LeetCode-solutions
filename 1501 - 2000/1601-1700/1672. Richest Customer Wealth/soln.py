class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        wealth=0
        maximum=0
        for i in accounts:
            wealth=sum(i)
            maximum=max(maximum,wealth)
        return maximum   