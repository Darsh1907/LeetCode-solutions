package main

func sumAndMultiply(n int) int64 {
	var sum int64 = 0
	var newNum int64 = 0
	nonZero := []int{}

	x := n
	for x > 0 {
		digit := x % 10
		if digit > 0 {
			nonZero = append(nonZero, digit)
			sum += int64(digit)
		}
		x /= 10
	}

	// rebuild number in reverse (because digits were collected from LSB → MSB)
	for i := len(nonZero) - 1; i >= 0; i-- {
		newNum = newNum*10 + int64(nonZero[i])
	}

	return newNum * sum
}
