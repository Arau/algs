CC=$(CXX)

BIN=bin

test_tree: node tree binnode bintree test_bintree.o
	g++ test_bintree.o BinTree.o BinNode.o Tree.o Node.o -o $(BIN)
#	g++ test_bintree.cpp BinTree.cpp BinNode.cpp Tree.cpp Node.cpp

bintree: BinTree.o

binnode: BinNode.o

node: Node.o

tree: Tree.o

clean:
	rm -f *o $(BIN)
