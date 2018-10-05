package queue

import "sync"

type Queue struct {
	items []interface{}
	lock  sync.Mutex
}

func NewQueue() *Queue {
	return &Queue{
		items: make([]interface{}, 0),
	}
}

func (q *Queue) Enqueue(i interface{}) {
	q.lock.Lock()
	q.items = append(q.items, i)
	q.lock.Unlock()
}

func (q *Queue) Dequeue() interface{} {
	q.lock.Lock()
	i := q.items[0]
	q.items = q.items[1:]
	q.lock.Unlock()
	return i
}

func (q *Queue) Front() interface{} {
	q.lock.Lock()
	i := q.items[0]
	q.lock.Unlock()
	return i
}

func (q *Queue) IsEmpty() bool {
	return len(q.items) == 0
}

func (q *Queue) Size() int {
	return len(q.items)
}
