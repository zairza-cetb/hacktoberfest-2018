package main

import "testing"

var testTable = []struct {
	a, b     string
	expected int
}{
	{"AGGTAB", "GXTXAYB", 4},
	{"ABCDGH", "ADH", 3},
	{"AAAAA", "BBBBB", 0},
}

func TestLCS(t *testing.T) {
	for _, tc := range testTable {
		got := LCS(tc.a, tc.b)

		if got != tc.expected {
			t.Errorf("LCS(%v, %v) expected to be '%v' but got '%v'", tc.a, tc.b, tc.expected, got)
		}
	}
}
