FLAGS = -g -Wall -O0 -pedantic-errors

compile: main

main: ItemType.cpp SortedLinkedList.cpp main.cpp
	g++ $(FLAGS) -o main ItemType.cpp SortedLinkedList.cpp main.cpp

run:
	./main input.txt

clean:
	rm main
