#include "sistema.h"
#include "concessionaria.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

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

    int quantidadeVeiculos = std::stoi(quantDeVeiculos); // Converter a string para inteiro.

    vector<Veiculo *> estoque; // Criar o vetor de veículos.

    static std::string nomeAntigo; // Declaração da variável nomeAntigo.

    if (nomeAntigo != nomeDaConcessionaria) {
        // Criar a nova concessionária com os argumentos.
        Concessionaria novaConcessionaria(nomeDaConcessionaria, Ncnpj, quantidadeVeiculos, estoque);

        // Adicionar a nova concessionária ao vetor.
        concessionarias.push_back(novaConcessionaria);
        nomeAntigo = nomeDaConcessionaria;

        return "Concessionária criada com sucesso.";
    } else {

        return "Concessionária já criada antes.";
    }
    
}

 
string Sistema::addVeiculo (const std::string nome) {

    istringstream buf(nome);

     string nomeDaConcessionaria, marca, preco, chassi, fabricacao, atributoDiferencial;
     buf >> nomeDaConcessionaria >> marca >> preco >> chassi >> fabricacao >> atributoDiferencial;


      double precoV = std::stoi(preco);
      int fabricacaoV = std::stoi(fabricacao);


      Automovel Moto( marca, precoV, chassi, fabricacaoV, atributoDiferencial);

      auto it = std::find_if(concessionarias.begin(), concessionarias.end(), [&](const Concessionaria& concessionarias) {
          return concessionarias.getNome() == nomeDaConcessionaria;
      });

      if (it != concessionarias.end()) {
          size_t pos = std::distance(concessionarias.begin(), it);
     

          Automovel* novoVeiculo = new Automovel(marca, precoV, chassi, fabricacaoV, atributoDiferencial);

          if (it->veiculoJaAdicionado(chassi)) {

               delete novoVeiculo;
                   std::stringstream ss;
                    ss << "ERRO - Veículo " << chassi << " já adicionado à concessionária " << it->getNome();
                    return ss.str();

          } else {

            int sizeVetorAntes = it->getEstoque().size();
            int quantVeiculoAntes = it->getQuantidadeVeiculos();
           
            it->addVeiculo(novoVeiculo); // Adiciona o carro ao estoque da concessionária

            int quantVeiculoDepois = it->getQuantidadeVeiculos();
            int sizeVetorDepois = it->getEstoque().size();


            int novaQuantVeiculos = it->quantidadeAtualVeiculos(sizeVetorAntes, quantVeiculoAntes, quantVeiculoDepois, sizeVetorDepois);
            it->setQuantidadeVeiculos(novaQuantVeiculos);

          }

      } else {
          std::cout << "Concessionaria não encontrada." << std::endl;
      }

  
   return "Adicionado veiculo com sucesso.";
}




string Sistema::removerVeiculo(const string chassi) {

    // Iterar sobre as concessionárias
    for (auto& concessionaria : concessionarias) {

        // Obter o vetor de veículos da concessionária
        vector<Veiculo*>& estoque = concessionaria.getEstoque();

        // Encontrar o veículo com base no chassi usando um iterador
        auto it = find_if(estoque.begin(), estoque.end(), [&](Veiculo* veiculo) {
            return veiculo->getChassi() == chassi;
        });

        // Verificar se o veículo foi encontrado
        if (it != estoque.end()) {
            // Remover o veículo do vetor
            delete *it; // Liberar a memória alocada dinamicamente

            estoque.erase(it);

            return "Veículo removido com sucesso.";
        }
    }

    // Se chegou aqui, o veículo não foi encontrado
    return "Veículo não encontrado.";
}






/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */