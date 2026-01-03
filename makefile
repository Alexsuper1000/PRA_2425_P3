bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h ../P1/ListLinked.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSTree.h Dict.h BSNode.h TableEntry.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp

clean:
	rm -rf *.o *.gch bin
