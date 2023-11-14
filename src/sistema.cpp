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
    // Inicialização do stringstream para processar a string de entrada
    istringstream buf(nome);
    
    // Declaração das variáveis para armazenar informações da concessionária
    string nomeDaConcessionaria, Ncnpj, quantDeVeiculos;
    buf >> nomeDaConcessionaria >> Ncnpj >> quantDeVeiculos;

    // Conversão da quantidade de veículos de string para inteiro
    int quantidadeVeiculos = std::stoi(quantDeVeiculos);

    // Vetor para armazenar o estoque de veículos da concessionária
    vector<Veiculo *> estoque;

    // Variável estática para controlar o nome da última concessionária criada
    static std::string nomeAntigo;

    // Verifica se a última concessionária criada é diferente da atual
    if (nomeAntigo != nomeDaConcessionaria) {
        // Verifica se a nova concessionária já existe no vetor de concessionárias
        bool concessionariaExistente = false;
        for (const auto& concessionaria : concessionarias) {
            if (concessionaria.getNome() == nomeDaConcessionaria && concessionaria.getCnpj() == Ncnpj) {
                concessionariaExistente = true;
                break;
            }
        }

        // Se a concessionária não existir, cria uma nova e a adiciona ao vetor de concessionárias
        if (!concessionariaExistente) {
            Concessionaria novaConcessionaria(nomeDaConcessionaria, Ncnpj, quantidadeVeiculos, estoque);
            concessionarias.push_back(novaConcessionaria);
            nomeAntigo = nomeDaConcessionaria;

            return "Concessionária criada com sucesso.";
        } else {
            // Se a concessionária já existir, retorna uma mensagem informando isso
            return "Concessionária já criada antes.";
        }
    } else {
        // Se a última concessionária criada for igual à atual, retorna uma mensagem informando isso
        return "Concessionária já criada antes.";
    }
}


 
string Sistema::addVeiculo(const std::string nome) {
    // Criando um stream a partir da string 'nome'
    istringstream buf(nome);

    // Declarando variáveis para armazenar informações do veículo
    string nomeDaConcessionaria, marca, preco, chassi, fabricacao, atributoDiferencial;
    buf >> nomeDaConcessionaria >> marca >> preco >> chassi >> fabricacao >> atributoDiferencial;

    // Convertendo strings para os tipos apropriados
    double precoV = std::stoi(preco);
    int fabricacaoV = std::stoi(fabricacao);

    // Criando um objeto Automovel 
    Automovel Moto(marca, precoV, chassi, fabricacaoV, atributoDiferencial);

    // Procurando a concessionária pelo nome dentro do vetor 'concessionarias'
    auto it = std::find_if(concessionarias.begin(), concessionarias.end(), [&](const Concessionaria& concessionarias) {
        return concessionarias.getNome() == nomeDaConcessionaria;
    });

    // Verificando se a concessionária foi encontrada
    if (it != concessionarias.end()) {
       

        // Obtendo a posição da concessionária no vetor
        size_t pos = std::distance(concessionarias.begin(), it);

        // Criando um novo veículo
        Automovel* novoVeiculo = new Automovel(marca, precoV, chassi, fabricacaoV, atributoDiferencial);

        // Verificando se o veículo já foi adicionado à concessionária
        if (it->veiculoJaAdicionado(chassi)) {
            // Se o veículo já foi adicionado, mostramos uma mensagem de erro
            delete novoVeiculo;
            std::stringstream ss;
            ss << "ERRO - Veículo " << chassi << " já adicionado à concessionária " << it->getNome();
            return ss.str();
        } else {
            // Se o veículo não foi adicionado, procedemos com a adição

            // Obtendo o tamanho do estoque e a quantidade de veículos antes da adição
            int sizeVetorAntes = it->getEstoque().size();
            int quantVeiculoAntes = it->getQuantidadeVeiculos();

            // Adicionando o veículo ao estoque da concessionária
            it->addVeiculo(novoVeiculo);

            // Obtendo a quantidade de veículos e o tamanho do estoque após a adição
            int quantVeiculoDepois = it->getQuantidadeVeiculos();
            int sizeVetorDepois = it->getEstoque().size();

            // Calculando a nova quantidade de veículos na concessionária
            int novaQuantVeiculos = it->quantidadeAtualVeiculos(sizeVetorAntes, quantVeiculoAntes, quantVeiculoDepois, sizeVetorDepois);
            
            // Definindo a nova quantidade de veículos na concessionária
            it->setQuantidadeVeiculos(novaQuantVeiculos);
        }
    } else {
        // Se a concessionária não foi encontrada, exibimos uma mensagem
        std::cout << "Concessionaria não encontrada." << std::endl;
    }
    // Retornando uma mensagem indicando o sucesso da adição do veículo
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