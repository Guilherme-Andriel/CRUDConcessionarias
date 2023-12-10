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

    // Método para obter o atributo específico do caminhão (Tipo de Carga)
    std::string getAtributoDiferente() const override;

    // Método para obter o tipo do veículo (Caminhão)
    std::string getTipo() const override;

    // Método para obter o atributo Tipo de Carga
    std::string getAtributo() const;

    virtual ~Caminhao(); // Destrutor virtual
};

#endif
