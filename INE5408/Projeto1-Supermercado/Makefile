obj = Produto.o Cliente.o Caixa.o Guiche.o Eventos.o Pichador.o Supermercado.o Estatistico.o #object files
lista = Lista/CabecaDeLista.h Lista/Iterador.h Lista/IteradorConstante.h
CC = g++ -std=c++0x -I ./Lista/

all: Main.o

Produto.o: Produto.h Produto.cpp
	$(CC) -c Produto.cpp

Cliente.o: Cliente.h Cliente.cpp Produto.h Guiche.h $(lista)
	$(CC) -c Cliente.cpp

Caixa.o: Caixa.h Caixa.cpp Cliente.h $(lista)
	$(CC) -c Caixa.cpp

Guiche.o: Guiche.h Guiche.cpp Caixa.h Escutador.h $(lista)
	$(CC) -c Guiche.cpp

Eventos.o: Eventos.h Eventos.cpp
	$(CC) -c Eventos.cpp

Pichador.o: Pichador.h Pichador.cpp Escutador.h Eventos.h Cliente.h Caixa.h
	$(CC) -c Pichador.cpp

Supermercado.o: Supermercado.h Supermercado.cpp Guiche.h Escutador.h Eventos.h Cliente.h Produto.h Caixa.h $(lista)
	$(CC) -c Supermercado.cpp

Estatistico.o: Estatistico.h Estatistico.cpp Escutador.h Eventos.h Supermercado.h Guiche.h $(lista)
	$(CC) -c Estatistico.cpp

Main.o: Main.cpp $(obj) $(lista)
	$(CC) Main.cpp $(obj)

.PHONY: clean cleanObj

clean: cleanObj
	-rm -f a.out

cleanObj:
	-rm -f $(obj)
