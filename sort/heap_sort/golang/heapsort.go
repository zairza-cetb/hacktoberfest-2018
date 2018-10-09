package main

import (
	"fmt"
	"math"
)

func parent(node int) int {
	return int(math.Floor((float64(node) - 1.0) / 2.0))
}

func siftDown(a []int, start, end int) {
	root := start

	for 2*root+1 <= end {
		child := 2*root + 1
		swap := root

		if a[swap] < a[child] {
			swap = child
		}

		if child+1 <= end && a[swap] < a[child+1] {
			swap = child + 1
		}

		if swap == root {
			break
		} else {
			a[root], a[swap] = a[swap], a[root]
			root = swap
		}
	}
}

func heapify(a []int, count int) {
	start := parent(count - 1)

	for start >= 0 {
		siftDown(a, start, count-1)
		start = start - 1
	}
}

// HeapSort sorts an array using the heap sort algorithm
func HeapSort(a []int) []int {
	n := len(a)

	heapify(a, n)

	for end := n - 1; end > 0; {
		a[end], a[0] = a[0], a[end]
		end = end - 1
		siftDown(a, 0, end)
	}

	return a
}

func main() {
	a := []int{-1, 4, 9, 0, -10, 5, 894, 3493, -54958, 4}
	fmt.Println(a)
	fmt.Println("Sorted array: ", HeapSort(a))
}
