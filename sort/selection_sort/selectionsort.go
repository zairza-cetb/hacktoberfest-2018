package main

import "fmt"

// CmpFunc compare function type
type CmpFunc func(a, b int) bool

// SelectionSort sorts an array using the selection sort algorithm and cmp as compare function
func SelectionSort(a []int, cmp CmpFunc) []int {
	n := len(a)
	for i := 0; i < n; i++ {
		minIndex := i
		for j := i + 1; j < n; j++ {
			if cmp(a[j], a[minIndex]) {
				minIndex = j
			}
		}
		a[i], a[minIndex] = a[minIndex], a[i]
	}
	return a
}

func main() {
	a := []int{10, 9, 3, -10, 0, -1, 4, 3, 5}
	fmt.Println(SelectionSort(a, func(x, y int) bool { return x < y }))
	fmt.Println(SelectionSort(a, func(x, y int) bool { return x > y }))
}
