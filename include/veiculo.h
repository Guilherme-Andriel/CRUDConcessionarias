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

    std::string getNomeConcessionaria() const;
    std::string getChassi() const; // Método para obter o número do chassi
    std::string getMarca() const;
    int getAno() const;
    double getPreco() const;
   virtual std::string getAtributoDiferente() const = 0;

    
};

class Automovel : public Veiculo {
private:
    std::string tipoMotor; // Tipo de motor do automóvel

public:
    // Construtor da classe Automovel
    Automovel(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoMotor);
    std::string getAtributoDiferente() const override;
    virtual ~Automovel(); // Destrutor virtual
};

class bike : public Veiculo {
private:
    std::string modelo; // Modelo da bike

public:
    // Construtor da classe bike
    bike(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _modelo);
    std::string getAtributoDiferente() const override;
    virtual ~bike(); // Destrutor virtual
};

class Caminhao : public Veiculo {
private:
    std::string tipoCarga; // Tipo de carga do caminhão

public:
    // Construtor da classe Caminhao
    Caminhao(std::string _marca, double _preco, std::string _chassi, int _anoFabricacao, std::string _tipoCarga);
    std::string getAtributoDiferente() const override;
    virtual ~Caminhao(); // Destrutor virtual
};

#endif