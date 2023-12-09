#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

#include "veiculo.h" 
#include <vector>
#include <string>
#include <iostream>



class Automovel : public Veiculo {
private:
    std::string tipoMotor; // Tipo de motor do automóvel

public:
    // Construtor da classe Automovel
    Automovel(std::string _marca, int _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor);
    std::string getAtributoDiferente() const override;
    std::string getTipo() const override;
    std::string getAtributo() const;

    virtual ~Automovel(); // Destrutor virtual
};


#endif