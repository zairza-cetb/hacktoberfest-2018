package main

import "fmt"

var dp [][]int

// LCS return the longest common subsequence between strings a and b
func LCS(a, b string) int {
	n := len(a)
	m := len(b)

	dp = make([][]int, n+1)

	for i := 0; i <= n; i++ {
		dp[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			if i == 0 || j == 0 {
				dp[i][j] = 0
			} else if a[i-1] == b[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = dp[i][j-1]
				if dp[i-1][j] > dp[i][j-1] {
					dp[i][j] = dp[i-1][j]
				}
			}
		}
	}

	return dp[n][m]
}

func main() {
	a := []string{"AGGTAB", "ABCDGH"}
	b := []string{"GXTXAYB", "ADH"}

	for i := range a {
		fmt.Printf("LCS between '%v' and '%v' is: %v\n", a[i], b[i], LCS(a[i], b[i]))
	}
}
