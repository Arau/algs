CC=$(CXX)

BIN = bin

test_tree: node tree binnode bintree test_bintree.o
	g++ test_bintree.o BinTree.o BinNode.o Tree.o Node.o -o $(BIN)

test_binsearch: node tree binnode bintree binsearchtree test_binsearch.o
	g++ test_binsearch.o BinSearchTree.o BinTree.o BinNode.o Tree.o Node.o -o $(BIN)

balancedBinTree_from_sortedArray: node tree binnode bintree binsearchtree balancedBinTree_from_sortedArray.o
	g++ balancedBinTree_from_sortedArray.o BinSearchTree.o BinTree.o BinNode.o Tree.o Node.o -o $(BIN)
	
linkedList_from_tree: node tree binnode bintree binsearchtree linkedList linkedList_from_tree.o
	g++ linkedList_from_tree.o LinkedList.o BinSearchTree.o BinTree.o BinNode.o Tree.o Node.o -o $(BIN)

first_common_ancestor_bintree: node tree binnode bintree first_common_ancestor_bintree.o
	g++ first_common_ancestor_bintree.o BinTree.o BinNode.o Tree.o Node.o -o $(BIN)

binsearchtree: BinSearchTree.o

bintree: BinTree.o

binnode: BinNode.o

node: Node.o

tree: Tree.o

linkedList: LinkedList.o

clean:
	rm -f *o $(BIN)
