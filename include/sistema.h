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

		// Adiciona um veículo a uma concessionária existente
		std::string addVeiculo (const std::string nome, const std::string nomeComando);

		// Remove um veículo pelo chassi
		std::string removerVeiculo (const std::string chassi);
		
		 // Busca um veículo pelo chassi
		std::string buscarVeiculo (const std::string chassi);

		// Salva os dados de uma concessionária em um arquivo
		std::string saveConcessionaria(const std::string concessionaria);

		 // Carrega os dados de uma concessionária de um arquivo
		std::string loadConcessionaria(const std::string arquivo);

		// Lista os veículos de uma concessionária
		std::string listConcessionaria(const std::string concessionaria);

		 // Aumenta os preços dos veículos de uma concessionária
		std::string raisePrice(const std::string concessionaria);


		  // Busca por um veículo pelo chassi e operação (remover ou buscar)
		std::string buscarPorChassi(const std::string chassi, const std::string opcao, int& saber);

		 // Busca veículos por nome de concessionária e realiza operações específicas
		void buscarPorNome(const std::string nomeConcessionaria, double aumento, const std::string opcao,
                int& contAutomovel, int& contBike, int& contCaminhao,
                int& valorAutomovel, int& valorBike, int& valorCaminhao, int& valorFrota);

		 // Obtém os atributos de um veículo genérico
		template<typename T>
		void getAtributos(std::string& marcaModelo, int& preco, std::string& chassi,
                  int& ano, std::string& atributoDiferencial, T* veiculo);
		
		// Retorna um iterador para uma concessionária pelo nome
		std::vector<Concessionaria>::iterator getIT(std::string nomeDaConcessionaria);


		// Destrutor para liberar a memória alocada para os veículos em cada concessionária
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