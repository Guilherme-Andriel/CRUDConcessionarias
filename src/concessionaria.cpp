#include "concessionaria.h"
#include "veiculo.h" 

Concessionaria::Concessionaria(std::string _nome, std::string _cnpj, int _quantidadeVeiculos, std::vector<Veiculo*> _estoque)
    : nome(_nome), cnpj(_cnpj), quantidadeVeiculos(_quantidadeVeiculos), estoque(_estoque) {}

std::string Concessionaria::getNome() const {
        return nome;
    }

std::string Concessionaria::getCnpj() const {
        return cnpj;
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

// Método para calcular a quantidade atual de veículos na concessionária
int Concessionaria::quantidadeAtualVeiculos(int sizeVetorAntes, int quantVeiculoAntes, int quantVeiculoDepois, int sizeVetorDepois) {
    if(quantVeiculoAntes == sizeVetorAntes) {
        // Se a quantidade de veículos for igual ao número de posições ocupadas no vetor estoque
       
        quantVeiculoDepois++;
      
        return quantVeiculoDepois;
    } else if(quantVeiculoAntes > sizeVetorAntes) {
        // Se a quantidade de veículos for maior que o número de posições ocupadas no vetor estoque
        
        int aux = sizeVetorDepois - quantVeiculoDepois;
        quantVeiculoDepois = quantVeiculoDepois + aux;
        
        return quantVeiculoDepois;
    }
    return 0;
}


// Verifica se um veículo com um determinado chassi já foi adicionado à concessionária
bool Concessionaria::veiculoJaAdicionado(const std::string& chassi) {
    for (Veiculo* veiculo : getEstoque()) {
        if (veiculo->getChassi() == chassi) {
            return true; // Se o veículo já estiver no estoque
        }
    }
    return false; // Se o veículo não estiver no estoque
}