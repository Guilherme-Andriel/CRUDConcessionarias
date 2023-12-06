.DEFAULT_GOAL := all

OBJECTS=build/sistema.o build/executor.o build/concessionaria.o build/veiculo.o build/automovel.o build/bike.o build/caminhao.o

build/sistema.o: src/sistema.cpp include/sistema.h
	g++ -Iinclude src/sistema.cpp -c -o build/sistema.o

build/executor.o: src/executor.cpp include/executor.h 
	g++ -Iinclude src/executor.cpp -c -o build/executor.o

build/concessionaria.o: src/concessionaria.cpp include/concessionaria.h 
	g++ -Iinclude src/concessionaria.cpp -c -o build/concessionaria.o

build/veiculo.o: src/veiculo.cpp include/veiculo.h 
	g++ -Iinclude src/veiculo.cpp -c -o build/veiculo.o

build/automovel.o: src/automovel.cpp include/automovel.h 
	g++ -Iinclude src/automovel.cpp -c -o build/automovel.o

build/bike.o: src/bike.cpp include/bike.h 
	g++ -Iinclude src/bike.cpp -c -o build/bike.o

build/caminhao.o: src/caminhao.cpp include/caminhao.h 
	g++ -Iinclude src/caminhao.cpp -c -o build/caminhao.o

objects: $(OBJECTS)

programa: objects src/programa.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/programa.cpp -o bin/programa

clean:
	rm build/*.o bin/programa

all: programa

run:
	./bin/programa
