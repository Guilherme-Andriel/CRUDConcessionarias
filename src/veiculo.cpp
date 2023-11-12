#include "veiculo.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Veiculo::Veiculo(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao)
    : marca(_marca), preco(_preco), chassi(_chassi), anoFabricacao(_anoFabricacao) {}

Veiculo::~Veiculo() {
    // Destrutor da classe base, pode ser vazio se não tiver nada a liberar
}

std::string Veiculo::getChassi() const {
    return chassi;
}

Automovel::Automovel(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoMotor(_tipoMotor) {}

Automovel::~Automovel() {
    // Destrutor da classe derivada, pode ser vazio se não tiver nada a liberar
}

Moto::Moto(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _modelo)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), modelo(_modelo) {}

Moto::~Moto() {
    // Destrutor da classe derivada, pode ser vazio se não tiver nada a liberar
}

Caminhao::Caminhao(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoCarga(_tipoCarga) {}

Caminhao::~Caminhao() {
    // Destrutor da classe derivada, pode ser vazio se não tiver nada a liberar
}
