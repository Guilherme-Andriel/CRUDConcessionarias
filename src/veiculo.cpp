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


// Método Marca
std::string Veiculo::getMarca() const {
    return marca;
}

// Método Preço
int Veiculo::getPreco() const {
    return preco;
}

// Método chassi
std::string Veiculo::getChassi() const {
    return chassi;
}

// Método Ano
int Veiculo::getAno() const {
    return anoFabricacao;
}

// Método Atributo diferencial
std::string Veiculo::getAtributoDiferente() const {
     return "";
 } 

void Veiculo::setPreco(int novoPreco) {
        this->preco = novoPreco;
    }





