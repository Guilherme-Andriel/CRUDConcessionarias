#include "veiculo.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// Construtor da classe Veiculo
Veiculo::Veiculo(std::string _marca, int _preco, std::string _chassi, int _anoFabricacao)
    : marca(_marca), preco(_preco), chassi(_chassi), anoFabricacao(_anoFabricacao) {}

// Destrutor virtual da classe Veiculo
Veiculo::~Veiculo() {}

// Método para obter a marca do veículo
std::string Veiculo::getMarca() const {
    return marca;
}

// Método para obter o preço do veículo
int Veiculo::getPreco() const {
    return preco;
}

// Método para obter o chassi do veículo
std::string Veiculo::getChassi() const {
    return chassi;
}

// Método para obter o ano de fabricação do veículo
int Veiculo::getAno() const {
    return anoFabricacao;
}

// Método para obter um atributo diferencial (ainda não implementado)
std::string Veiculo::getAtributoDiferente() const {
    return "";
}

// Método para definir um novo preço para o veículo
void Veiculo::setPreco(int novoPreco) {
    this->preco = novoPreco;
}
