#include "veiculo.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Veiculo::Veiculo(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao)
    : marca(_marca), preco(_preco), chassi(_chassi), anoFabricacao(_anoFabricacao) {}

 std::string Veiculo::getChassi() const {
        return chassi;
    }

Automovel::Automovel(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoMotor(_tipoMotor) {}

Moto::Moto(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _modelo)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), modelo(_modelo) {}

Caminhao::Caminhao(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga)
    : Veiculo(_marca, _preco, _chassi, _anoFabricacao), tipoCarga(_tipoCarga) {}