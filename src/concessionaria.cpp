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
