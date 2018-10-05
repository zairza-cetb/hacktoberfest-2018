class Graph:
	def __init__(self):
		self.vertices = {}
		self.invVertices = []
		self.adjList = []
		self.size = 0

	def insert_node(self, name):
		self.invVertices.append(name)
		self.vertices[name] = self.size
		self.adjList.append([])
		self.size += 1

	def insert_edge(self, src, dest, weight = 1):
		self.adjList[self.vertices[src]].append((self.vertices[dest], weight))

	def dijkstra(self, rt):
		root = self.vertices[rt]
		INF = float('inf')
		m = Heap(size = self.size, inf = INF)
		dist = [INF for i in xrange(self.size)]
		pi = [0 for i in xrange(self.size)]

		m.update(root, 0)
		pi[root] = root
		dist[root] = 0

		for i in xrange(self.size):
			root = m.extract_top()

			if dist[root] == INF:
				break

			for node, wt in self.adjList[root]:
				if dist[root] + wt < dist[node]:
					dist[node] = dist[root] + wt
					m.update(node, dist[node])
					pi[node] = root

		for i in xrange(self.size):
			if dist[i] != INF:
				print "Node: ", self.invVertices[i],"\tDistance: ",dist[i],"\tPi(",self.invVertices[i],"): ",self.invVertices[pi[i]]

class Heap:
	@staticmethod
	def parent(n):
		return (n-1)/2

	@staticmethod
	def left(n):
		return 2*n + 1

	@staticmethod
	def right(n):
		return 2*n + 2

	def compare(self, a, b):
		return (a < b if self.isMin else a > b)

	def swap(self, i, j):
		self.pos[self.heap[i][0]] = j
		self.pos[self.heap[j][0]] = i
		self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

	def __init__(self, size, inf, isMin = True):
		self.pos = [i for i in xrange(size)]
		self.heap = [[i, inf] for i in xrange(size)]
		self.size = size
		self.isMin = isMin

	def update(self, i, newVal):
		if self.compare(self.heap[self.pos[i]][1], newVal):
			self.heap[self.pos[i]][1] = newVal
			self.top_down_heapify(self.pos[i])

		else:
			self.heap[self.pos[i]][1] = newVal
			self.bottom_up_heapify(self.pos[i])

	def extract_top(self):
		retVal = self.heap[0][0]
		self.size -= 1
		self.swap(0, self.size)
		self.heap.pop()
		self.top_down_heapify(0)
		return retVal

	def top_down_heapify(self, i):
		l = Heap.left(i)
		r = Heap.right(i)
		j = i

		while r < self.size:
			j = l if self.compare(self.heap[l][1], self.heap[r][1]) else r

			if self.compare(self.heap[i][1], self.heap[j][1]):
				break

			else:
				self.swap(i, j)
				i = j
				l = Heap.left(i)
				r = Heap.right(i)

		if l == self.size - 1 and self.compare(self.heap[l][1], self.heap[j][1]):
			self.swap(l, j)

	def bottom_up_heapify(self, i):
		p = Heap.parent(i)
		while(p >= 0):
			if self.compare(self.heap[i][1], self.heap[p][1]):
				self.swap(i, p)
				i = p
				p = Heap.parent(i)

			else:
				break

if __name__ == "__main__":
	a = Graph()

	a.insert_node('A')
	a.insert_node('B')
	a.insert_node('C')
	a.insert_node('D')
	a.insert_node('E')

	a.insert_edge('A', 'B', 10)
	a.insert_edge('B', 'C', 2)
	a.insert_edge('C', 'D', 9)
	a.insert_edge('D', 'C', 7)
	a.insert_edge('E', 'D', 2)
	a.insert_edge('E', 'C', 8)
	a.insert_edge('B', 'E', 4)
	a.insert_edge('E', 'B', 1)
	a.insert_edge('A', 'E', 3)

	print "\nDijkstra:"
	a.dijkstra('A')
