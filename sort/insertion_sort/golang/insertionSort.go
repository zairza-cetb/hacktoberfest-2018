package insertionSort

func InsertionSort(arr []int) []int {
	for i := 1; i < len(arr); i++ {
		n := arr[i]
		j := i
		for j > 0 && arr[j-1] > n {
			arr[j] = arr[j-1]
			j--
		}
		arr[j] = n
	}
	return arr
}
