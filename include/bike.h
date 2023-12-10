#ifndef BIKE_H
#define BIKE_H

#include "veiculo.h"

#include <vector>
#include <string>
#include <iostream>

class bike : public Veiculo {
private:
    std::string modelo; // Modelo da bike

public:
    // Construtor da classe bike
    bike(std::string _marca, int _preco, std::string _chassi, int _anoFabricacao, std::string _modelo);

    // Método para obter o atributo específico da bike (Modelo)
    std::string getAtributoDiferente() const override;

    // Método para obter o tipo do veículo (Bike)
    std::string getTipo() const override;

    // Método para obter o atributo Modelo
    std::string getAtributo() const;

    virtual ~bike(); // Destrutor virtual
};

#endif
