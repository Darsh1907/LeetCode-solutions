class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        size = len(flowerbed)
        count = 0
        i = 0
        while i < size:
            if flowerbed[i] == 0:
                if i==size-1 or flowerbed[i+1]==0: # We dont need to check with the previous position because we always skip positions exactly right of 1 by doing i=i+2
                    count += 1
                    i += 2  # Skip to the next available spot after planting
                else:
                    i += 1  # Skip to the next spot (occupied, so can't plant)
            else:
                i += 2  # Skip to the next unoccupied spot
        return count >= n