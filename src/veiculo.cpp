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

// Método para obter o número do chassi
std::string Veiculo::getChassi() const {
    return chassi;
}

// Construtor da classe Automovel
Automovel::Automovel(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoMotor(_tipoMotor) {}

// Destrutor virtual da classe Automovel
Automovel::~Automovel() {}

// Construtor da classe Moto
Moto::Moto(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _modelo)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), modelo(_modelo) {}

// Destrutor virtual da classe Moto
Moto::~Moto() {}

// Construtor da classe Caminhao
Caminhao::Caminhao(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoCarga(_tipoCarga) {}

// Destrutor virtual da classe Caminhao
Caminhao::~Caminhao() {}
