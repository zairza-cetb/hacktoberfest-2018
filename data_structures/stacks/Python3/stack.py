#!/usr/bin/python3

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[-1]

    def size(self):
        return len(self.items)

if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)

    print("Size of stack: %d " % stack.size())
    print("Stack.peek: %d" % stack.peek())
    

    print("Stack.pop: %d" % stack.pop())
    print("Stack.pop: %d" % stack.pop())
