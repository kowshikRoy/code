package leetcode

import (
	"testing"
)

func TestLargestNumber(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want string
	}{
		{
			name: "Example 1",
			args: args{
				nums: []int{10, 2},
			},
			want: "210",
		},
		{
			name: "Example 2",
			args: args{
				nums: []int{3, 30, 34, 5, 9},
			},
			want: "9534330",
		},
		{
			name: "Example 3",
			args: args{
				nums: []int{1},
			},
			want: "1",
		},
		{
			name: "Example 4",
			args: args{
				nums: []int{0, 0},
			},
			want: "0",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := largestNumber(tt.args.nums); got != tt.want {
				t.Errorf("largestNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}
