//Grupo: Pedro Enrico Barchi Nogueira e Pedro Gonçalves Correia
#ifndef FILA_H
#define FILA_H
#include"pedido.h"

//Definição de um valor base para o tamanho inicial do vetor
#define INICIAL 10

typedef pedido T;

//Definindo a estrutura da lista
struct Fila{
    T *dados;
    unsigned quantidade;
    int fim, inicio, max;
};
typedef struct Fila* fila;

//Função que inicializa a fila e retorna o endereço em que ela foi alocada
fila CriaFila();
//Função que verifica se a fila está vazia
int FilaVazia(fila f);
//Função que verifica se a fila está cheia
int FilaCheia(fila f);
//Função que retorna a quantidade de elementos da fila
unsigned TamanhoFila(fila f);
//Função que insere um elemento no final da fila
void InsercaoFila(fila f, T p);
//Função que remove um elemento do início da fila
void RemocaoFila(fila f);
//Função que retorna o índice do vetor onde está o primeiro elemento
int Inicio(fila f);
//Função que retorna o índice do vetor onde está o último elemento
int Final(fila f);
//Função que retorna as informações de um elemento na posição i da fila
T Elemento(fila f, int i);
//Função que retorna as informações do primeiro elemento da fila
T PrimeiroElemento(fila f);
//Função que destrói a fila
void DestroiFila(fila f);

#endif