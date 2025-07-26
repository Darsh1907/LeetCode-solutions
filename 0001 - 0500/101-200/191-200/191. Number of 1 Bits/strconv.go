func hammingWeight(n int) int {
	res := 0
	binary := strconv.FormatInt(int64(n), 2)
	for _, char := range binary {
		if char == '1' {
			res++
		}
	}
	return res
}