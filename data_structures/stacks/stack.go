// Author: Austin Crane
package main

import (
	"errors"
	"fmt"
)

// Stack is a simple int stack this gives a simple
// implementation of how stacks are implemented
type Stack struct {
	items []int
}

// Push moves a item onto the top of the stack
func (s *Stack) Push(n int) {
	s.items = append(s.items, n)
}

// Pop gets the top item out of the stack and updates
// the stack to exclude that "popped" item out of the
// stack
func (s *Stack) Pop() (int, error) {
	if s.Size() == 0 {
		return 0, errors.New("end of stack reached")
	}

	var x int
	x, s.items = s.items[0], s.items[1:]
	return x, nil
}

// Size returns count of items in the stack
func (s *Stack) Size() int {
	return len(s.items)
}

// simple helper method to print the popped item
func popAndPrint(stack *Stack) {
	n, err := stack.Pop()
	// there is an error returned if end of stack
	// is reached
	if err != nil {
		fmt.Println(err.Error())
		return
	}

	fmt.Printf("Popped: %d\n", n)
}

func main() {
	// create an empty stack
	s := Stack{}

	// add some items to the top of the stack
	s.Push(1)
	s.Push(2)

	// print stack size: 2
	fmt.Printf("Stack size: %d\n", s.Size())

	// pop off 2
	popAndPrint(&s)
	// pop off 3
	popAndPrint(&s)
	// end of stack is returned
	popAndPrint(&s)
}
