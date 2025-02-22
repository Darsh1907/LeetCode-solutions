package main

func construct2DArray(original []int, rows int, cols int) [][]int {
	size := len(original)
	if size != rows*cols {
		return nil
	}
	// Create a 2D slice with 'rows' rows
	ans := make([][]int, rows)
	// Initialize each row to an empty slisce
	for i := 0; i < rows; i++ {
		ans[i] = make([]int, 0, cols) // Allocate space for 'cols' elements in each row
	}
	// Populate the 2D array with values from the original slice
	itr := 0
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			ans[i] = append(ans[i], original[itr])
			itr++
		}
	}
	return ans
}
