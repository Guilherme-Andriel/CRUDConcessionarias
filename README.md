# Concessionaria

### Table of Contents
1. [Problema](#1-problema)
2. [Orientações](#2-orientações)
3. [Entrega](#3-entrega)
4. [Avaliação](#4-avaliação)

# Motivação

## Create/Read/Update/Delete - Crud
O termo CRUD refere-se às principais manipulações sobre os dados que modelam a aplicação. Entender como modelar os dados e como realizar atividades de crud é um conhecimento muito importante em diversas áreas, mais especificamente na área de serviços web e distribuídos, sobretudo em aplicações de backend. Normalmente, a especificação do problema já indica o conjunto de dados a ser manipulado, e o trabalho de programação está em modelar classes que representam os dados e realizar as ações sobre os dados como especificado pela aplicação. Nesta atividade iremos praticar algumas operações comuns em aplicações que envolvem CRUD.

# 1. Problema

Implemente um programa em C++ que atenda aos seguintes critérios:

1. Uma `Concessionária` pode comercializar diversos tipos de `Veículos`: `Automóveis`, `Motos` e `Caminhões`. Cada Concessionária possui um `nome`, `CNPJ` e número de veículos no `estoque`.

2. Todo `Veículo` possui os seguintes campos: `marca`, `preço`, número do `chassi` e ano de `fabricação`. Apenas `Automóveis` possuem um atributo relativo ao `tipo de motor` (gasolina ou elétrico); apenas `Motos` possuem um atributo relativo ao `modelo` (clássico ou esportivo); apenas `Caminhões` possuem um atributo relativo ao `tipo de carga` (comum ou perigosa). Considere que os veículos podem ser ordenados pelos últimos 5 dígitos do número de chassi.

3. O programa deverá permitir criar uma `Concessionária`. Exemplo:
```
$ create-concessionaria IMD_SA 11.111.111/0001-11 0
```

4. O programa deverá permitir que se adicione um veículo, seja ele um automóvel, moto ou caminhão, a uma concessionária. Exemplo: 
```
$ add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
$ add-truck IMD_SA Scania 700000 7BRBLQHEXG0208811 2010 perigosa
```

5. O programa não deve permitir adicionar um veículo que já tenha sido anteriormente adicionado, sendo neste caso exibida uma mensagem de erro. Exemplo:
```
$ add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
ERRO - Veículo 9BRBLWHEXG0107721 já adicionado à concessionária IMD_SA
```

6. O programa deve permitir remover um veículo a partir do número de seu chassi. Exemplo:
```
$ remove-vehicle 9BRBLWHEXG0107721
Veículo 9BRBLWHEXG0107721 removido da concessionária IMD_SA
```

7. O programa deve permitir que se realize uma busca por número de chassi. Caso o veículo pertença à uma concessionária, o programa deve exibir na tela seus atributos. Caso contrário, deve ser exibida uma mensagem indicando a busca sem sucesso. Exemplo:
```
$ search-vehicle 9BRBLWHEXG0107721
Concessionaria: IMD_SA
Marca: Toyota
Preço: R$ 100000 
Chassi: 9BRBLWHEXG0107721 
Ano:2019
Tipo de motor: gasolina
```

8. O programa deverá permitir escrever em um arquivo de texto todo o estoque de uma concessionária, incluindo os atributos comuns e particulares de cada veículo. Exemplo:
```
$ save-concessionaria IMD_SA
Arquivo IMD_SA.txt criado com sucesso
```

9. O programa deverá permitir criar/recuperar os dados de uma concessionária à partir de um arquivo de texto no formato descrito no item anterior. Exemplo:
```
$ load-concessionaria IMD_SA.txt
Concessionaria IMD_SA criada com sucesso
```

10. O programa deve possuir uma função para listar a frota total de cada tipo de veículo e o valor total dos veículos de uma dada concessionária.
Exemplo:
```
$ list-concessionaria IMD_SA
Concessionaria IMD_SA
Total de Automóveis: 1; Valor total: R$ 100000
Total de Motos: 0; Valor total: R$ 0
Total de Caminhões: 1; Valor total: R$ 700000
Valor Total da frota: R$ 800000
```

11. O programa deverá permitir que seja dado um aumento de [X, 2X, 3X]% ao preço de todos os automóveis, motos e caminhões de uma determinada concessionária, respectivamente. Exemplo:
```
$ raise-price IMD_SA 10
Aumento de 10% nos preços de automóveis da Concessionária IMD_SA realizado
Aumento de 20% nos preços de motos da Concessionária IMD_SA realizado
Aumento de 30% nos preços de caminhões da Concessionária IMD_SA realizado
```

12. O programa deverá ser finalizado pelo comando `quit`. Exemplo:
```
$ quit
Saindo...
```

# 2. Orientações

- Utilize estritamente recursos da linguagem C++.
- Durante a compilação do seu código fonte, você deverá habilitar a exibição de mensagens de aviso (warnings) e vazamento de memória
- Aplique boas práticas de programação. Codifique o programa de maneira legível (com indentação de código fonte, nomes consistentes, etc.). Modularize e comente seu código
- Garanta que seu programa funcione de forma correta e eficiente. Pense também nas possíveis entradas que poderão ser utilizadas para testar apropriadamente o seu programa e trate adequadamente possíveis entradas consideradas inválidas
- A resolução da questão deve conter um arquivo makefile responsável pela compilação e ligação
- Quando não especificado, a modelagem das classes é livre, ou seja, inclua os atributos que você considerar importantes para resolver a questão
- Utilize os recursos e técnicas discutidos ao longo da disciplina

# 3. Entrega
* Enviar via repositório (GitHub Classroom) os arquivos solicitados
* Incluir um arquivo texto **avaliacao** contendo: 
  * a identificação completa do aluno 
  * a descrição de como compilar e rodar o programa, incluindo um roteiro de entradas e comandos que destaquem as funcionalidades 
  * a descrição das limitações (caso existam) do programa e quaisquer dificuldades encontradas
  * o formulário de autoavaliação preenchido
* Incluir print da tela demonstrando a compilação bem sucedida
* Incluir prints de execução do programa demonstrando *todas* as funcionalidades implementadas
* Enviar um arquivo .zip com o repositório completo (sem o executável e arquivos objeto) via SIGAA
* **Datas**
  * 20/11/23: envio U2 (comandos 1 a 6)
  * 12/12/23: entrega completa
  * 14/12/23 e 19/12/23: entrevistas

# 4. Avaliação

* O trabalho será avaliado sob os critérios indicados no arquivo **avaliacao**
* **apenas trabalhos acompanhados do arquivo avaliacao preenchido serão avaliados**
* **a ausência dos prints de tela implicam em redução de 50% da nota**
* Entregas atrasadas não serão aceitas

## Authorship

**Original problem: Silvio Sampaio**

**Code Snippets: Julio Melo, [julio@imd.ufrn.br](mailto:julio@imd.ufrn.br)**

**Extensions and current adaptation: Renan Moioli, [renan.moioli@imd.ufrn.br](mailto:renan.moioli@imd.ufrn.br)**


