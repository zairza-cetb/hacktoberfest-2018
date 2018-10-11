package main

import (
	"container/heap"
	"fmt"
)

// INF constant
const INF = 1000000000

// Edge structure
type Edge struct {
	To     int
	Weight int
}

// Graph structure
type Graph struct {
	Size  int
	Nodes [][]*Edge
}

// Item priority item
type Item struct {
	Priority int
	Index    int
}

// PriorityQueue priority queue type
type PriorityQueue []*Item

// Len lenght of the queue
func (pq PriorityQueue) Len() int { return len(pq) }

// Less compare function
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].Priority < pq[j].Priority
}

// Swap swap function
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

// Push push to the queue
func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

// Pop pop from the queue
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

// Dijkstra calculates the shortes distance from source to target
func (g *Graph) Dijkstra(s, t int) int {
	dist := make([]int, g.Size, g.Size)
	seen := make([]bool, g.Size, g.Size)
	pq := &PriorityQueue{}

	for i := 0; i < g.Size; i++ {
		dist[i] = INF
		seen[i] = false
	}

	dist[s] = 0
	heap.Init(pq)
	heap.Push(pq, &Item{0, s})

	for len(*pq) > 0 {
		item := heap.Pop(pq).(*Item)

		from := item.Index

		if seen[from] {
			continue
		}

		adj := g.Nodes[from]
		for i := 0; i < len(adj); i++ {
			to := adj[i].To
			weight := adj[i].Weight

			if dist[from]+weight < dist[to] {
				dist[to] = dist[from] + weight
				heap.Push(pq, &Item{dist[to], to})
			}
		}
	}

	fmt.Printf("Shortest distance array from %v: %v\n", s, dist)

	return dist[t]
}

func main() {
	g := &Graph{
		Size: 3,
		Nodes: [][]*Edge{
			[]*Edge{{1, 100}, {2, 200}},
			[]*Edge{{0, 100}, {2, 50}},
			[]*Edge{{0, 200}, {1, 50}},
		},
	}

	fmt.Println("Dijkstra:", g.Dijkstra(2, 0))
}
