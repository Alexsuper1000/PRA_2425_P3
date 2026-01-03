bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h ../P1/ListLinked.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

clean:
	rm -rf *.o *.gch bin
