package main

import "slices"

func minDifference(nums []int) int {
	n := len(nums)
	// if n is less than equal to 3, we can convert every number to 0 and hence the ans = 0.
	// if n==4 we can convert 3 numbers into the 4th number, hence again the ans = 0.
	if n <= 4 {
		return 0
	}
	slices.Sort(nums)
	// Essentially we can do only 4 things:
	// 1. Remove all 3 from left
	// 2. Remove 2 from left and 1 from right;
	// 3. Remove 1 from left and 2 from right
	// 4. Remove all 3 from right
	// Return the minimum of these values
	range1 := nums[n-4] - nums[0]
	range2 := nums[n-3] - nums[1]
	range3 := nums[n-2] - nums[2]
	range4 := nums[n-1] - nums[3]
	return min(range1, range2, range3, range4)
}
