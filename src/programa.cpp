#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "sistema.h"
#include "executor.h"
#include "concessionaria.h"
#include "veiculo.h"

using namespace std;

int main() {
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  // o executor recebe o cin e o cout. Ele os utilizará para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens
  executor.iniciar(cin, cout);


  return 0;
}
