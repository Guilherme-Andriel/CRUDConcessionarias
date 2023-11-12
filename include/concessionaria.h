#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "veiculo.h"  

#include <vector>
#include <string>

class Concessionaria {
private:
    std::string nome;
    std::string cnpj;
    int quantidadeVeiculos;
    std::vector<Veiculo*> estoque; 

public:
    Concessionaria(std::string _nome, std::string _cnpj, int _quantidadeVeiculos, std::vector<Veiculo*> _estoque);

    std::string getNome() const;
    
    std::vector<Veiculo*>& getEstoque();
     void addVeiculo(Veiculo* novoVeiculo);
     int getQuantidadeVeiculos() const;
    void setQuantidadeVeiculos(int novaQuantidade);
    int quantidadeAtualVeiculos(int sizeVetorAntes, int quantVeiculoAntes, int quantVeiculoDepois, int sizeVetorDepois);
     
};

#endif
