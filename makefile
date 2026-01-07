.PHONY: all clean

all: bin/testBSTree bin/testHashTable bin/testBSTreeDict

bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h ../PRA_2425_P1/ListLinked.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSTree.h Dict.h BSNode.h TableEntry.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp

clean:
	rm -rf *.o *.gch bin
