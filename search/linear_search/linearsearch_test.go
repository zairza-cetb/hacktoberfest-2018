package main

import (
	"fmt"
	"testing"
)

var (
	items = []int{-1, 0, 2, 4, 6, 3, 5, 7, 8, -4}

	testTable = []struct {
		item, expected int
		err            error
	}{
		{-1, 0, nil},
		{1000, -1, fmt.Errorf("Item '%v' not found", 1000)},
		{7, 7, nil},
	}
)

func TestLinearSearch(t *testing.T) {
	for _, testCase := range testTable {
		got, err := LinearSearch(items, testCase.item)

		if got != testCase.expected || (err != nil && err.Error() != testCase.err.Error()) {
			t.Errorf("LinearSearch(%v, %v): expected (%v, %v), actual (%v, %v)", items, testCase.item, testCase.expected, testCase.err, got, err)
		}
	}
}
