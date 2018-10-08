package main

import (
	"reflect"
	"testing"
)

var testTable = []struct {
	id       int
	a        []int
	cmp      CmpFunc
	expected []int
}{
	{
		1,
		[]int{10, 9, 3, -10, 0, -1, 4, 3, 5},
		func(x, y int) bool { return x < y },
		[]int{-10, -1, 0, 3, 3, 4, 5, 9, 10},
	},
	{
		2,
		[]int{10, 9, 3, -10, 0, -1, 4, 3, 5},
		func(x, y int) bool { return x > y },
		[]int{10, 9, 5, 4, 3, 3, 0, -1, -10},
	},
}

func TestSelectionSort(t *testing.T) {
	for _, tc := range testTable {
		got := SelectionSort(tc.a, tc.cmp)

		if !reflect.DeepEqual(got, tc.expected) {
			t.Errorf("FAILED case #%v: expected '%v' but got '%v'", tc.id, tc.expected, got)
		}
	}
}
