public class Stack<T> {

	int size;
	int top = -1;
	T[] stack;

	// generic Stack inisialisation
	@SuppressWarnings("unchecked") // ignores compiler warnings
	public Stack(int size) {
		this.size = size;
		this.stack = (T[]) new Object[size];
	}

	// addin an element at the top of the stack
	public void push(T num) {
		stack[++top] = num;
		System.out.println("Pushed " + num);
	}

	// removing the top element
	public void pop() {
		System.out.println("Poped " + stack[top--]);
	}

	// addressing the top element
	public T top() {
		System.out.println("Top element is " + stack[top]);
		return stack[top];
	}

	// checking if stack is empty
	public boolean isEmpty() {
		if (top == -1) {
			System.out.println("Stack is empty");
			return true;
		}
		System.out.println("Stack is not empty");
		return false;
	}

	// checking if stack is full
	public boolean isFull() {
		if (top == size - 1) {
			System.out.println("Stack is full");
			return true;
		}
		System.out.println("Stack is not full");
		return false;
	}
}
