#include "sistema.h"
#include "concessionaria.h"
#include "veiculo.h"
#include "automovel.h"
#include "bike.h"
#include "caminhao.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

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

    // Vetor que armazena ponteiros para objetos do tipo Veiculo
    vector<Veiculo *> estoque;

    // Variável estática para controlar o nome da última concessionária criada
     std::string nomeAntigo;

    // Verifica se o nome da última concessionária criada é diferente da atual
    if (nomeAntigo != nomeDaConcessionaria) {
        // Verifica se a nova concessionária já existe no vetor de concessionárias
        bool concessionariaExistente = false;
        for (const auto& concessionaria : concessionarias) {
            if (concessionaria.getNome() == nomeDaConcessionaria || concessionaria.getCnpj() == Ncnpj) {
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
        } 
    }

     // Se a última concessionária criada for igual à atual
        return "Concessionária já criada antes.";
}


 


string Sistema::addVeiculo(const std::string nome, const std::string nomeComando) {
    // Criando um stream a partir da string 'nome'

    istringstream buf(nome);

    // Declarando variáveis para armazenar informações do veículo
    string nomeDaConcessionaria, marca, preco, chassi, fabricacao, atributoDiferencial;
    buf >> nomeDaConcessionaria >> marca >> preco >> chassi >> fabricacao >> atributoDiferencial;

    // Convertendo strings para os tipos apropriados
    double precoV = std::stoi(preco);
    int fabricacaoV = std::stoi(fabricacao);

    

    // Procurando a concessionária pelo nome dentro do vetor 'concessionarias'
    auto it = std::find_if(concessionarias.begin(), concessionarias.end(), [&](const Concessionaria& concessionaria) {
        return concessionaria.getNome() == nomeDaConcessionaria;
    });

    //  Compara se o iterador it não está apontando para esse marcador de fim   
    
    if (it != concessionarias.end()) {

      // Procurando o veículo em todas as concessionárias e ver se ele está no vetor
      for (const auto& concessionaria : concessionarias) {
        if (concessionaria.veiculoJaAdicionado(chassi)) {
            std::stringstream ss;
            ss << "ERRO - Veículo " << chassi << " já adicionado à concessionária " << concessionaria.getNome();
            return ss.str();
           }
        }
       
        // Criando um novo veículo

        Veiculo* novoVeiculo = nullptr;

        if (nomeComando == "add-car") {
            novoVeiculo = new Automovel(marca, precoV, chassi, fabricacaoV, atributoDiferencial);
        } else if (nomeComando == "add-bike") {
            novoVeiculo = new bike(marca, precoV, chassi, fabricacaoV, atributoDiferencial);
        } else if (nomeComando == "add-truck") {
            novoVeiculo = new Caminhao(marca, precoV, chassi, fabricacaoV, atributoDiferencial);
        }
       

        int sizeVetorAntes = it->getEstoque().size();
        int quantVeiculoAntes = it->getQuantidadeVeiculos();


        // Adicionando o veículo à concessionária encontrada pelo find_if
        it->addVeiculo(novoVeiculo);

        // Ordenar o estoque pelos ultimos 5 digitos numericos do chassi
        it->ordenarPorChassi();

          int quantVeiculoDepois = it->getQuantidadeVeiculos();
          int sizeVetorDepois = it->getEstoque().size();


          int novaQuantVeiculos = it->quantidadeAtualVeiculos(sizeVetorAntes, quantVeiculoAntes, quantVeiculoDepois, sizeVetorDepois);
          it->setQuantidadeVeiculos(novaQuantVeiculos);
         

        // Retornando uma mensagem indicando o sucesso da adição do veículo
        return "Adicionado veiculo com sucesso.";
    } else {
        // Se a concessionária não foi encontrada, exibimos uma mensagem
        return "ERRO - Concessionaria não encontrada.";
    }
}







string Sistema::removerVeiculo(const string chassi) {
    // Iterar sobre as concessionárias para procurar o chassi em cada estoque de cada concessionaria
    for (auto& concessionaria : concessionarias) {

        auto& estoque = const_cast<vector<Veiculo*>&>(concessionaria.getEstoque()); //conversão da referência estoque que é constante para uma referência não constante usando o const_cast.
       
        //busca pelo veiculo com chassi pedido utilizando a função find_if
        auto it = std::find_if(estoque.begin(), estoque.end(), [&](Veiculo* veiculo) {
            return veiculo->getChassi() == chassi;
        });

           //Se o a função retornar um iterador apontando para o veiculo, logo it é diferente de estoque.end()
        if (it != estoque.end()) {
            delete *it; //liberando o valor apontado pelo iterador
            estoque.erase(it); //remove o veiculo do vetor e faz o ajuste automático do tamanho do vetor
            return "Veículo " + chassi + " removido da concessionária " + concessionaria.getNome();
        }
    }

    return "Veículo " + chassi + " não encontrado.";
}







string Sistema::buscarVeiculo(const string chassi){

     // Iterar sobre as concessionárias para procurar o chassi em cada estoque de cada concessionaria
    for (auto& concessionaria : concessionarias) {

        auto& estoque = const_cast<vector<Veiculo*>&>(concessionaria.getEstoque()); //conversão da referência estoque que é constante para uma referência não constante usando o const_cast.
       
       //busca pelo veiculo com chassi pedido utilizando a função find_if
        auto it = std::find_if(estoque.begin(), estoque.end(), [&](Veiculo* veiculo) {
            return veiculo->getChassi() == chassi;
        });

        //Se o a função retornar um iterador apontando para o veiculo, logo it é diferente de estoque.end()
        if (it != estoque.end()) {
 
             std::string info = "Concessionaria: " + concessionaria.getNome() + "\n" +
                                      "Marca: " + (*it)->getMarca() + "\n" +
                                      "Preço: R$ " + std::to_string((*it)->getPreco()) + "\n" +
                                      "Chassi: " + (*it)->getChassi() + "\n" +
                                      "Ano: " + std::to_string((*it)->getAno()) + "\n" +
                                      (*it)->getAtributoDiferente() + "\n";

            return info; 
           
        }
    }

    return "Busca sem sucesso";

}











std::string Sistema::saveConcessionaria(const std::string concessionaria) {
    std::string caminhoArquivo = "./save/arquivo.txt";

    // Criação do objeto fstream para manipulação do arquivo
    std::fstream arquivo(caminhoArquivo, std::ios::out);

    if (arquivo.is_open()) {
        arquivo << "Este é um arquivo de exemplo da concessionaria "  << concessionaria << std::endl;
        arquivo.close();

        return "Concessionaria "+concessionaria+" criada com sucesso";
    } else {
        return "Não foi possível criar a concessionaria "+concessionaria;
    }
}







std::string Sistema::loadConcessionaria(const std::string arquivo) {

        return "loadConcessionaria "+arquivo;
    
}








std::string Sistema::listConcessionaria(const std::string concessionaria) {
     return "listConcessionaria " + concessionaria;
    
}







std::string Sistema::raisePrice(const std::string concessionaria) {
    // Criando um stream a partir da string 'concessionaria'
    istringstream buf(concessionaria);

    // Declarando variável
    string nomeConcessionaria, aumento;
    buf >> nomeConcessionaria >> aumento;
    std::string str = "raisePrice da "+nomeConcessionaria + " de "+aumento+"\n";
    return str;
    
}








/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */