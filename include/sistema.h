#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>


#include "veiculo.h"  
#include "concessionaria.h"

// Sistema deve concentrar todas as operações
class Sistema {
  private:
		std::vector<Concessionaria> concessionarias; //um vetor com todos as concessionarias
  public:

		/*Encerra o funcionamento do programa.
			@return uma string com a mensagem "Saindo.."
		*/
		std::string quit();

		/* Cria uma concessionaria e retorna uma string de erro/sucesso 
			@param nome o nome da concessionaria
			@return uma string contendo uma mensagem de erro ou "Concessionaria Criada"
		*/
		std::string create_concessionaria (const std::string nome);

		std::string addVeiculo (const std::string nome, const std::string nomeComando);

		std::string removerVeiculo (const std::string chassi);
		
		std::string buscarVeiculo (const std::string chassi);

		std::string saveConcessionaria(const std::string concessionaria);

		std::string loadConcessionaria(const std::string arquivo);

		std::string listConcessionaria(const std::string concessionaria);

		std::string raisePrice(const std::string concessionaria);

		

		 ~Sistema() {
        // Liberar a memória alocada para os veículos em cada concessionária
        for (auto& concessionaria : concessionarias) {
            for (Veiculo* veiculo : concessionaria.getEstoque()) {
                delete veiculo;
            }
        }
    }
};

#endif