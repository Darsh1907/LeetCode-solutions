func maximumHappinessSum(happiness []int, k int) int64 {
	slices.Sort(happiness)
	slices.Reverse(happiness)
	var res int64 = 0
	for i := 0; i < k; i++ {
		curr := happiness[i] - i
		if curr < 0 {
			curr = 0
		}
		res += int64(curr)
	}
	return res
}