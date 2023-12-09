#include "caminhao.h" 

#include "veiculo.h" 
#include <iostream>
#include <sstream>
#include <algorithm>


// Construtor da classe Caminhao
Caminhao::Caminhao(std::string _marca, int _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoCarga(_tipoCarga) {}

// Método Tipo Carga
std::string Caminhao::getAtributoDiferente() const  {
   
    return  "Tipo de Carga: "+ tipoCarga;
}

std::string Caminhao::getAtributo() const  {
   
    return tipoCarga;
}

std::string Caminhao::getTipo() const  {
        return "Caminhao";
    }


// Destrutor virtual da classe Caminhao
Caminhao::~Caminhao() {}