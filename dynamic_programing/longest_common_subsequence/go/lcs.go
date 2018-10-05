package lcs

func LCSLength(x string, y string) int {
	C := make([][]int, len(x) + 1)
	for i := range C {
		C[i] = make([]int, len(y) + 1)
	}
	for i := 1; i <= len(x); i++ {
		for j := 1; j <= len(y); j++ {
			if x[i-1] == y[j-1] {
				C[i][j] = C[i-1][j-1] + 1
			} else {
				C[i][j] = max(C[i][j-1], C[i-1][j])
			}
		}
	}
	return C[len(x)][len(y)]
}

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
