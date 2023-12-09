#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "veiculo.h" 

#include <vector>
#include <string>
#include <iostream>


class Caminhao : public Veiculo {
private:
    std::string tipoCarga; // Tipo de carga do caminhão

public:
    // Construtor da classe Caminhao
    Caminhao(std::string _marca, int _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga);
    std::string getAtributoDiferente() const override;
     std::string getTipo() const override;
     std::string getAtributo() const;

    virtual ~Caminhao(); // Destrutor virtual
};

#endif