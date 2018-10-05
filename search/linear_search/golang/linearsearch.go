package linearsearch

import (
	"fmt"
)

// ErrorMessage shares the expected error message
const ErrorMessage = "Array does not contain %d"

func linearsearch(elements []int, target int) (int, error) {
	for i, v := range elements {
		if v == target {
			fmt.Println("Pass")
			return i, nil
		}
	}
	fmt.Println("Failed")
	return -1, fmt.Errorf(ErrorMessage, target)
}
