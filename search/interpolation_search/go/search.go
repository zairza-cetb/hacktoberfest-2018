package search

func interpolationSearch(l []int, v int) int {
	low := 0
	high := len(l) - 1

	for low <= high && v >= l[low] && v <= l[high] {
		pos := low + (((high - low) / (l[high] - l[low])) * (v - l[low]))

		switch {
		case l[pos] == v:
			return pos
		case l[pos] < v:
			low = pos + 1
		default:
			high = pos - 1
		}
	}
	return -1
}
