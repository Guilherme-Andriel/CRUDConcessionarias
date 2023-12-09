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
    istringstream buf(nome);

    string nomeDaConcessionaria, marca, preco, chassi, fabricacao, atributoDiferencial;
    buf >> nomeDaConcessionaria >> marca >> preco >> chassi >> fabricacao >> atributoDiferencial;

    int precoV = std::stoi(preco);
    int fabricacaoV = std::stoi(fabricacao);

    auto it = std::find_if(concessionarias.begin(), concessionarias.end(), [&](const Concessionaria& concessionaria) {
        return concessionaria.getNome() == nomeDaConcessionaria;
    });

    if (it != concessionarias.end()) {
        if (it->veiculoJaAdicionado(chassi)) {
            std::stringstream ss;
            ss << "ERRO - Veículo " << chassi << " já adicionado à concessionária " << it->getNome();
            return ss.str();
        } else {
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

            return "Adicionado veículo com sucesso.";
        }
    } else {
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








std::string Sistema::saveConcessionaria(const std::string nomeConcessionaria) {
    std::string caminhoArquivo = "./save/" + nomeConcessionaria + ".txt";

    // Criação do objeto fstream para manipulação do arquivo
    std::ofstream arquivo(caminhoArquivo); 

    if (arquivo.is_open()) {
        // Procurando a concessionária pelo nome dentro do vetor 'concessionarias'
        auto it = std::find_if(concessionarias.begin(), concessionarias.end(), [&](const Concessionaria& concessionaria) {
            return concessionaria.getNome() == nomeConcessionaria;
           
        
        });

        if (it != concessionarias.end()) {
            std::string cnpj = it->getCnpj(); 
            std::string quantVeiculos = std::to_string(it->getQuantidadeVeiculos()); 

            std::string comando = "create-concessionaria " + nomeConcessionaria + " " + cnpj + " " + quantVeiculos + "\n";
            arquivo << comando; 
           
           // Percorrer o estoque da concessionária e criar comandos para cada veículo
            for (auto veiculo : it->getEstoque()) {
                std::string tipoVeiculo = veiculo->getTipo(); // Obtém o tipo do veículo

             
                std::string comandoVeiculo; // Comando específico para cada veículo

                // Lógica para definir o comandoVeiculo com base nas informações do veículo
                if (tipoVeiculo == "Automovel") {
                    Automovel* automovel = dynamic_cast<Automovel*>(veiculo); // Converte para Automovel
                    if (automovel) {

                        // Use os métodos de Automovel para obter os atributos
                        std::string marcaModelo = automovel->getMarca(); // MarcaModelo
                        int preco = automovel->getPreco(); // Preco
                        std::string chassi = automovel->getChassi(); // Chassi
                        int ano = automovel->getAno(); // Ano
                        std::string tipoMotor = automovel->getAtributo(); // Tipo

                        // criar o comandoVeiculo
                        comandoVeiculo = "add-car " + nomeConcessionaria + " " + marcaModelo + " " + std::to_string(preco) + " " + chassi + " " + std::to_string(ano) + " " + tipoMotor + "\n";
                    }

                } else if (tipoVeiculo == "bike") {
                    
                    bike* moto = dynamic_cast<bike*>(veiculo); // Converte para Bike
                    if (moto) {
                        // Use os métodos de Bike para obter os atributos
                        std::string marcaModelo = moto->getMarca(); // MarcaModelo
                        int preco = moto->getPreco(); // Preco
                        std::string chassi = moto->getChassi(); // Chassi
                        int ano = moto->getAno(); // Ano
                        std::string modelo = moto->getAtributo(); // Tipo

                        // Crie o comandoVeiculo com as informações da Bike
                        comandoVeiculo = "add-bike " + nomeConcessionaria + " " + marcaModelo + " " + std::to_string(preco) + " " + chassi + " " + std::to_string(ano) + " " + modelo + "\n";
                    }
                } else if (tipoVeiculo == "Caminhao") {
                    
                    Caminhao* caminhao = dynamic_cast<Caminhao*>(veiculo); // Converte para Caminhao
                    if (caminhao) {
                        // Use os métodos de Caminhao para obter os atributos
                        std::string marcaModelo = caminhao->getMarca(); // MarcaModelo
                        int preco = caminhao->getPreco(); // Preco
                        std::string chassi = caminhao->getChassi(); // Chassi
                        int ano = caminhao->getAno(); // Ano
                        std::string tipoCarga = caminhao->getAtributo(); // Tipo

                        // Crie o comandoVeiculo com as informações do Caminhao
                        comandoVeiculo = "add-truck " + nomeConcessionaria + " " + marcaModelo + " " + std::to_string(preco) + " " + chassi + " " + std::to_string(ano) + " " + tipoCarga + "\n";
                    }
                }

                arquivo << comandoVeiculo; // Escreve o comandoVeiculo no arquivo
            }

            arquivo.close();

            return "Arquivo " + nomeConcessionaria + ".txt criado com sucesso";
        }
        
    } else {
        return "Não foi possível criar o arquivo " + nomeConcessionaria + ".txt\n";
    }

    return "Concessionaria não encontrada";
}







std::string Sistema::loadConcessionaria(const std::string arq) {
    std::ifstream arquivo("./save/" + arq); // Abrindo o arquivo
    std::string concessionaria;

    if (arquivo.is_open()) {
        std::string linha;

        while (getline(arquivo, linha)) {
            std::istringstream iss(linha);
            std::string comando;

            iss >> comando;

            if (comando == "create-concessionaria") {
                std::string nome, cnpj, quantidade;
                iss >> nome >> cnpj >> quantidade;

                concessionaria = nome;

                std::string arg = nome + " " + cnpj + " " + quantidade;
                this->create_concessionaria(arg);
            } else if (comando == "add-car" || comando == "add-bike" || comando == "add-truck") {
                std::string nome, marca, preco, chassi, ano, atributoDiferencial;
                iss >> nome >> marca >> preco >> chassi >> ano >> atributoDiferencial;
                std::string arg = nome + " " + marca + " " + preco + " " + chassi + " " + ano + " " + atributoDiferencial;
                this->addVeiculo(arg, comando);
            }
        }

        arquivo.close(); // Fechando o arquivo após a leitura
        return "Concessionaria "+concessionaria+" criada com sucesso";
    } else {
        return "Não foi possível abrir o arquivo.\n";
    }
}








std::string Sistema::listConcessionaria(const std::string nomeConcessionaria) {
    int contAutomovel = 0, contBike = 0, contCaminhao = 0;
    int valorAutomovel = 0, valorBike = 0, valorCaminhao = 0, valorFrota = 0;

    for (auto& concessionaria : concessionarias) {
        if (concessionaria.getNome() == nomeConcessionaria) {
            auto& estoque = concessionaria.getEstoque(); // Obtendo o estoque da concessionária

            for (auto veiculo : estoque) {
                // Verificando o tipo de veículo e contando-os
                if (dynamic_cast<Automovel*>(veiculo) != nullptr) {
                    contAutomovel++;
                    valorAutomovel += veiculo->getPreco();
                } else if (dynamic_cast<bike*>(veiculo) != nullptr) {
                    contBike++;
                    valorBike += veiculo->getPreco();
                } else if (dynamic_cast<Caminhao*>(veiculo) != nullptr) {
                    contCaminhao++;
                    valorCaminhao += veiculo->getPreco();
                }
                valorFrota += veiculo->getPreco();
            }
            break; // Parando após encontrar a concessionária
        }
    }

    std::string resultado = "Total de Automóveis: " + std::to_string(contAutomovel) + "; Valor total: R$ " + std::to_string(valorAutomovel) + "\n" +
                            "Total de Motos: " + std::to_string(contBike) + "; Valor total: R$ " + std::to_string(valorBike) + "\n" +
                            "Total de Caminhões: " + std::to_string(contCaminhao) + "; Valor total: R$ " + std::to_string(valorCaminhao) + "\n" +
                            "Valor Total da frota: R$ " + std::to_string(valorFrota) + "\n";

    return resultado;
}








std::string Sistema::raisePrice(const std::string comando) {
    // Analisar o comando para obter a concessionária e a porcentagem de aumento
    std::istringstream iss(comando);
    std::string nomeConcessionaria, valorAumento;
    iss >> nomeConcessionaria >> valorAumento;

    // Encontrar a concessionária
    auto it = std::find_if(concessionarias.begin(), concessionarias.end(), [&](const Concessionaria& concessionaria) {
        return concessionaria.getNome() == nomeConcessionaria;
    });

    if (it != concessionarias.end()) {
        double aumento = std::stod(valorAumento);

         // Strings para armazenar os aumentos por tipo de veículo
        std::string aumentoAutomoveis = "Aumento de 10% nos preços de automóveis da Concessionária " + nomeConcessionaria + " realizado";
        std::string aumentoMotos = "Aumento de 20% nos preços de motos da Concessionária " + nomeConcessionaria + " realizado";
        std::string aumentoCaminhoes = "Aumento de 30% nos preços de caminhões da Concessionária " + nomeConcessionaria + " realizado";


        // Aplicar o aumento a cada tipo de veículo
        for (auto veiculo : it->getEstoque()) {
            if (veiculo) {
            if (dynamic_cast<Automovel*>(veiculo) != nullptr) {
                double precoAtual = veiculo->getPreco();
                veiculo->setPreco(precoAtual * (1 + (aumento / 100))); // Aumento para automóveis
            } else if (dynamic_cast<bike*>(veiculo) != nullptr) {
                double precoAtual = veiculo->getPreco();
                veiculo->setPreco(precoAtual * (1 + (2 * aumento / 100))); // Aumento para motos
            } else if (dynamic_cast<Caminhao*>(veiculo) != nullptr) {
                double precoAtual = veiculo->getPreco();
                veiculo->setPreco(precoAtual * (1 + (3 * aumento / 100))); // Aumento para caminhões
            }
            }
        }

        // Retornar as mensagens de aumento para cada tipo de veículo
        return aumentoAutomoveis + "\n" + aumentoMotos + "\n" + aumentoCaminhoes + "\n";
    }

    return "Concessionária não encontrada";
}




