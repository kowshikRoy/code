package leetcode

import (
	"strings"
)

func uncommonFromSentences(s1 string, s2 string) []string {
	l1 := strings.Split(s1, " ")
	l2 := strings.Split(s2, " ")
	wordCount := make(map[string]int)
	for _, word := range l1 {
		wordCount[word]++
	}
	for _, word := range l2 {
		wordCount[word]++
	}
	var result []string
	for word, count := range wordCount {
		if count == 1 {
			result = append(result, word)
		}
	}
	return result
}
