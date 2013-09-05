all: reverse1 reverse2 reverse_recursive

reverse1: reverse1.c
	gcc reverse1.c -o reverse1
reverse2: reverse2.c
	gcc reverse2.c -o reverse2
reverse_recursive: reverse_recursive.cpp
	g++ reverse_recursive.cpp -o reverse_recursive

clean:
	rm -rf *.o reverse1 reverse2 reverse_recursive
