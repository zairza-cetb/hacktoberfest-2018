package queue

import "testing"

func TestQueue_Enqueue(t *testing.T) {
	q := NewQueue()
	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)

	if size := q.Size(); size != 3 {
		t.Errorf("invalid size, excepted %d, actual %d", 3, size)
	}
}

func TestQueue_Dequeue(t *testing.T) {
	q := NewQueue()
	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)

	q.Dequeue()
	if size := q.Size(); size != 2 {
		t.Errorf("invalid size, excepted %d, actual %d", 2, size)
	}

	q.Dequeue()
	q.Dequeue()
	if size := q.Size(); size != 0 {
		t.Errorf("invalid size, excepted %d, actual %d", 0, size)
	}
}

func TestQueue_IsEmpty(t *testing.T) {
	q := NewQueue()
	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)

	q.Dequeue()
	q.Dequeue()
	q.Dequeue()

	if !q.IsEmpty() {
		t.Errorf("IsEmpty should return true")
	}
}
