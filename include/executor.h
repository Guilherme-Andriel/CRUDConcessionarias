#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "sistema.h"

#include <istream>
#include <ostream>
#include <sstream>

using namespace std;

class Executor {
private:
  Sistema * sistema; 
  stringstream ss; 
  bool sair = false; 

public:
  // Construtor que recebe uma referência para o Sistema
  Executor(Sistema &sistema);

  // Método para iniciar o processamento dos comandos
  void iniciar(istream &in, ostream &out);

  // Método para processar cada linha de comando
  string processarLinha(string linha);
};

#endif
