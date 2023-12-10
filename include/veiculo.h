#ifndef VEICULO_H
#define VEICULO_H

#include <vector>
#include <string>
#include <iostream>

class Veiculo {
private:
    std::string marca; // Marca do veículo
    int preco; // Preço do veículo
    std::string chassi; // Número do chassi do veículo
    int anoFabricacao; // Ano de fabricação do veículo

public:
    // Construtor da classe Veiculo
    Veiculo(std::string _marca, int _preco, std::string _chassi, int _anoFabricacao);

    virtual ~Veiculo(); // Destrutor virtual

    std::string getNomeConcessionaria() const; // Método para obter o nome da concessionária (não implementado)
    std::string getChassi() const; // Método para obter o número do chassi
    std::string getMarca() const; // Método para obter a marca do veículo
    int getAno() const; // Método para obter o ano de fabricação do veículo
    int getPreco() const; // Método para obter o preço do veículo

    virtual std::string getAtributoDiferente() const = 0; // Método virtual puro para obter um atributo específico
    virtual std::string getTipo() const = 0; // Método virtual puro para obter o tipo de veículo

    void setPreco(int novoPreco); // Método para definir um novo preço para o veículo

};

#endif
