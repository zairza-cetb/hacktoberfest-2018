package main

import "testing"

var testTable = []struct {
	name     string
	expected int
	s        int
	t        int
	graph    *Graph
}{
	{
		name:     "2 nodes graph",
		expected: 100,
		s:        0,
		t:        1,
		graph: &Graph{
			Size: 2,
			Nodes: [][]*Edge{
				[]*Edge{{1, 100}},
				[]*Edge{{0, 100}},
			},
		},
	},
	{
		name:     "3 nodes graph",
		expected: 150,
		s:        2,
		t:        0,
		graph: &Graph{
			Size: 3,
			Nodes: [][]*Edge{
				[]*Edge{{1, 100}, {2, 200}},
				[]*Edge{{0, 100}, {2, 50}},
				[]*Edge{{0, 200}, {1, 50}},
			},
		},
	},
	{
		name:     "Disconnected graph",
		expected: INF,
		s:        0,
		t:        1,
		graph: &Graph{
			Size: 2,
			Nodes: [][]*Edge{
				[]*Edge{},
				[]*Edge{},
			},
		},
	},
}

func TestDijkstra(t *testing.T) {
	for _, tc := range testTable {
		t.Run(tc.name, func(tt *testing.T) {
			got := tc.graph.Dijkstra(tc.s, tc.t)
			if got != tc.expected {
				tt.Errorf("Failed to calculate shortest distance from %v to %v. Expected '%v' but got '%v'", tc.s, tc.t, tc.expected, got)
			}
		})
	}
}
