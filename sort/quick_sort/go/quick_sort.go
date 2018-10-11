// Quick Sort in Golang
package main

import (
	"fmt"
	"math/rand"
)

func main() {
	var n int

	fmt.Printf("Enter number of integers : ")
	fmt.Scan(&n)

	arr := make([]float64, n)

	fmt.Printf("\nEnter array elements : ")

	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	quicksort(arr)
	fmt.Printf("Sorted array is ")

	for i := 0; i < n; i++ {
		fmt.Printf("%v ", arr[i])
	}
}

func quicksort(a []float64) []float64 {
	if len(a) < 2 {
		return a
	}

	left, right := 0, len(a)-1

	pivot := rand.Int() % len(a)

	a[pivot], a[right] = a[right], a[pivot]

	for i, _ := range a {
		if a[i] < a[right] {
			a[left], a[i] = a[i], a[left]
			left++
		}
	}

	a[left], a[right] = a[right], a[left]

	quicksort(a[:left])
	quicksort(a[left+1:])

	return a
}
