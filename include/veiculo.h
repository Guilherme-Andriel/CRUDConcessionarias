#ifndef VEICULO_H
#define VEICULO_H

#include <vector>
#include <string>
#include <iostream>

class Veiculo {
private:
    std::string marca; 
    int preco; 
    std::string chassi; 
    int anoFabricacao; 

public:
    // Construtor da classe Veiculo
    Veiculo(std::string _marca, int _preco, std::string _chassi, int _anoFabricacao);

    virtual ~Veiculo(); // Destrutor virtual

    std::string getNomeConcessionaria() const;
    std::string getChassi() const; // Método para obter o número do chassi
    std::string getMarca() const;
    int getAno() const;
    int getPreco() const;
   virtual std::string getAtributoDiferente() const = 0;
   virtual std::string getTipo() const = 0;
    void setPreco(int novoPreco);

    
};


#endif