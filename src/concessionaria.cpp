#include "concessionaria.h"
#include "veiculo.h" 

#include <algorithm> 

// Construtor da classe Concessionaria
Concessionaria::Concessionaria(std::string _nome, std::string _cnpj, int _quantidadeVeiculos, std::vector<Veiculo*> _estoque)
    : nome(_nome), cnpj(_cnpj), quantidadeVeiculos(_quantidadeVeiculos), estoque(_estoque) {}

// Método para retornar o nome da concessionária
std::string Concessionaria::getNome() const {
    return nome;
}

// Método para retornar o CNPJ da concessionária
std::string Concessionaria::getCnpj() const {
    return cnpj;
}

// Método para adicionar um veículo ao estoque da concessionária
void Concessionaria::addVeiculo(Veiculo* novoVeiculo) {
    estoque.push_back(novoVeiculo);
}

// Método para retornar o vetor de veículos no estoque da concessionária
const std::vector<Veiculo*>& Concessionaria::getEstoque() const { 
    return estoque;
}

// Método para definir um novo estoque de veículos para a concessionária
void Concessionaria::setEstoque(const std::vector<Veiculo*>& novoEstoque) {
    this->estoque = novoEstoque;
}

// Método para retornar a quantidade de veículos na concessionária
int Concessionaria::getQuantidadeVeiculos() const {
    return quantidadeVeiculos;
}

// Método para definir a quantidade de veículos na concessionária
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
        
        int aux = quantVeiculoDepois - sizeVetorDepois;
        quantVeiculoDepois = quantVeiculoDepois - aux;
        
        return quantVeiculoDepois;
    }
    return 0;
}


// Verifica se um veículo com um determinado chassi já foi adicionado à concessionária
bool Concessionaria::veiculoJaAdicionado(const std::string& chassi) const{
    for (Veiculo* veiculo : getEstoque()) {
        if (veiculo->getChassi() == chassi) {
            return true; // Se o veículo já estiver no estoque
        }
    }
    return false; // Se o veículo não estiver no estoque
}


 void Concessionaria::ordenarPorChassi() {
    // Ordena o estoque de veículos com base nos últimos 5 dígitos do número de chassi
    std::sort(estoque.begin(), estoque.end(), [](Veiculo* v1, Veiculo* v2) {
        // Obtém os últimos 5 dígitos do chassi de cada veículo e converte para inteiros
        int chassi1 = std::stoi(v1->getChassi().substr(v1->getChassi().size() - 5));
        int chassi2 = std::stoi(v2->getChassi().substr(v2->getChassi().size() - 5));
        
        // Retorna verdadeiro se chassi1 for menor que chassi2 na ordenação
        return chassi1 < chassi2;
    });
}

