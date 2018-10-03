package knapsack

import (
	"testing"
)

type TestKnapsackItem struct {
	weight int64
	value  int64
}

func (i TestKnapsackItem) Weight() int64 {
	return i.weight
}

func (i TestKnapsackItem) Value() int64 {
	return i.value
}

func TestKnapsackEasy(t *testing.T) {
	items := []Packable{
		TestKnapsackItem{
			3, 5,
		},
		TestKnapsackItem{
			2, 3,
		},
		TestKnapsackItem{
			1, 4,
		},
	}

	indices := Knapsack(items, 5)
	var value int64
	for _, i := range indices {
		value += items[i].Value()
	}

	if value != 9 {
		t.Errorf("Expected %d, got %d", 9, value)
	}
}

func TestZeroCapacityKnapsack(t *testing.T) {
	items := []Packable{
		TestKnapsackItem{
			3, 5,
		},
		TestKnapsackItem{
			2, 3,
		},
		TestKnapsackItem{
			1, 4,
		},
	}

	indices := Knapsack(items, 0)
	var value int64
	for _, i := range indices {
		value += items[i].Value()
	}

	if value != 0 {
		t.Errorf("Expected %d, got %d", 0, value)
	}
}

func TestNoItemsForKnapsack(t *testing.T) {
	items := []Packable{}

	indices := Knapsack(items, 0)
	var value int64
	for _, i := range indices {
		value += items[i].Value()
	}

	if value != 0 {
		t.Errorf("Expected %d, got %d", 0, value)
	}
}
