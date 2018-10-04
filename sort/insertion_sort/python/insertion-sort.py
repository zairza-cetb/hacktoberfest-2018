def insertion_sort(to_sort):
	i=0
	while i <= len(to_sort)-1:
		hole = i;
		item = to_sort[i]
		while hole > 0 and to_sort[hole-1]  > item:
			to_sort[hole] = to_sort[hole-1]
			hole-=1
		to_sort[hole] = item
		i+=1
	return to_sort
