func isValid(current []int, target []int) bool {
	for i := 0; i < 26; i++ {
		if current[i] < target[i] {
			return false
		}
	}
	return true
}

func validSubstringCount(word1 string, word2 string) int64 {
	n := len(word1)
	target := make([]int, 26)

	// Count required characters from word2
	for i := 0; i < len(word2); i++ {
		target[word2[i]-'a']++
	}w

	var result int64
	current := make([]int, 26)

	left := 0
	for right := 0; right < n; right++ {
		current[word1[right]-'a']++
		for left <= right && isValid(current, target) {
			// All substrings starting at 'left' and ending anywhere from 'right' to 'n-1' are valid.
			result += int64(n - right)
			current[word1[left]-'a']--
			left++
		}
	}

	return result
}