#include "executor.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <queue>
#include <thread> // Adicionando a biblioteca necessária para usar 'std::this_thread'
#include <chrono>  // Adicionando a biblioteca necessária para usar 'std::chrono'

using namespace std;

// Função de apoio que recebe um istringstream e
// le todo texto restante até o fim da linha
string restoDe(istringstream &ss) {
  string resto;
  getline(ss, resto, '\0'); // ler o resto da linha
  if (resto != "" && (resto[0] == ' ' || resto[0] == '\t')) {
    resto = resto.substr(1); // o primeiro caractere é um espaço, descartar
  }
  return resto;
}

// Construtor. Recebe uma referência ao sistema que vai operar
// Guarda o seu endereço para executar as operações.
Executor::Executor(Sistema &sistema) {
  this->sair = false;
  this->sistema = &sistema;
}

// Inicia o processamento dos comentarios.
// Esse método recebe por exemplo o "cin" e o "cout" no main
// Dessa forma ele faz o necessário para ler 1 comando por linha e
// o processar corretamente, colocando no stream de saída o resultado de cada um.
void Executor::iniciar(istream &inputStream, ostream &outputStream) {
  
cout << "Bem-vindo ao sistema de gerenciamento de veículos!" << endl;
    cout << "===============================================" << endl;
    cout << "Carregando o sistema..." << endl;

    // Simulando uma pequena animação de carregamento
    for (int i = 0; i < 20; ++i) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << endl << "Sistema carregado com sucesso!" << endl;
    cout << "===============================================" << endl;

    // Apresentação das funcionalidades
    cout << "Por favor, escolha uma das opções abaixo:" << endl;
    cout << "1. Criar uma nova concessionária (create-concessionaria)" << endl;
    cout << "2. Adicionar um veículo (add-car, add-bike, add-truck)" << endl;
    cout << "3. Remover um veículo (remove-vehicle)" << endl;
    cout << "4. Pesquisar veículo por chassi (search-vehicle)" << endl;
    cout << "5. Salvar estoque de uma concessionária (save-concessionaria)" << endl;
    cout << "6. Carregar estoque de uma concessionária (load-concessionaria)" << endl;
    cout << "7. Listar a frota e valor total por tipo de veículo (list-concessionaria)" << endl;
    cout << "8. Aumentar preço dos veículos (raise-price)" << endl;
    cout << "9. Sair do sistema (quit)" << endl;
    cout << "Digite o comando desejado:" << endl;

  string linha, saida;
  this->sair = false;
  while (! this->sair)
  {
    if (std::getline(inputStream, linha)) {
      saida = processarLinha(linha);
      outputStream << saida << endl;
    }
  }
}

// Método responsável por processar cada linha, capturando o nome do comando
// e seus parâmetros em variáveis e executar o método correspondente no sistema
string Executor::processarLinha(string linha) {
  istringstream buf(linha);
  string nomeComando;
  buf >> nomeComando;

  if (nomeComando.empty()) {
    return "Comando Inválido <vazio>";
  }

  if (nomeComando == "quit" ) {
    this->sair = true;
    return sistema->quit();
  }
  else if (nomeComando == "create-concessionaria") {
    string nome;    
    nome = restoDe(buf);
    return sistema->create_concessionaria(nome);
  } 
  else if (nomeComando == "add-car" || nomeComando == "add-bike" || nomeComando == "add-truck") {
    string nome;    
    nome = restoDe(buf);
    return sistema->addVeiculo(nome);
  }else if (nomeComando == "remove-vehicle") {
    string chassi;    
    chassi = restoDe(buf);
    return sistema->removerVeiculo(chassi);
  }

  return "Erro";  
}


