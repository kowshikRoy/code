package leetcode

import (
	"reflect"
	"testing"
)

func TestUncommonFromSentences(t *testing.T) {
	type args struct {
		s1 string
		s2 string
	}
	tests := []struct {
		name string
		args args
		want []string
	}{
		{
			name: "Example 1",
			args: args{
				s1: "this apple is sweet",
				s2: "this apple is sour",
			},
			want: []string{"sweet", "sour"},
		},
		{
			name: "Example 2",
			args: args{
				s1: "apple apple",
				s2: "banana",
			},
			want: []string{"banana"},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := uncommonFromSentences(tt.args.s1, tt.args.s2); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("uncommonFromSentences() = %v, want %v", got, tt.want)
			}
		})
	}
}
