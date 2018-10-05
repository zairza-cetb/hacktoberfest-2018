package search

import (
	"testing"
)

func Test_interpolationSearch(t *testing.T) {
	tests := []struct {
		name string
		l    []int
		key  int
		want int
	}{
		{
			name: "Slice with the mentioned key",
			l:    []int{1, 2, 3, 4, 5},
			key:  4,
			want: 3,
		},
		{
			name: "Slice without the mentioned key",
			l:    []int{1, 2, 3, 4, 5},
			key:  1337,
			want: -1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := interpolationSearch(tt.l, tt.key); got != tt.want {
				t.Errorf("interpolationSearch() = %v, want %v", got, tt.want)
			}
		})
	}
}
