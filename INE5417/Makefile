CC = g++ -std=c++0x

obj = MovimentacaoDeTropas.o Tecnologia.o Jogador.o OrdemDeEnvio.o \
	  Exercito.o

all: a.out

Tecnologia.o: Tecnologia.h Tecnologia.cpp
	$(CC) -c Tecnologia.cpp

Jogador.o: Jogador.h Jogador.cpp Tecnologia.h
	$(CC) -c Jogador.cpp

MovimentacaoDeTropas.o: MovimentacaoDeTropas.h MovimentacaoDeTropas.cpp
	$(CC) -c MovimentacaoDeTropas.cpp

OrdemDeEnvio.o: OrdemDeEnvio.h OrdemDeEnvio.cpp
	$(CC) -c OrdemDeEnvio.cpp

Exercito.o: Exercito.h Exercito.cpp
	$(CC) -c Exercito.cpp

.PHONY: clean

clean:
	-rm $(obj)

a.out: $(obj)
	$(CC) $(obj) Main.cpp
