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

	def dfs(self, source):
		source = self.vertices[source]
		visit = [True for i in xrange(self.size)]
		stack = [source]
		pi = {source : source}

		while len(stack) != 0:
			c = stack.pop()

			if visit[c]:
				print "Node: ", self.invVertices[c], "\t Pi(", self.invVertices[c], "): ", self.invVertices[pi[c]]

				visit[c] = False

			for n,w in self.adjList[c]:
				if visit[n]:
					stack.append(n)
					pi[n] = c

if __name__ == "__main__":
	a = Graph()

	a.insert_node('A')
	a.insert_node('B')
	a.insert_node('C')
	a.insert_node('D')
	a.insert_node('E')

	a.insert_edge('A', 'B')
	a.insert_edge('B', 'C')
	a.insert_edge('C', 'E')
	a.insert_edge('C', 'D')
	a.insert_edge('C', 'A')
	a.insert_edge('C', 'B')

	print "\nDFS:"
	a.dfs('A')
