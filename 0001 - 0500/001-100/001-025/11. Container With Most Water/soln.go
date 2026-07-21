package main

func maxArea(height []int) int {
	i := 0
	j := len(height) - 1
	res := 0
	for i < j {
		curr := (j - i) * min(height[i], height[j])
		res = max(res, curr)
		if height[i] <= height[j] {
			i++
		} else {
			j--
		}
	}
	return res
}
