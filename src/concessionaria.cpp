#include "concessionaria.h"
#include "veiculo.h" 

Concessionaria::Concessionaria(std::string _nome, std::string _cnpj, int _quantidadeVeiculos, std::vector<Veiculo*> _estoque)
    : nome(_nome), cnpj(_cnpj), quantidadeVeiculos(_quantidadeVeiculos), estoque(_estoque) {}

std::string Concessionaria::getNome() const {
        return nome;
    }

void Concessionaria::addVeiculo(Veiculo* novoVeiculo) {
        estoque.push_back(novoVeiculo);
    }
 std::vector<Veiculo*>& Concessionaria::getEstoque() {
        return estoque;
    }

int Concessionaria::getQuantidadeVeiculos() const {
    return quantidadeVeiculos;
}

void Concessionaria::setQuantidadeVeiculos(int novaQuantidade) {
    quantidadeVeiculos = novaQuantidade;
}


int Concessionaria::quantidadeAtualVeiculos(int sizeVetorAntes, int quantVeiculoAntes, int quantVeiculoDepois, int sizeVetorDepois){

    if(quantVeiculoAntes == sizeVetorAntes){ //comparar se a quantidade de veiculos é igual a quantidade de posições já ocupadas no vetor estoque.
 
 
  std::cout << "Quantidade de veiculos antes: " << quantVeiculoDepois << std::endl;
  quantVeiculoDepois++;
  std::cout << "Quantidade de veiculos depois: " << quantVeiculoDepois << std::endl;

    return quantVeiculoDepois;
 

}
else if(quantVeiculoAntes > sizeVetorAntes){ 

  std::cout << "Quantidade estoque antes: " << sizeVetorDepois << std::endl;
  std::cout << "Quantidade veiculo antes: " << quantVeiculoDepois << std::endl;
  

  int aux =  sizeVetorDepois - quantVeiculoDepois;
  quantVeiculoDepois = quantVeiculoDepois + aux;

  std::cout << "Quantidade estoque depois: " << sizeVetorDepois << std::endl;
  std::cout << "Quantidade veiculo depois: " << quantVeiculoDepois << std::endl;
  
  return quantVeiculoDepois;
  
}

return 0;
}


bool Concessionaria::veiculoJaAdicionado(const std::string& chassi){
        for (Veiculo* veiculo : getEstoque()) {
            if (veiculo->getChassi() == chassi) {
                return true; // Se o veículo já estiver no estoque
            }
        }
        return false; // Se o veículo não estiver no estoque
    }