#include "sistema.h"
#include "concessionaria.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_concessionaria(const string nome) {
    istringstream buf(nome);
    
    string nomeDaConcessionaria, Ncnpj, quantDeVeiculos;
    buf >> nomeDaConcessionaria >> Ncnpj >> quantDeVeiculos;

    cout << "Nome da Concessionária: " << nomeDaConcessionaria << endl;
    cout << "CNPJ: " << Ncnpj << endl;
    cout << "Quantidade de Veículos: " << quantDeVeiculos << endl;

    int quantidadeVeiculos = std::stoi(quantDeVeiculos); // Converter a string para inteiro
    vector<Veiculo*> estoque; // Criar o vetor de veículos

    // Criar a nova concessionária com os argumentos 
    Concessionaria novaConcessionaria(nomeDaConcessionaria, Ncnpj, quantidadeVeiculos, estoque);

    // Adicionar a nova concessionária ao vetor
    concessionarias.push_back(novaConcessionaria);
    return "Concessionária criada com sucesso.";
}

//IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina  
string Sistema::addCar (const std::string nome) {
   istringstream buf(nome);

   string nomeDaConcessionaria, marca, preco, chassi, fabricacao, motor;
   buf >> nomeDaConcessionaria >> marca >> preco >> chassi >> fabricacao >> motor;

   cout << "Nome da Concessionária: " << nomeDaConcessionaria << endl;
    cout << "Marca: " << marca << endl;
    cout << "Preço: " << preco << endl;
    cout << "Chassi: " << chassi << endl;
    cout << "Fabricação: " << fabricacao << endl;
    cout << "Motor: " << motor << endl;
    double precoV = std::stoi(preco);
    int fabricacaoV = std::stoi(fabricacao);


    Automovel carro( marca, precoV, chassi, fabricacaoV, motor);

    auto it = std::find_if(concessionarias.begin(), concessionarias.end(), [&](const Concessionaria& concessionarias) {
        return concessionarias.getNome() == nomeDaConcessionaria;
    });

    if (it != concessionarias.end()) {
        size_t pos = std::distance(concessionarias.begin(), it);
        std::cout << "Valor encontrado na posição: " << pos << std::endl;

          bool veiculoJaAdicionado = false;
        for (Veiculo* veiculo : it->getEstoque()) {
          if (veiculo->getChassi() == chassi) {
              veiculoJaAdicionado = true;
              break;
          }
      }
        
        Automovel* novoCarro = new Automovel(marca, precoV, chassi, fabricacaoV, motor);

        if (veiculoJaAdicionado) {
            std::cout << "Veículo já adicionado no estoque." << std::endl;
            
        } else {
           it->addVeiculo(novoCarro); // Adiciona o carro ao estoque da concessionária
            int cont = it->getQuantidadeVeiculos();
              std::cout << "Veículo antes: " << cont << std::endl;
            cont++;
            it->setQuantidadeVeiculos(cont);
            std::cout << "Veículo adicionado com sucesso." << std::endl;
           
             std::cout << "Veículo depois: " << cont << std::endl;
         

        }

    } else {
        std::cout << "Valor não encontrado." << std::endl;
    }


  return "Adicionado veiculo carro com sucesso.";
}

string Sistema::addMotorcycle (const std::string nome) {


   return "Adicionado veiculo moto com sucesso.";
}

string Sistema::addTruck (const std::string nome) {




   return "Adicionado veiculo caminhão com sucesso.";
}

string Sistema::removerVeiculo (const string chassi) {


   return "Removido veiculo com sucesso.";
}





/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
