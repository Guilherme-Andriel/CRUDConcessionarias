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
    // Construtor da classe Veiculo
    Veiculo(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao);

    virtual ~Veiculo(); // Destrutor virtual

    std::string getChassi() const; // Método para obter o número do chassi
};

class Automovel : public Veiculo {
public:
    std::string tipoMotor; // Tipo de motor do automóvel

    // Construtor da classe Automovel
    Automovel(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor);

    virtual ~Automovel(); // Destrutor virtual
};

class Moto : public Veiculo {
public:
    std::string modelo; // Modelo da moto

    // Construtor da classe Moto
    Moto(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _modelo);

    virtual ~Moto(); // Destrutor virtual
};

class Caminhao : public Veiculo {
public:
    std::string tipoCarga; // Tipo de carga do caminhão

    // Construtor da classe Caminhao
    Caminhao(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga);

    virtual ~Caminhao(); // Destrutor virtual
};

#endif
