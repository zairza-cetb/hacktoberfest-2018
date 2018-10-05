package stack

import (
	"testing"
)

type testTable struct {
	s        Stack
	expected int
	err      error
}

func TestPush(t *testing.T) {
	s := Stack{}
	s.Push(1)
	if s.isEmpty() {
		t.Errorf("Push did not add integer to stack")
	}
}

func TestPeakOnEmptyStack(t *testing.T) {
	s := Stack{}
	i, err := s.Peak()
	if err == nil || i != 0 {
		t.Errorf("Empty StackPop: expected (%v, %v), actual (%v, %v)", 0, EmptyStackError, i, err)
	}
}

func TestPeak0(t *testing.T) {
	s := Stack{[]int{1}}
	i, err := s.Peak()
	if err != nil || i != 1 || s.isEmpty() != false {
		t.Errorf("Pop on stack{[]int{1}} Failed expected (%v, %v, %v), actual (%v, %v, %v)", 1, nil, false, i, err, s.isEmpty())
	}
}

func TestPeak1(t *testing.T) {
	s := Stack{[]int{1, 2}}
	i, err := s.Peak()
	if err != nil || i != 2 || s.isEmpty() != false {
		t.Errorf("Pop on stack{[]int{1, 2}} Failed expected (%v, %v, %v), actual (%v, %v, %v)", 1, nil, false, i, err, s.isEmpty())
	}
}

func TestPopOnEmptyStack(t *testing.T) {
	s := Stack{}
	i, err := s.Pop()
	if err == nil || i != 0 {
		t.Errorf("Empty StackPop: expected (%v, %v), actual (%v, %v)", 0, EmptyStackError, i, err)
	}
}
func TestPop(t *testing.T) {
	s := Stack{[]int{1, 2}}
	i, err := s.Pop()
	if err != nil || i != 2 || s.isEmpty() != false {
		t.Errorf("Pop on stack{[]int{1, 2}} Failed expected (%v, %v, %v), actual (%v, %v, %v)", 1, nil, false, i, err, s.isEmpty())
	}
	i, err = s.Pop()
	if err != nil || i != 1 || s.isEmpty() != true {
		t.Errorf("Pop on stack{[]int{1}} Failed: expected (%v, %v, %v), actual (%v, %v, %v)", 1, nil, true, i, err, s.isEmpty())
	}
}
