package main

import "fmt"

func maxSum(nums []int) int {
	uniquePosNums := map[int]int{}
	for _, num := range nums {
		if num > 0 && uniquePosNums[num] == 0 {
			uniquePosNums[num] = 1
		}
	}
	res := 0
	if len(uniquePosNums) == 0 {
		return getMaxNum(nums)
	}
	for k := range uniquePosNums {
		res += k
	}
	return res
}

func getMaxNum(nums []int) int {
	maxNum := -100 // minimum possible number is -100
	for _, num := range nums {
		if num > maxNum {
			maxNum = num
		}
	}
	return maxNum
}

func main() {
	nums := []int{1, 2, 2, 3, -1, 4}
	fmt.Println(maxSum(nums))
}
