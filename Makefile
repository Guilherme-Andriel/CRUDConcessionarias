.DEFAULT_GOAL := all

#quando adicionar uma nova dependencia não esqueça de atualizar aqui!
OBJECTS=build/sistema.o build/executor.o

build/sistema.o: src/sistema.cpp include/sistema.h
	g++ -Iinclude src/sistema.cpp -c -o build/sistema.o

build/executor.o: src/executor.cpp include/executor.h 
	g++ -Iinclude src/executor.cpp -c -o build/executor.o

#para adicionar novas regras apenas siga o formato
#build/concessionaria.o: src/concessionaria.cpp include/concessionaria.h
#	g++ -Iinclude src/concessionaria.cpp -c

objects: $(OBJECTS)

programa: objects src/programa.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/programa.cpp -o bin/programa

clean:
	rm build/*.o bin/programa

all: programa

run:
	./bin/programa
