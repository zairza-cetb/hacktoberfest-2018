Output:avl.o
	g++ avl.o -o namedb
	
avl.o:avl.cpp
	g++ -c avl.cpp
	
clean:
	rm *.o namedb
