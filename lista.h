//Grupo: Pedro Enrico Barchi Nogueira e Pedro Gonçalves Correia
#ifndef LISTA_H
#define LISTA_H
#include"pedido.h"

typedef pedido T;

// Definindo a estrutura de um nó da lista
typedef struct node {
    T dados;
    struct node *prox, *ant;
} Node;

// Definindo a estrutura da lista
typedef struct {
    Node *sentinela;
    unsigned quantidade;
    int (*igual)(T,T);
} lista;

//Definindo a estrutura do iterador
typedef struct {
    Node *elemento;
    lista *lista;
} iterador;

//Função que inicializa a lista
//Passagem do ponteiro de função igual como parâmetro para que seja possível realizar a comparação de igualdade na API sem que haja a quebra de encapsulamento
void CriaLista(lista *l, int(*igual)(T,T));
//Função que verifica se a a lista está vazia
int ListaVazia(lista *l);
//Função para retornar o tamanho da lista, ou seja, o campo quantidade
int TamanhoLista(lista *l);
//Função que insere elemento p no fim da lista
void InserirFim(lista *l, T p);
//Função que remove elemento do início da lista
void RemoverInicio(lista *l);
//Função que retorna o iterador que contém o primeiro elemento da lista
iterador PrimeiroLista(lista *l);
//Função que vai para o próximo elemento a partir de um iterador prévio
//Uso do iterador para que ele retorne o elemento seguinte da lista
iterador ProximoLista(iterador i);
//Função que realiza uma busca na lista
//Retorna o iterador com o elemento que foi buscado com base na variável p, se não encontrar retornará um iterador inválido
iterador BuscaLista(iterador i, T p);
//Função que retira o elemento no indice do iterador
//Função remove da lista o elemento com base no iterador passado como parâmetro
iterador RetiraLista(iterador i);
//Função que verifica se o iterador está em um elemento da lista
//Verifica se o iterador contêm algo
int ValidoLista(iterador i);
//Função que retorna os dados com base no iterador
//Retorna os dados do elemento do iterador
T ElementoLista(iterador i);
//Função que destrói a lista
void DestroiLista(lista *l);

#endif