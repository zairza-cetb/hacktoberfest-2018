# arr	:	array to heapify
# n		: 	size of the array
# i		:	root
def heapify(arr, n, i): 
	largest = i 

	# child nodes
	l = 2 * i + 1	
	r = 2 * i + 2

	# If first condition is false second condition is not checked.
	# This also helps to avoid an array index error. 
	if l < n and arr[i] < arr[l]: 
		largest = l 	

	# Same as above but for the right child.
	if r < n and arr[largest] < arr[r]: 
		largest = r 

	# If needed, change the root and heapify again.
	if largest != i: 
		arr[i], arr[largest] = arr[largest], arr[i] # swap 

		# Heapify the new root. 
		heapify(arr, n, largest) 


def heapSort(arr): 
	n = len(arr) 

	# Build a maxheap. 
	for i in range(n, -1, -1):
		heapify(arr, n, i) 

	for i in range(n-1, 0, -1): 
		arr[i], arr[0] = arr[0], arr[i] # swap 
		heapify(arr, i, 0) 

# Testing Code
arr = [9, 8, 7, 6, 5, 4, 3, 200, 100] 
heapSort(arr) 
n = len(arr)  

# Print the result
for i in range(n): 
	print ("%d" %arr[i], end = " "), 


