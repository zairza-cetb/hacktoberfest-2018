package binarysearch

import "fmt"

func binarysearch(elements []int, target int) (int, error) {
	low := 0
	high := len(elements) - 1
	var mid int
	for low <= high {
		mid = (low + high) / 2
		if elements[mid] > target {
			high = mid - 1
		} else if elements[mid] < target {
			low = mid + 1
		} else {
			return mid, nil
		}
	}
	return 0, fmt.Errorf("value %d not found", target)
}
