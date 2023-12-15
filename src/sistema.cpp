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

// Método para 
string Sistema::quit() {
  return "Saindo...";
}



// Método para criar concessionária
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




 


// Método para adicionar um novo veículo a uma concessionária 
std::string Sistema::addVeiculo(const std::string nome, const std::string nomeComando) {
    // Convertendo a string 'nome' em um stream para facilitar a leitura dos dados
    std::istringstream buf(nome);

    std::string nomeDaConcessionaria, marca, preco, chassi, fabricacao, atributoDiferencial;
    buf >> nomeDaConcessionaria >> marca >> preco >> chassi >> fabricacao >> atributoDiferencial;

    // Convertendo strings de preço e fabricação para inteiros
    int precoV = std::stoi(preco);
    int fabricacaoV = std::stoi(fabricacao);

    // Obtendo um iterador para a concessionária pelo nome
    auto it = this->getIT(nomeDaConcessionaria);

    // Verificando se a concessionária foi encontrada
    if (it != concessionarias.end()) {
        // Verificando se o veículo já foi adicionado à concessionária
        if (it->veiculoJaAdicionado(chassi)) {
            std::stringstream ss;
            ss << "ERRO - Veículo " << chassi << " já adicionado à concessionária " << it->getNome();
            return ss.str(); // Mensagem de erro se o veículo já estiver presente na concessionária
        } else {
            Veiculo* novoVeiculo = nullptr;

            // Criando um novo objeto do tipo de veículo correspondente ao comando passado
            if (nomeComando == "add-car") {
                novoVeiculo = new Automovel(marca, precoV, chassi, fabricacaoV, atributoDiferencial);
            } else if (nomeComando == "add-bike") {
                novoVeiculo = new bike(marca, precoV, chassi, fabricacaoV, atributoDiferencial);
            } else if (nomeComando == "add-truck") {
                novoVeiculo = new Caminhao(marca, precoV, chassi, fabricacaoV, atributoDiferencial);
            }

            int sizeVetorAntes = it->getEstoque().size();
            int quantVeiculoAntes = it->getQuantidadeVeiculos();

            // Adicionando o novo veículo à concessionária
            it->addVeiculo(novoVeiculo);

            // Ordenar o estoque pelos últimos 5 dígitos numéricos do chassi
            it->ordenarPorChassi();

            int quantVeiculoDepois = it->getQuantidadeVeiculos();
            int sizeVetorDepois = it->getEstoque().size();

            // Calculando a nova quantidade de veículos na concessionária
            int novaQuantVeiculos = it->quantidadeAtualVeiculos(sizeVetorAntes, quantVeiculoAntes, quantVeiculoDepois, sizeVetorDepois);
            it->setQuantidadeVeiculos(novaQuantVeiculos);

            // Retornando uma mensagem indicando o sucesso da adição do veículo
            return "Adicionado veículo com sucesso.";
        }
    } else {
        return "ERRO - Concessionaria não encontrada."; // Mensagem de erro se a concessionária não for encontrada
    }
}









// Método para remover um veículo pelo número de chassi
std::string Sistema::removerVeiculo(const std::string chassi) {
    // Iterar sobre as concessionárias para procurar o chassi em cada estoque de cada concessionaria
    
    std::string opcao = "remover";
    std::string resultado;
    int saber = 0;

    // Realiza a busca do veículo pelo chassi com a opção de remoção
    resultado = this->buscarPorChassi(chassi, opcao, saber);

    if (saber == 1) {
        return resultado; // Retorna o resultado da remoção
    }

    return "Veículo " + chassi + " não encontrado."; // Mensagem de veículo não encontrado
}






// Método para buscar um veículo pelo número de chassi
std::string Sistema::buscarVeiculo(const std::string chassi) {
    // Iterar sobre as concessionárias para procurar o chassi em cada estoque de cada concessionaria
    std::string opcao = "buscar";
    std::string resultado;
    int saber = 0;

    // Realiza a busca do veículo pelo chassi com a opção de busca
    resultado = this->buscarPorChassi(chassi, opcao, saber);

    if (saber == 2) {
        return resultado; // Retorna o resultado da busca
    }

    return "Busca sem sucesso"; // Mensagem de busca sem sucesso
}









std::string Sistema::saveConcessionaria(const std::string nomeDaConcessionaria) {
    std::string caminhoArquivo = "./save/" + nomeDaConcessionaria + ".txt";

    // Criação do objeto fstream para manipulação do arquivo
    std::ofstream arquivo(caminhoArquivo); 

    if (arquivo.is_open()) {
        // Procurando a concessionária pelo nome dentro do vetor 'concessionarias'
        auto it = this -> getIT(nomeDaConcessionaria);

        if (it != concessionarias.end()) {
            std::string cnpj = it->getCnpj(); 
            std::string quantVeiculos = std::to_string(it->getQuantidadeVeiculos()); 

            std::string comando = "create-concessionaria " + nomeDaConcessionaria + " " + cnpj + " " + quantVeiculos + "\n";
            arquivo << comando; 
           
           // Percorrer o estoque da concessionária e criar comandos para cada veículo
            for (auto veiculo : it->getEstoque()) {
                std::string tipoVeiculo = veiculo->getTipo(); // Obtém o tipo do veículo

             
                std::string comandoVeiculo; // Comando específico para cada veículo
                std::string marcaModelo, atributoDiferencial, chassi;
                 int preco = 0; int ano = 0;

                // Lógica para definir o comandoVeiculo com base nas informações do veículo
                if (tipoVeiculo == "Automovel") {
                    Automovel* automovel = dynamic_cast<Automovel*>(veiculo); // Converte para Automovel
                    if (automovel) {

                       this -> getAtributos(marcaModelo, preco, chassi, ano, atributoDiferencial, automovel);

                        // criar o comandoVeiculo
                        comandoVeiculo = "add-car " + nomeDaConcessionaria + " " + marcaModelo + " " + std::to_string(preco) + " " + chassi + " " + std::to_string(ano) + " " + atributoDiferencial + "\n";
                    }

                } else if (tipoVeiculo == "bike") {
                    
                    bike* moto = dynamic_cast<bike*>(veiculo); // Converte para Bike
                    if (moto) {
                       
                       this -> getAtributos(marcaModelo, preco, chassi, ano, atributoDiferencial, moto);

                        // Crie o comandoVeiculo com as informações da Bike
                        comandoVeiculo = "add-bike " + nomeDaConcessionaria + " " + marcaModelo + " " + std::to_string(preco) + " " + chassi + " " + std::to_string(ano) + " " + atributoDiferencial + "\n";
                    }
                } else if (tipoVeiculo == "Caminhao") {
                    
                    Caminhao* caminhao = dynamic_cast<Caminhao*>(veiculo); // Converte para Caminhao
                    if (caminhao) {
                        
                        this -> getAtributos(marcaModelo, preco, chassi, ano, atributoDiferencial, caminhao);

                        // Crie o comandoVeiculo com as informações do Caminhao
                        comandoVeiculo = "add-truck " + nomeDaConcessionaria + " " + marcaModelo + " " + std::to_string(preco) + " " + chassi + " " + std::to_string(ano) + " " + atributoDiferencial + "\n";
                    }
                }

                arquivo << comandoVeiculo; // Escreve o comandoVeiculo no arquivo
            }

            arquivo.close();

            return "Arquivo " + nomeDaConcessionaria + ".txt criado com sucesso";
        }
        
    } else {
        return "Não foi possível criar o arquivo " + nomeDaConcessionaria + ".txt\n";
    }

    return "Concessionaria não encontrada";
}







// Método que carrega informações de uma concessionária a partir de um arquivo.
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

                // Criando uma nova concessionária com os dados fornecidos
                std::string arg = nome + " " + cnpj + " " + quantidade;
                this->create_concessionaria(arg);
            } else if (comando == "add-car" || comando == "add-bike" || comando == "add-truck") {
                std::string nome, marca, preco, chassi, ano, atributoDiferencial;
                iss >> nome >> marca >> preco >> chassi >> ano >> atributoDiferencial;

                // Adicionando um novo veículo à concessionária com os dados fornecidos
                std::string arg = nome + " " + marca + " " + preco + " " + chassi + " " + ano + " " + atributoDiferencial;
                this->addVeiculo(arg, comando);
            }
        }

        arquivo.close(); // Fechando o arquivo após a leitura
        return "Concessionaria "+concessionaria+" criada com sucesso"; // Mensagem de sucesso
    } else {
        return "Não foi possível abrir o arquivo.\n"; // Mensagem de erro
    }
}








// Método que lista informações sobre os veículos disponíveis em uma concessionária.
std::string Sistema::listConcessionaria(const std::string nomeConcessionaria) {
    // Inicialização dos contadores e valores iniciais
    int contAutomovel = 0, contBike = 0, contCaminhao = 0;
    int valorAutomovel = 0, valorBike = 0, valorCaminhao = 0, valorFrota = 0;

    std::string opcao = "list"; // Define a opção como 'list'

    // Busca por informações dos veículos na concessionária
    this->buscarPorNome(nomeConcessionaria, 0, opcao, contAutomovel, contBike, contCaminhao, valorAutomovel, valorBike, valorCaminhao, valorFrota);

    // Construção da string com informações sobre os veículos na concessionária
    std::string resultado = "Total de Automóveis: " + std::to_string(contAutomovel) + "; Valor total: R$ " + std::to_string(valorAutomovel) + "\n" +
                            "Total de Motos: " + std::to_string(contBike) + "; Valor total: R$ " + std::to_string(valorBike) + "\n" +
                            "Total de Caminhões: " + std::to_string(contCaminhao) + "; Valor total: R$ " + std::to_string(valorCaminhao) + "\n" +
                            "Valor Total da frota: R$ " + std::to_string(valorFrota) + "\n";

    return resultado; // Retorna as informações sobre os veículos na concessionária
}






// Método que permite dar um aumento ao preço de todos os automóveis
std::string Sistema::raisePrice(const std::string comando) {
   
    // Analisar o argumento da chamada para obter a concessionária e a porcentagem de aumento
    std::istringstream iss(comando);
    std::string nomeConcessionaria, valorAumento, opcao;
    iss >> nomeConcessionaria >> valorAumento;


    double aumento = std::stod(valorAumento); // tipo double
    opcao = "price"; //opçao que diferencia esse metodo para o metodo de buscarPorNome 

     // Inicialização dos contadores e valores iniciais
    int contAutomovel = 0, contBike = 0, contCaminhao = 0;
    int valorAutomovel = 0, valorBike = 0, valorCaminhao = 0, valorFrota = 0;


    this->buscarPorNome(nomeConcessionaria, aumento, opcao,
                     contAutomovel, contBike, contCaminhao,
                     valorAutomovel, valorBike, valorCaminhao, valorFrota);

         // Strings para armazenar os aumentos por tipo de veículo
        std::string aumentoAutomoveis = "Aumento de 10% nos preços de automóveis da Concessionária " + nomeConcessionaria + " realizado";
        std::string aumentoMotos = "Aumento de 20% nos preços de motos da Concessionária " + nomeConcessionaria + " realizado";
        std::string aumentoCaminhoes = "Aumento de 30% nos preços de caminhões da Concessionária " + nomeConcessionaria + " realizado";


       

        // Retornar as mensagens de aumento para cada tipo de veículo
        return aumentoAutomoveis + "\n" + aumentoMotos + "\n" + aumentoCaminhoes + "\n";
    

    return "Concessionária não encontrada";
}





//Métodos usados frequentemente:

std::string Sistema::buscarPorChassi(const std::string chassi, const std::string opcao, int& saber) {
    // Percorre cada concessionária no vetor 'concessionarias'
    for (auto& concessionaria : concessionarias) {
        // Obtém uma referência ao estoque da concessionária
        auto& estoque = const_cast<vector<Veiculo*>&>(concessionaria.getEstoque());

        // Encontra o veículo pelo número do chassi
        auto it = std::find_if(estoque.begin(), estoque.end(), [&](Veiculo* veiculo) {
            return veiculo->getChassi() == chassi;
        });

        // Verifica se o veículo foi encontrado
        if (it != estoque.end()) {
            // Caso a opção seja 'remover'
            if (opcao == "remover") {
                // Remove o veículo da concessionária e libera a memória
                delete *it;
                estoque.erase(it);
                saber = 1;
                // Retorna a mensagem de veículo removido
                return "Veículo " + chassi + " removido da concessionária " + concessionaria.getNome();
            }
            // Caso a opção seja 'buscar'
            else if (opcao == "buscar") {
                saber = 2;
                // Cria uma string com informações detalhadas sobre o veículo encontrado
                std::string info = "Concessionaria: " + concessionaria.getNome() + "\n" +
                                    "Marca: " + (*it)->getMarca() + "\n" +
                                    "Preço: R$ " + std::to_string((*it)->getPreco()) + "\n" +
                                    "Chassi: " + (*it)->getChassi() + "\n" +
                                    "Ano: " + std::to_string((*it)->getAno()) + "\n" +
                                    (*it)->getAtributoDiferente() + "\n";
                // Retorna as informações do veículo
                return info;
            }
        }
    }

    // Se nenhum veículo for encontrado
    return "Veículo " + chassi + " não encontrado.";
}


std::vector<Concessionaria>::iterator Sistema::getIT(std::string nomeDaConcessionaria) {
  // Procurando a concessionária pelo nome dentro do vetor 'concessionarias'
  auto it = std::find_if(concessionarias.begin(), concessionarias.end(),
                         [&](const Concessionaria &concessionaria) {
                           return concessionaria.getNome() == nomeDaConcessionaria;
                         });

  return it; // Retorna um iterador apontando para a concessionária encontrada ou para o final se não encontrada

}


void Sistema::buscarPorNome(const std::string nomeConcessionaria, double aumento, const std::string opcao, 
                            int& contAutomovel, int& contBike, int& contCaminhao, int& valorAutomovel, 
                            int& valorBike, int& valorCaminhao, int& valorFrota) {
  // Itera sobre as concessionárias
  for (auto& concessionaria : concessionarias) {
    // Verifica se o nome da concessionária corresponde ao nome passado
    if (concessionaria.getNome() == nomeConcessionaria) {
      auto& estoque = concessionaria.getEstoque(); // Obtém o estoque da concessionária

      // Itera sobre os veículos do estoque
      for (auto veiculo : estoque) {

        // Verifica o tipo de veículo e executa operações específicas com base na variável 'opcao', que pode ser 'list' ou 'price'.
        // Ambos os métodos 'list' e 'price' compartilham essencialmente o mesmo código para diferentes finalidades.

        if (dynamic_cast<Automovel*>(veiculo) != nullptr) {
          if (opcao == "list") {
            contAutomovel++;
            valorAutomovel += veiculo->getPreco();
          } else if (opcao == "price") {
            double precoAtual = veiculo->getPreco();
            veiculo->setPreco(precoAtual * (1 + (aumento / 100))); // Aumento para automóveis
          }
        } else if (dynamic_cast<bike*>(veiculo) != nullptr) {
          if (opcao == "list") {
            contBike++;
            valorBike += veiculo->getPreco();
          } else if (opcao == "price") {
            double precoAtual = veiculo->getPreco();
            veiculo->setPreco(precoAtual * (1 + (2 * aumento / 100))); // Aumento para motos
          }
        } else if (dynamic_cast<Caminhao*>(veiculo) != nullptr) {
          if (opcao == "list") {
            contCaminhao++;
            valorCaminhao += veiculo->getPreco();
          } else if (opcao == "price") {
            double precoAtual = veiculo->getPreco();
            veiculo->setPreco(precoAtual * (1 + (3 * aumento / 100))); // Aumento para caminhões
          }
        }
        // Se a opção for "list", atualiza o valor total da frota
        if (opcao == "list") {
          valorFrota += veiculo->getPreco();
        }
      }
      break; // Parando após encontrar a concessionária
    }
  }
}


// Método genérico para obter os atributos de um veículo (tipo T).
template<typename T>
void Sistema::getAtributos(std::string& marcaModelo, int& preco, std::string& chassi,
                  int& ano, std::string& atributoDiferencial, T* veiculo) {

 // Obter os atributos
  marcaModelo = veiculo->getMarca();    // Obtendo a marca/modelo do veículo
  preco = veiculo->getPreco();          // Obtendo o preço do veículo
  chassi = veiculo->getChassi();        // Obtendo o número de chassi do veículo
  ano = veiculo->getAno();              // Obtendo o ano do veículo
  atributoDiferencial = veiculo->getAtributo();   // Obtendo um atributo diferencial do veículo
}


