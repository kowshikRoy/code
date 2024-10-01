package leetcode

import (
	"sort"
	"strconv"
	"strings"
)

func largestNumber(nums []int) string {
	nums_str := make([]string, len(nums))
	for i := 0; i < len(nums); i++ {
		nums_str[i] = strconv.Itoa(nums[i])
	}
	sort.Slice(nums_str, func(i, j int) bool {
		return nums_str[i]+nums_str[j] > nums_str[j]+nums_str[i]
	})
	out := strings.TrimLeft(strings.Join(nums_str, ""), "0")
	if out == "" {
		return "0"
	}
	return out
}
