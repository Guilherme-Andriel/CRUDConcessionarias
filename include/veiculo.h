#ifndef VEICULO_H
#define VEICULO_H

#include <vector>
#include <string>
#include <iostream>

class Veiculo {
private:
    std::string marca;
    double preco;
    std::string chassi;
    int anoFabricacao;

public:
    Veiculo(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao);
    virtual ~Veiculo(); // Destrutor virtual

    std::string getChassi() const;
};

class Automovel : public Veiculo {
public:
    std::string tipoMotor;

    Automovel(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor);
    virtual ~Automovel(); // Destrutor virtual
};

class Moto : public Veiculo {
public:
    std::string modelo;

    Moto(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _modelo);
    virtual ~Moto(); // Destrutor virtual
};

class Caminhao : public Veiculo {
public:
    std::string tipoCarga;

    Caminhao(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga);
    virtual ~Caminhao(); // Destrutor virtual
};

#endif
