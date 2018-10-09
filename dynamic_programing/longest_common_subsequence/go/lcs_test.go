package lcs

import "testing"

func TestLCSLength(t *testing.T) {
	length := LCSLength("klapper", "takpapp")
	expectedLength := 4 // kapp
	if length != expectedLength {
		t.Errorf("Expected %d but got %d", expectedLength, length)
	}

	length = LCSLength("kappr", "takpapp")
	if length != expectedLength {
		t.Errorf("Expected %d but got %d", expectedLength, length)
	}
}
