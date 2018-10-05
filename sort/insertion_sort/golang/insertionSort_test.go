package insertionSort

import (
	"testing"
)

func TestSuccessfulInsertionSort0(t *testing.T) {
	input := []int{5, 2, -2, 3, 4, -4, -3, -1, 1, 0, -5}
	expected := []int{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5}
	evaluateTest(t, input, expected)
}

func TestSuccessfulInsertionSort1(t *testing.T) {
	input := []int{-3, -2, -1, 2, 2, 0, 1, 2, 3}
	expected := []int{-3, -2, -1, 0, 1, 2, 2, 2, 3}
	evaluateTest(t, input, expected)
}

func evaluateTest(t *testing.T, input []int, expected []int) {
	got := InsertionSort(input)
	if !Equal(got, expected) {
		t.Errorf("linearsearch(%v): expected (%v), actual (%v)", input, expected, got)
	}
}

// Equal tells whether arr1 and arr2 contain the same elements.
// A nil argument is equivalent to an empty slice.
func Equal(arr1, arr2 []int) bool {
	if len(arr1) != len(arr2) {
		return false
	}
	for i, v := range arr1 {
		if v != arr2[i] {
			return false
		}
	}
	return true
}
