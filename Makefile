Project_dir = ${shell cd}
CC = g++
CFLAGS = -std=c++14 -Wall -ggdb -I ${Project_dir}

all: main Teste
	del bin\*.o

Teste: Teste_busca Teste_doc
	
Teste_busca: bin/Busca.o bin/Busca.teste.o
	$(CC) $(CFLAGS) $^ -o bin/Teste-busca.exe

Teste_doc: bin/Documento.o bin/Documento.teste.o
	$(CC) $(CFLAGS) $^ -o bin/Teste-documento.exe

main: bin/Documento.o bin/Busca.o bin/main.o
	$(CC) $(CFLAGS) $^ -o bin/main.exe

run: main
	cls
	bin/main.exe	

bin/Documento.o: src/Documento.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

bin/Busca.o: src/Busca.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

bin/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

bin/Documento.teste.o: test/Documento.teste.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

bin/Busca.teste.o: test/Busca.teste.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	del /s /q bin\*.*