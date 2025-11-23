package main

import (
	"fmt"
)

func maxSumDivThree(nums []int) int {
	n := len(nums)
	const NEG_INF = -1 << 60

	// dp[i][r] = maximum sum achievable using first i elements with sum%3 == r
	dp := make([][3]int, n+1)
	// initialize with NEG_INF
	for i := 0; i <= n; i++ {
		for r := 0; r < 3; r++ {
			dp[i][r] = NEG_INF
		}
	}
	dp[0][0] = 0

	for i := 1; i <= n; i++ {
		x := nums[i-1]
		xr := ((x % 3) + 3) % 3 // safe remainder for any x

		// skip option: carry forward previous remainders
		for r := 0; r < 3; r++ {
			dp[i][r] = dp[i-1][r]
		}

		// take option: transition from any reachable previous remainder
		for prevR := 0; prevR < 3; prevR++ {
			if dp[i-1][prevR] == NEG_INF {
				continue
			}
			newR := (prevR + xr) % 3
			sum := dp[i-1][prevR] + x
			if sum > dp[i][newR] {
				dp[i][newR] = sum
			}
		}
	}

	return dp[n][0]
}

func main() {
	fmt.Println(maxSumDivThree([]int{3, 6, 5, 1, 8})) // example
}
