package main

import "strconv"

func sumAndMultiply(n int) int64 {
	s := strconv.Itoa(n)
	sum, d := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == '0' {
			continue
		}
		x := int(s[i] - '0')
		d = d*10 + x
		sum += x
	}
	return int64(sum * d)
}
