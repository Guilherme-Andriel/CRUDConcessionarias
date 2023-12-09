#include "bike.h" 

#include "veiculo.h" 
#include <iostream>
#include <sstream>
#include <algorithm>


// Construtor da classe bike
bike::bike(std::string _marca, int _preco, std::string _chassi, int _anoFabricacao, std::string _modelo)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), modelo(_modelo) {}

// Método Modelo
std::string bike::getAtributoDiferente() const  {
   
    return "Modelo: " + modelo;
}

std::string bike::getAtributo() const  {
   
    return modelo;
}

 std::string bike::getTipo() const {
        return "bike";
    }


// Destrutor virtual da classe bike
bike::~bike() {}