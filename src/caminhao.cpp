#include "caminhao.h" 

#include "veiculo.h" 
#include <iostream>
#include <sstream>
#include <algorithm>


// Construtor da classe Caminhao
Caminhao::Caminhao(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoCarga(_tipoCarga) {}

// Método Tipo Carga
std::string Caminhao::getAtributoDiferente() const  {
   
    return  "Tipo de Carga: "+ tipoCarga;
}

// Destrutor virtual da classe Caminhao
Caminhao::~Caminhao() {}