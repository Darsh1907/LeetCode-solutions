package main

func uniqueOccurrences(arr []int) bool {
	counts := map[int]int{}
	for _, num := range arr {
		counts[num]++
	}
	uniqueCounts := map[int]bool{}
	for _, count := range counts {
		uniqueCounts[count] = true
	}
	return len(uniqueCounts) == len(counts)
}
