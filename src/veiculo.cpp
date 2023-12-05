#include "veiculo.h" 
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// Construtor da classe Veiculo
Veiculo::Veiculo(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao)
    : marca(_marca), preco(_preco), chassi(_chassi), anoFabricacao(_anoFabricacao) {}

// Destrutor virtual da classe Veiculo
Veiculo::~Veiculo() {}


// Método Marca
std::string Veiculo::getMarca() const {
    return marca;
}

// Método Preço
double Veiculo::getPreco() const {
    return preco;
}

// Método chassi
std::string Veiculo::getChassi() const {
    return chassi;
}

// Método Ano
int Veiculo::getAno() const {
    return anoFabricacao;
}

// Método Atributo diferencial
std::string Veiculo::getAtributoDiferente() const {
     return "";
 } 



// Construtor da classe Automovel
Automovel::Automovel(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoMotor(_tipoMotor) {}

// Método Tipo Motor
std::string Automovel::getAtributoDiferente() const  {

    return "Tipo de Motor: " +tipoMotor;
}

// Destrutor virtual da classe Automovel
Automovel::~Automovel() {}

// Construtor da classe bike
bike::bike(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _modelo)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), modelo(_modelo) {}

// Método Modelo
std::string bike::getAtributoDiferente() const  {
   
    return "Modelo: " + modelo;
}

// Destrutor virtual da classe bike
bike::~bike() {}

// Construtor da classe Caminhao
Caminhao::Caminhao(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoCarga(_tipoCarga) {}

// Método Tipo Carga
std::string Caminhao::getAtributoDiferente() const  {
   
    return  "Tipo de Carga: "+ tipoCarga;
}

// Destrutor virtual da classe Caminhao
Caminhao::~Caminhao() {}