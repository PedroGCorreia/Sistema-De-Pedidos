# Projeto prático da disciplina de estrutura de dados
* Foi desenvolvido um sistema que utiliza duas filas e uma lista em liguagem C para organizar pedidos em um restaurante

## Desenvolvimento
No desenvolvimento foram utilizadas:
* Duas filas dinâmicas com encadeamento simples e com iterador: uma com os pedidos não iniciados e outra com os pedidos concluídos;
* Uma lista dinâmica, circular, duplamente encadeada, com sentinela e iterador: que contém os pedidos em andamento;
* Além de um biblioteca que funciona para criar a interface do sistema.

### Sobre a implementação da estrutura fila
* <strong>Struct fila</strong> - deve ser criada no arquivo main.c pelo usuário;
* <strong>fila CriaFila()</strong> - função para inicializar a fila declarada pelo usuário e retornar o endereço alocado para ela;
* <strong>int FilaVazia(fila f)</strong> - função para verificar se a fila está vazia, ou seja, não possui nenhum elemento;
* <strong>int FilaCheia(fila f)</strong> - função para verificar se o vetor que armazena os elementos da fila atingiu sua capacidade máxima;
* <strong>unsigned TamanhoFila(fila f)</strong> - função que retorna a quantidade de elementos da fila;
* <strong>void InsercaoFila(fila f, T p)</strong> - função que insere um elemento, que é passado pelo parâmetro p, no final da fila;
* <strong>void RemocaoFila(fila f)</strong> - função que remove o elemento do início da fila, para utilizar essa função é necessária a verificação FilaVazia, pois se a fila não possuir elementos não pode ocorrer uma remoção;
* <strong>int Inicio(fila f)</strong> - função que retorna o índice do vetor onde está o primeiro elemento da fila;
* <strong>int Final(fila f)</strong> - função que retorna o índice do vetor onde está o último elemento da fila;
* <strong>T Elemento(fila f, int i)</strong> - função que retorna as informações de um elemento na posição i do vetor que armazena os elementos da fila;
* <strong>T PrimeiroElemento(fila f)</strong> - função que retorna as informações do primeiro elemento da fila, no caso ela é do tipo T pois retorna os dados de uma struct que foi definida como T;
* <strong>void DestroiFila(fila f)</strong> - função que destrói a fila, desalocando a memória tanto o vetor que contém os elementos da fila, quanto a estrutura da fila.
* <strong>Obs1.:</strong> a fim de que as funções funcionem corretamente nessa estrutura é necessário que a CriaFila tenha sido chamada uma única vez antes da chamada das demais funções.
* <strong>Obs2.:</strong> sempre ao final da execução da fila é necessário chamar a DestroiFila para que não ocorra vazamento de memória.

### Sobre a implementação da estrutura lista
* <strong>Struct lista</strong> - deve ser criada no arquivo main.c pelo usuário;
* <strong>void CriaLista(lista *l, int(*igual)(T,T))</strong> - função que inicializa a lista criada pelo usuário;
* <strong>int ListaVazia(lista *l)</strong> - função que verifica se a lista está vazia, ou seja, não possui nenhum elemento;
* <strong>int TamanhoLista(lista *l)</strong> - função que retorna a quantidade de elementos da lista;
* <strong>void InserirFim(lista *l, T p)</strong> - função que insere um elemento, que é passado pelo parâmetro p, no final da lista;
* <strong>void RemoverInicio(lista *l)</strong> - função que remove o elemento do início da lista, para essa função é necessária a verificação ListaVazia, pois se a lista estiver sem nenhum elemento, não pode ocorrer uma remoção;
* <strong>iterador PrimeiroLista(lista *l)</strong> - função que retorna o iterador que contém o primeiro elemento da lista;
* <strong>iterador ProximoLista(iterador i)</strong> - função que retorna o iterador, que contém o próximo elemento, com base no iterador passado como parâmetro;
* <strong>iterador BuscaLista(iterador i, T p)</strong> - função que realiza uma busca de um elemento na lista com o auxílio das funções ValidoLista e ProximoLista, sendo que, se o elemento buscado, que é passado como parâmetro, pertencer a lista, ela retornará o iterador com esse elemento, se não, retornará um iterador inválido;
* <strong>iterador RetiraLista(iterador i)</strong> - função que remove um elemento da lista na posição que é o índice do iterador, sendo esse passado como parâmetro;
* <strong>int ValidoLista(iterador i)</strong> - função que verifica se o iterador está em um elemento da lista, retornando verdadeiro se o elemento do iterador não for o sentinela;
* <strong>T ElementoLista(iterador i)</strong> - função que retorna os dados do elemento indicado pelo iterador que é passado como parâmetro, sendo do tipo T, pois retorna os dados de uma struct que foi definida como T;
* <strong>void DestroiLista(lista *l)</strong> - função que destrói a lista, utilizando a função RemoverInicio para remover cada elemento e a verificação ListaVazia para remover até que a fila esteja sem elementos.
* <strong>Obs1.:</strong> a fim de que as funções funcionem corretamente nessa estrutura é necessário que a CriaLista tenha sido chamada uma única vez antes da chamada das demais funções.
* <strong>Obs2.:</strong> sempre ao final da execução da lista é necessário chamar a DestroiLista para que não ocorra vazamento de memória.

### Sobre os arquivos interface.h e interface.c
* Essa biblioteca é a responsável pela estilização do sistema dentro do terminal, sendo que ela contém a mensagem sobre a abertura do sistema, a mensagem sobre o fechamento do sistema, as opções de execução permitidas pelo sistema por meio do código e sua respectiva operação, uma função que pega o horário oficial de Brasília e duas funções que fazem tracejados meramente estilísticos.

### Sobre o arquivo pedido.h
* Dentro desse arquivo foi armazenado a struct que contém os dados (número de identificação, informações sobre o pedido e o valor) que serão utilizadas em cada pedido.

### Sobre o main.c
* Criou-se uma posssível aplicação desenvolvida pelo usuário, em que se simula a utilização no restaurante.

🚀 | Aplicação desenvolvida por Pedro Gonçalves Correia e Pedro Enrico Barchi Nogueira