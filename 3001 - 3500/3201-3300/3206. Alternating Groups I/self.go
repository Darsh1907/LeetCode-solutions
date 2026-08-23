package main

func numberOfAlternatingGroups(colors []int) int {
	resp := 0
	// Middle positions
	for i := range colors {
		if i > 0 && i < len(colors)-1 && colors[i-1] != colors[i] && colors[i] != colors[i+1] {
			resp++
		}
	}
	n := len(colors)
	// Last with first (circular)
	if colors[n-2] != colors[n-1] && colors[n-1] != colors[0] {
		resp++
	}
	// First with last (circular)
	if colors[n-1] != colors[0] && colors[0] != colors[1] {
		resp++
	}
	return resp
}
