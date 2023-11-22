
# Identificação

* Nome: GUILHERME ANDRIEL FIGUEIREDO MEDEIROS DA SILVA.

* Matrícula: 20220050240
  
# Compilação  

* Abra o terminal e navegue até o diretório onde estão os arquivos. Digite o seguinte comando "make" para compilar o programa por meio do Makefile. Isso criará um executável chamado "programa" dentro de uma pasta chamada "bin". No terminal, após a compilação bem-sucedida, digite o comando "./bin/programa" para iniciar o programa e e apresentar o menu de interações. 

Para Criar uma concessionária, por exemplo, digite o comando: 
"create-concessionaria IMD_SA 11.111.111/0001-11 0"

- Somente serão criadas concessionárias com nomes e CNPJ diferentes. Caso contrário, uma mensagem de inválida será exibida.
- Mensagem de sucesso: "Concessionária criada com sucesso."
- Mensagem de erro: "Concessionária já criada antes."

Para adicionar veículos, utilize os comandos conforme o tipo de veículo:
- Carro: "add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina" (Carro)
- Caminhão: "add-truck IMD_SA Scania 700000 7BRBLQHEXG0208811 2010 perigosa" (Caminhão)
- Moto: "add-bike IMD_SE Honda 100000 9BRBLWHEXG0107722 2019 clássico" (Motp)

- Mensagem de sucesso: "Adicionado veiculo com sucesso."
- Não é possível adicionar veículos já existentes, apenas veículos com chassi diferente. Mensagem de erro: "ERRO - Veículo 9BRBLWHEXG0107721 já adicionado à concessionária IMD_SA".
- Somente veículos podem ser adicionados a concessionárias existentes. Mensagem de erro: "ERRO - Concessionaria não encontrada."

Para Remover um veículo pelo número do chassi, por exemplo, digite o comando: "remove-vehicle 9BRBLWHEXG0107721"

- Mensagem de sucesso: "Veículo 9BRBLWHEXG0107721 removido da concessionária IMD_SA".
- Mensagem de erro para chassi não existente: "Veículo 9BRBLWHEXG0107721 não encontrado."

Para Finalizar o programa digite o comando: "quit"

- Mensagem: "Saindo..."


# Limitações

* Encontrei desafios ao criar uma lógica para o caso de criar uma concessionária com uma quantidade inicial de veículos diferente de zero. Quando adicionava um veículo, precisava atualizar essa quantidade para refletir o número correto de veículos no vetor. Para resolver isso, criei o método 'quantidadeAtualVeiculos(int sizeVetorAntes, int quantVeiculoAntes, int quantVeiculoDepois, int sizeVetorDepois)'. Além disso, enfrentei alguns problemas relacionados a vazamento de memória e acessos incorretos a regiões de memória que já haviam sido liberadas. Quebrei muito a cabeça para conseguir resolver e acho que até então, pelos meus testes, está tudo ocorrendo certo. O método de busca pelo chassi e exibição dos atributos do veículo teve problema em diferenciar o método de cada classe: automóvel, bike e caminhão para conseguir mostrar qual era o veículo. Faça o teste na pasta 'test' com o comando 'bin/programa < test/buscarPorChassi.txt' e verá que há repetição de 'Tipo de motor:' para qualquer veiculo. Coloquei print do caso (erroExibicaoDeBusca.png).  
   
# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | ** 10/ 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | ** 10/ 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | ** 10/ 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | ** 10/ 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | ** 10/ 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **... / 15 - Bônus: ...**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **... / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **... / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **... / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | ** 10/ 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | ** 5/ 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | ** 5/ 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | ** 15/ 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **... / 150 ** pontos (sem bônus)
 
 **... / 200 ** pontos (com bônus)
