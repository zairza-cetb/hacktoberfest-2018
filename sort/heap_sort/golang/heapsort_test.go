package main

import (
	"reflect"
	"testing"
)

var testTable = []struct {
	id       int
	a        []int
	expected []int
}{
	{
		1,
		[]int{10, 9, 3, -10, 0, -1, 4, 3, 5},
		[]int{-10, -1, 0, 3, 3, 4, 5, 9, 10},
	},
	{
		2,
		[]int{-1, 4, 9, 0, -10, 5, 894, 3493, -54958, 4},
		[]int{-54958, -10, -1, 0, 4, 4, 5, 9, 894, 3493},
	},
}

func TestSelectionSort(t *testing.T) {
	for _, tc := range testTable {
		got := HeapSort(tc.a)

		if !reflect.DeepEqual(got, tc.expected) {
			t.Errorf("FAILED case #%v: expected '%v' but got '%v'", tc.id, tc.expected, got)
		}
	}
}
