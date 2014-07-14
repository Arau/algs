CC=$(CXX)

test_linkedList: list test_linkedList.o
	g++ LinkedList.o test_linkedList.o

test_dups: list remove_duplicate.o
	g++ LinkedList.o remove_duplicate.o

test_nth: list nth_to_last.o
	g++ LinkedList.o nth_to_last.o

list: LinkedList.o

clean:
	rm -f *o a.out
