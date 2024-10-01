package leetcode

import "strconv"

func isPalindrome(x int) bool {
	s1 := strconv.Itoa(x)
	s2 := make([]byte, len(s1))
	for i, j := len(s1)-1, 0; i >= 0; i-- {
		s2[j] = s1[i]
		j++
	}
	return s1 == string(s2)

}
