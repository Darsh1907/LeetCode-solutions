package main

import (
	"strconv"
)

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

func main() {
	// Example usage
	n := 11 // Binary: 1011, Hamming weight: 3
	result := hammingWeight(n)
	println("Hamming weight of", n, "is", result) // Output: Hamming weight of 11 is 3
}
