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
    std::string getAtributoDiferente() const override;
     std::string getTipo() const override;
     std::string getAtributo() const;
     
    virtual ~bike(); // Destrutor virtual
};


#endif