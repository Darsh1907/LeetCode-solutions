class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        size = len(flowerbed)
        count = 0
        i = 0
        while i<size:
            if flowerbed[i] == 0:
                if (i==0 or flowerbed[i-1]==0) and (i==size-1 or flowerbed[i+1]==0):
                    count += 1
                    flowerbed[i] = 1
            i = i+1
        return count >= n