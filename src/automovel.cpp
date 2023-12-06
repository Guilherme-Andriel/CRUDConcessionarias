#include "automovel.h" 

#include "veiculo.h" 
#include <iostream>
#include <sstream>
#include <algorithm>


// Construtor da classe Automovel
Automovel::Automovel(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoMotor(_tipoMotor) {}

// Método Tipo Motor
std::string Automovel::getAtributoDiferente() const  {

    return "Tipo de Motor: " +tipoMotor;
}

// Destrutor virtual da classe Automovel
Automovel::~Automovel() {}
