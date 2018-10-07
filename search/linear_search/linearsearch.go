package main

import "fmt"

// LinearSearch search for an item in a list in linear time
func LinearSearch(items []int, item int) (int, error) {
	for i, _ := range items {
		if items[i] == item {
			return i, nil
		}
	}
	return -1, fmt.Errorf("Item '%v' not found", item)
}

func main() {
	items := []int{-1, 0, 2, 4, 6, 3, 5, 7, 8, -4}
	inputs := []int{-1, 3, 300}

	for _, in := range inputs {
		index, err := LinearSearch(items, in)
		if err != nil {
			fmt.Println(err)
		} else {
			fmt.Println(index)
		}
	}
}
