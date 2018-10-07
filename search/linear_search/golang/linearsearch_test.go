package linearsearch

import (
	"fmt"
	"testing"
)

var arr = []int{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5}

type testTable struct {
	target, expected int
	err              error
}

func TestSuccessfulLinearSearch0(t *testing.T) {
	tArray := arr
	tTable := testTable{
		0,
		5,
		nil,
	}
	evaluateTest(t, tArray, tTable)
}

func TestSuccessfulLinearSearch1(t *testing.T) {
	tArray := arr
	tTable := testTable{
		-5,
		0,
		nil,
	}
	evaluateTest(t, tArray, tTable)
}

func TestSuccessfulLinearSearch2(t *testing.T) {
	tArray := arr
	tTable := testTable{
		5,
		10,
		nil,
	}
	evaluateTest(t, tArray, tTable)
}

func TestFailedLinearSearch0(t *testing.T) {
	tArray := arr
	target := 7
	tTable := testTable{
		target,
		-1,
		fmt.Errorf(ErrorMessage, target),
	}

	evaluateTest(t, tArray, tTable)
}

func TestFailedLinearSearch1(t *testing.T) {
	tArray := arr
	target := -6
	tTable := testTable{
		target,
		-1,
		fmt.Errorf(ErrorMessage, target),
	}

	evaluateTest(t, tArray, tTable)
}

func evaluateTest(t *testing.T, tArray []int, tTable testTable) {
	got, err := linearsearch(tArray, tTable.target)
	if got != tTable.expected || (err != nil && err.Error() != tTable.err.Error()) {
		t.Errorf("linearsearch(%v, %v): expected (%v, %v), actual (%v, %v)", tArray, tTable.target, tTable.expected, tTable.err, got, err)
	}
}
