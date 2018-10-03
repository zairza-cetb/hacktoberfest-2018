package main

import "fmt"

func insertionSort(arr []float64) []float64 {
	var key float64
	var i int

	for j := 0; j < len(arr); j++ {
		key = arr[j]

		i = j - 1

		for i > 0 && arr[i] > key {
			arr[i+1] = arr[i]
			i--
		}
		arr[i+1] = key
	}

	return arr
}

func main() {
	var n int

	fmt.Printf("Enter number of integers : ")
	fmt.Scan(&n)

	arr := make([]float64, n)

	fmt.Printf("\nEnter array elements : ")

	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	arr = insertionSort(arr)
	fmt.Printf("Sorted array is ")

	for i := 0; i < n; i++ {
		fmt.Printf("%v ", arr[i])
	}
}
