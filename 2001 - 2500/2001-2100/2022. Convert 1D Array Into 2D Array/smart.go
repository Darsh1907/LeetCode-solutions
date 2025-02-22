package main

func construct2DArray(original []int, m int, n int) [][]int {
	if len(original) != m*n {
		return nil
	}
	res := make([][]int, m)
	for i, num := range original {
		row := i / n
		pos := i % n
		if pos == 0 {
			res[row] = make([]int, n)
		}
		res[row][pos] = num
	}
	return res
}
