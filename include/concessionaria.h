#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "veiculo.h"  

#include <vector>
#include <string>

class Concessionaria {
private:
    std::string nome;
    std::string cnpj;
    int quantidadeVeiculos;
    std::vector<Veiculo*> estoque; // Vetor de ponteiros para Veiculos no estoque

public:
    // Construtor da classe Concessionaria
    Concessionaria(std::string _nome, std::string _cnpj, int _quantidadeVeiculos, std::vector<Veiculo*> _estoque);

    // Métodos para obter informações da concessionária
    std::string getNome() const; // Retorna o nome da concessionária
    std::string getCnpj() const; // Retorna o CNPJ da concessionária
    std::vector<Veiculo*>& getEstoque(); // Retorna o vetor de Veiculos no estoque
    int getQuantidadeVeiculos() const; // Retorna a quantidade de veículos na concessionária

    // Métodos para manipulação da quantidade de veículos
    void setQuantidadeVeiculos(int novaQuantidade); // Define a nova quantidade de veículos na concessionária
    int quantidadeAtualVeiculos(int sizeVetorAntes, int quantVeiculoAntes, int quantVeiculoDepois, int sizeVetorDepois);
    // Calcula a nova quantidade de veículos na concessionária com base nas alterações no estoque

    // Verifica se um veículo com um determinado chassi já foi adicionado à concessionária
    bool veiculoJaAdicionado(const std::string& chassi);

    // Método para adicionar um novo veículo ao estoque da concessionária
    void addVeiculo(Veiculo* novoVeiculo);
};

#endif
