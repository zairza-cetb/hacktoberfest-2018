package stack

import (
	"errors"
)

// Stack is a Golang implementation of a stack
type Stack struct {
	stack []int
}

// EmptyStackError is an error returned when pop is called on an empty stack
const EmptyStackError = "Stack is empty"

func (s *Stack) Pop() (int, error) {
	n := len(s.stack) - 1
	if n == -1 {
		return 0, errors.New(EmptyStackError)
	}
	e := s.stack[n]
	s.stack = s.stack[:n]
	return e, nil
}

func (s *Stack) Push(i int) {
	s.stack = append(s.stack, i)
}

func (s *Stack) Peak() (int, error) {
	n := len(s.stack) - 1
	if n == -1 {
		return 0, errors.New(EmptyStackError)
	}
	return s.stack[n], nil
}

func (s *Stack) isEmpty() bool {
	if len(s.stack) == 0 {
		return true
	}
	return false
}
