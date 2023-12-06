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
    bike(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _modelo);
    std::string getAtributoDiferente() const override;
    virtual ~bike(); // Destrutor virtual
};


#endif