lista = Lista/ElementoDuplamenteEncadeado.h Lista/Iterador.h Lista/CabecaDeLista.h Lista/Elemento.h Lista/ListaSerializada.h Lista/IteradorConstante.h
trie = FileTrie.h NodoTrie.h MemoryTrie.h TrieIndex.h
obj = ListaInvertida.o ListaInvertidaSerial.o TrieIndex.o Parser.o

CC = g++ -std=c++0x -I Lista/

all: Main.o

TrieIndex.o: TrieIndex.h TrieIndex.cpp
	$(CC) -c TrieIndex.cpp

ListaInvertida.o: ListaInvertida.h ListaInvertida.cpp $(trie) $(lista)
	$(CC) -c ListaInvertida.cpp

ListaInvertidaSerial.o: ListaInvertidaSerial.h ListaInvertidaSerial.cpp $(trie) $(lista)
	$(CC) -c ListaInvertidaSerial.cpp

Parser.o: Parser.h Parser.cpp TrieIndex.h
	$(CC) -c Parser.cpp

Main.o: Main.cpp $(obj) $(lista)
	$(CC) -o A $(obj) Main.cpp

.PHONY: clean

clean:
	-rm -f a.out

Teste: $(obj) $(lista)
	$(CC) -o T $(obj) Teste.cpp
