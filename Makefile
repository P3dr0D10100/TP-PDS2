Project_dir = ${shell cd}
CX := g++
CX_FLAGS := -std=c++14 -ggdb -I ${Project_dir}

all: main Teste
	del bin\*.o

Teste: Teste_busca Teste_doc
	
Teste_busca: bin/Busca.o bin/Busca.teste.o
	$(CX) $(CX_FLAGS) $^ -o bin/Teste-busca.exe

Teste_doc: bin/Documento.o bin/Documento.teste.o
	$(CX) $(CX_FLAGS) $^ -o bin/Teste-documento.exe

main: bin/Documento.o bin/Busca.o bin/main.o
	$(CX) $(CX_FLAGS) $^ -o bin/main.exe

run: main
	cls
	bin/main.exe	

bin/Documento.o: src/Documento.cpp
	$(CX) $(CX_FLAGS) -c $^ -o $@

bin/Busca.o: src/Busca.cpp
	$(CX) $(CX_FLAGS) -c $^ -o $@

bin/main.o: src/main.cpp
	$(CX) $(CX_FLAGS) -c $^ -o $@

bin/Documento.teste.o: test/Documento.teste.cpp
	$(CX) $(CX_FLAGS) -c $^ -o $@

bin/Busca.teste.o: test/Busca.teste.cpp
	$(CX) $(CX_FLAGS) -c $^ -o $@

clean:
	del /s /q bin\*.exe
	del /s /q bin\*.o